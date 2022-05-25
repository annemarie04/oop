//
// Created by Anne Messner on 06.04.2022.
//

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include "Account.h"
#include "Post.h"
#include "Photo.h"
#include "Check_in.h"
#include "Live.h"
#include "my_exceptie.h"


// Constructor de Initiere
Account::Account(const std::string &username, int followers, int following, const std::string &targetAudience)
        : username(username), followers(followers), following(following),
          target_audience(targetAudience) {}


// Operator == (de egalitate)
bool Account::operator==(const Account &cont) const {
    return username == cont.username &&
           followers == cont.followers &&
           following == cont.following &&
           target_audience == cont.target_audience &&
           posts == cont.posts &&
           likes == cont.likes;
}

// Operator << // avea friend
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "Username: " << account.username << ", Followers: " << account.followers << ", Following: "
       << account.following << ", No of Posts: " << account.posts.size() << ", Target Audience: "
       << account.target_audience
       << "\n Posts:\n ";
    int index = 0;
    for (auto &post : account.posts) {
        std::cout << "Post ID: " << index << "\n";
        post->show_post();
        index++;
    }
    return os;
}

void Account::swap(Account &a1, Account &a2) {
    using std::swap;
    swap(a1.username, a2.username);
    swap(a1.followers, a2.followers);
    swap(a1.following, a2.following);
    swap(a1.target_audience, a2.target_audience);
    swap(a1.posts, a2.posts);
    swap(a1.likes, a2.likes);
    swap(a1.shares, a2.shares);
    swap(a1.pinned_post, a2.pinned_post);
}


//Account &Account::operator=(Account &other) {
////    Account::swap(*this, other);
////    username = other.username;
////    followers = other.followers;
////    following = other.following;
////    target_audience = other.target_audience;
////    pinned_post = other.pinned_post;
////    likes = other.likes;
////    std::copy(other.posts.begin(), other.posts.end(), posts.begin());
////    std::copy(other.shares.begin(), other.shares.end(), shares.begin());
//    return *this;
//}

// Destructor
Account::~Account() {}

void Account::new_follower() {
    ++this->followers;
}

void Account::new_following() {
    ++this->following;
}

void Account::change_audience(std::string const &new_target) {
    this->target_audience = new_target;
}

const std::vector<std::shared_ptr<Post>> &Account::getPosts() const {
    return posts;
}

void Account::setPosts(const std::vector<std::shared_ptr<Post>> &p) {
    Account::posts = p;
}

//getters
std::string Account::get_username() {
    return this->username;
}

int Account::get_followers() {
    return this->followers;
}

int Account::get_following() {
    return this->following;
}

std::string Account::get_audience() {
    return this->target_audience;
}

// ----------------------------------------- post



void
Account::add_photo(Photo &photo) {
    std::shared_ptr<Post> photo_sp = std::make_shared<Photo>(photo);
    this->posts.push_back(photo_sp);
    std::cout << "Type: " << typeid(photo_sp.get()).name() << "\n";

}

void
Account::add_check_in(Check_in &check_in) {
    std::shared_ptr<Post> check_in_sp = std::make_shared<Check_in>(check_in);
    this->posts.push_back(check_in_sp);
}

void Account::add_live(Live &live) {
    std::shared_ptr<Post> live_sp = std::make_shared<Live>(live);
    this->posts.push_back(live_sp);
}


void Account::get_post(unsigned int id) {
    if (id >= this->posts.size())
        throw eroare_client("ID-ul nu exista");
    std::cout << "Post ID: " << id << "\n";
    this->posts[id]->show_post();
}

void Account::get_posts() {
    int index = 0;

    if (pinned_post != nullptr) {
        this->show_pin();
        std::cout << '\n';
    }
    for (auto &post : this->posts) {
        std::cout << "Post ID: " << index << "\n";
        post->show_post();
        std::cout << "\n";
        index++;
    }
}

//setters in functie de id
void Account::do_like(unsigned int id) {
    if (id >= this->posts.size())
        throw eroare_client("ID-ul nu exista");

    if (this->likes.count(this->posts[id])) {
        throw eroare_client("Ai dat deja like");
    }
    this->likes.insert(std::pair<std::shared_ptr<Post>, bool>(this->posts[id], true));
    this->posts[id]->increment_no_likes();


}

void Account::do_unlike(unsigned int id) {
    if (id >= this->posts.size())
        throw eroare_client("ID-ul nu exista");
    if (!this->likes.count(this->posts[id])) {
        throw eroare_client("Nu ai dat inca like");
        return;
    }
    auto it = likes.find(this->posts[id]);
    likes.erase(it);
    this->posts[id]->decrement_no_likes();
}

void Account::show_my_likes() {
    for (auto it = this->likes.begin(); it != this->likes.end(); it++) {
        it->first->show_post();
        std::cout << "\n";
    }
}

//get_top_post
void Account::sort_posts_by_likes() {
    if (this->posts.empty()) {
        throw eroare_client("Nu exista postari");
    }

    sort(this->posts.begin(), this->posts.end(), [](std::shared_ptr<Post> lhs, std::shared_ptr<Post> rhs) {
        return lhs->get_likes() > rhs->get_likes();
    });

}


void Account::find_post_by_theme(const std::string &searched_theme) {

    int index = 0;
    for (auto &post : this->posts) {
        if (post->get_theme() == searched_theme) {
            std::cout << "Post ID: " << index << "\n";
            post->show_post();
            std::cout << "\n";
        }
        index++;
    }
}

Post *Account::dcast(Post *postare) {
    Post *obj = nullptr;
    if (postare == nullptr) {
        return nullptr;
    }
    if (dynamic_cast<Photo *>(postare)) {
        obj = dynamic_cast<Photo *>(postare);
    }
    if (dynamic_cast<Check_in *>(postare)) {
        obj = dynamic_cast<Check_in *>(postare);
    }
    if (dynamic_cast<Live *>(postare)) {
        obj = dynamic_cast<Live *>(postare);
    }
    if (obj == nullptr)
        throw eroare_server("Nu a putut fi facut dynamic_cast.");
    return obj;
}

void Account::share(unsigned int id, Account *cont2) {
    if (id >= cont2->posts.size())
        throw eroare_client("ID-ul nu exista");
    std::shared_ptr<Post> shared_post = cont2->posts[id]->clone();
    this->shares.push_back(shared_post);

}

void Account::show_shared() {
    for (auto &share : shares) {
        share->show_post();
    }
}

void Account::pin_post(unsigned int id) {

    if (id >= this->posts.size())
        throw eroare_client("ID-ul nu exista");
    this->pinned_post = this->posts[id];
    this->posts.erase(this->posts.begin() + id);
}

void Account::delete_pin() {
    if (pinned_post == nullptr) {
        return;
    }
    this->posts.push_back(pinned_post);
    pinned_post = nullptr;

}

void Account::show_pin() {
    if (pinned_post == nullptr) {
        std::cout << "\nNo pin available.";
        return;
    }
    std::cout << "\nPinned post: \n";
    pinned_post->show_post();
}
