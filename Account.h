//
// Created by Anne Messner on 06.04.2022.
//

#ifndef OOP_ACCOUNT_H
#define OOP_ACCOUNT_H

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include "Post.h"

class Account {
    std::string username;
    int followers;
    int following;
    std::string target_audience;
    std::vector<Post> posts;
    std::map<Post *, bool> likes;

public:
    // Constructor de Initiere
    Account(const std::string &username, int followers, int following, const std::string &targetAudience,
            std::vector<Post> &posts);

    // Operator == (de egalitate)
    bool operator==(const Account &cont) const;

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    // Destructor
    ~Account();

    //setters
    void do_like(Post *post_u);

    void do_unlike(Post *post_u);

    void new_follower();

    void new_following();

    void add_post(Post postare);

    void change_audience(std::string const &new_target);

    //getters
    std::string get_username();

    int get_followers();

    int get_following();

    void get_posts();

    std::string get_audience();

    Post get_top_post();

    // find
    Post find_post_by_theme(const std::string &searched_theme);
};


#endif //OOP_ACCOUNT_H
