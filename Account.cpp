//
// Created by Anne Messner on 06.04.2022.
//

#include "Account.h"
#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include "Post.h"


// Constructor de Initiere
Account::Account(const std::string &username, int followers, int following, const std::string &targetAudience,
                 std::vector<Post> &posts) : username(username), followers(followers), following(following),
                                             target_audience(targetAudience), posts(posts) {}

//    // Operator =
//    Account &operator=(const Account &other) {
//        username = other.username;
//        followers = other.followers;
//        following = other.following;
//        target_audience = other.target_audience;
//
//        std::copy(other.posts.begin(), other.posts.end(), posts.begin());
//        return *this;
//    }

// Operator == (de egalitate)
bool Account::operator==(const Account &cont) const {
    return username == cont.username &&
           followers == cont.followers &&
           following == cont.following &&
           target_audience == cont.target_audience &&
           posts == cont.posts;
}

// Operator << // avea friend
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "username: " << account.username << ", followers: " << account.followers << ", following: "
       << account.following << ", no_posts: " << account.posts.size() << ", target_audience: "
       << account.target_audience
       << "\n posts:\n ";
    int i = 1;
    for (const auto &postare: account.posts) {

        std::cout << "postare " << i << " : " << postare << '\n';
        i++;
    }
    return os;
}

// Destructor
Account::~Account() {}

//setters
void Account::do_like(Post *post_u) {
    if (likes.count(post_u)) {
        return;
    }
    this->likes.insert(std::pair<Post *, bool>(post_u, true));
    post_u->increment_no_likes();
}

void Account::do_unlike(Post *post_u) {
    if (!likes.count(post_u)) {
        return;
    }
    auto it = likes.find(post_u);
    likes.erase(it);
    post_u->decrement_no_likes();
}

//    void parcurgere_likes() {
//        std::map<Post *, bool>::iterator it = likes.begin();
//        for (; it != likes.end(); it++) {
//            std::cout << *it->first << " :: " << it->second << std::endl;
//        }
//    }

void Account::new_follower() {
    ++this->followers;
}

void Account::new_following() {
    ++this->following;
}

void Account::add_post(Post postare) {
    this->posts.push_back(postare);
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

void Account::get_posts() {
    for (Post post : this->posts) {
        std::cout << post << " ";
    }
}

Post Account::get_top_post() {
    std::vector<Post> copy_posts;
    copy_posts = this->posts;

    sort(copy_posts.begin(), copy_posts.end(), [](Post lhs, Post rhs) {
        return lhs.get_likes() > rhs.get_likes();
    });
    return copy_posts[0];
}

std::string Account::get_audience() {
    return this->target_audience;
}

// find

Post Account::find_post_by_theme(const std::string &searched_theme) {
    auto it = std::find_if(this->posts.begin(), this->posts.end(), [searched_theme](Post post) {
        return post.get_theme() == searched_theme;
    });
    return *it;
}