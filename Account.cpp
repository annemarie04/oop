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
        Post *obj = Account::dcast(post);
        std::cout << "Post ID: " << index << "\n";
        obj->show_post();
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


Account &Account::operator=(const Account &other) {
    username = other.username;
    followers = other.followers;
    following = other.following;
    target_audience = other.target_audience;
    pinned_post = other.pinned_post;
    likes = other.likes;
    std::copy(other.posts.begin(), other.posts.end(), posts.begin());
    std::copy(other.shares.begin(), other.shares.end(), shares.begin());
    return *this;
}

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
Account::add_photo(const std::vector<std::string> &hashtags, const std::string &theme, int brightness, int contrast,
                   int saturation,
                   const std::string &filter, const std::string &file_path) {
    Photo *photo = new Photo(0, 0, hashtags, theme, brightness, contrast, saturation, filter, file_path);
    this->posts.push_back(photo);
}

void
Account::add_check_in(const std::vector<std::string> &hashtags, const std::string &theme, const std::string &adress,
                      const std::string &city, const std::string &country) {
    Check_in *check_in = new Check_in(0, 0, hashtags, theme, adress, city, country);
    this->posts.push_back(check_in);
}

void Account::add_live(const std::vector<std::string> &hashtags, const std::string &theme, int people_watching,
                       int starting_time, int ending_time) {
    Live *live = new Live(0, 0, hashtags, theme, people_watching, starting_time, ending_time);
    this->posts.push_back(live);
}


class my_exceptie : public std::runtime_error {
public:
    explicit my_exceptie(const std::string &arg) : runtime_error(arg) {}
};

class eroare_server : public my_exceptie {
public:
    explicit eroare_server(const std::string &arg) : my_exceptie(arg) {}
};

class eroare_client : public my_exceptie {
public:
    explicit eroare_client(const std::string &arg) : my_exceptie(arg) {}
};


void Account::get_post(unsigned int id) {
    try {
        if (id >= this->posts.size())
            throw eroare_client("ID-ul nu exista");
        Post *obj = dcast(this->posts[id]);
        std::cout << "Post ID: " << id << "\n";
        obj->show_post();
    } catch (my_exceptie &err) {
        std::cout << "Error: " << err.what();
    }

}

void Account::get_posts() {
    int index = 0;
    if (pinned_post != nullptr) {

    }
    if (pinned_post != nullptr) {
        this->show_pin();
        std::cout << '\n';
    }
    for (auto &post : this->posts) {
        std::cout << "Post ID: " << index << "\n";
        Post *obj = dcast(post);
        obj->show_post();
        std::cout << "\n";
        index++;
    }
}

//setters in functie de id
void Account::do_like(unsigned int id) {
    try {
        if (id >= this->posts.size())
            throw eroare_client("ID-ul nu exista");

        Post *post_u = this->posts[id];
        if (likes.count(post_u)) {
            return;
        }
        this->likes.insert(std::pair<Post *, bool>(post_u, true));
        post_u->increment_no_likes();
    } catch (my_exceptie &err) {
        std::cout << "Error: " << err.what();
    }


}

void Account::do_unlike(unsigned int id) {
    try {
        if (id >= this->posts.size())
            throw eroare_client("ID-ul nu exista");
        Post *post_u = this->posts[id];
        if (!likes.count(post_u)) {
            return;
        }
        auto it = likes.find(post_u);
        likes.erase(it);
        post_u->decrement_no_likes();
    } catch (my_exceptie &err) {
        std::cout << "Error: " << err.what();
    }
}

void Account::show_my_likes() {
    auto it = this->likes.begin();
    for (; it != this->likes.end(); it++) {
        Post *obj = dcast(it->first);
        obj->show_post();
        std::cout << "\n";
    }
}

void Account::get_top_post() {
    if (this->posts.empty()) {
        std::cout << "\nNu sunt postari\n";
        return;
    }
    std::vector<Post *> copy_posts;
    copy_posts = this->posts;

    sort(copy_posts.begin(), copy_posts.end(), [](const Post *lhs, const Post *rhs) {
        return lhs->get_likes() > rhs->get_likes();
    });
    Post *obj = dcast(copy_posts[0]);
    obj->show_post();
}


void Account::find_post_by_theme(const std::string &searched_theme) {

    int index = 0;
    for (auto &post : this->posts) {
        if (post->get_theme() == searched_theme) {
            Post *obj = dcast(post);
            std::cout << "Post ID: " << index << "\n";
            obj->show_post();
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
    try {
        if (id >= cont2->posts.size())
            throw eroare_client("ID-ul nu exista");
        std::shared_ptr<Post> shared_post = cont2->posts[id]->clone();
        this->shares.push_back(shared_post);
    } catch (my_exceptie &err) {
        std::cout << "Error: " << err.what();
    }
}

void Account::show_shared() {
    for (auto &share : shares) {
        Post &pointer = *share;
        Post *obj = dcast(&pointer);
        obj->show_post();
    }
}

void Account::pin_post(unsigned int id) {
    try {
        if (id >= this->posts.size())
            throw eroare_client("ID-ul nu exista");
        this->pinned_post = this->posts[id];
        this->posts.erase(this->posts.begin() + id);
    } catch (my_exceptie &err) {
        std::cout << "Error: " << err.what();
    }
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
    Post *obj = dcast(this->pinned_post);
    obj->show_post();
}
