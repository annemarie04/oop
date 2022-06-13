//
// Created by Anne Messner on 06.04.2022.
//

#ifndef OOP_ACCOUNT_H
#define OOP_ACCOUNT_H

#include <iostream>
#include <vector>
#include<map>
#include <memory>
#include<algorithm>
#include "Post.h"
#include "Check_in.h"
#include "Photo.h"
#include "Live.h"


class Account {
    std::string username;
    int followers;
    int following;
    std::string target_audience;
    std::vector<std::shared_ptr<Post>> posts;
    std::map<std::shared_ptr<Post>, bool> likes;
    std::vector<std::shared_ptr<Post>> shares;
    std::shared_ptr<Post> pinned_post = nullptr;

public:
    // Constructor de Initiere
    Account(const std::string &username, int followers, int following, const std::string &targetAudience);

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    static void swap(Account &a1, Account &a2);

    Account(const Account &other);

    Account &operator=(Account &other);

//    virtual Account* clone() = 0;
    //setters
    void do_like(unsigned int id);

    void do_unlike(unsigned int id);

    void new_follower();

    void new_following();

//    void add_post(Post postare);
    void add_photo(Photo &photo);

    void add_check_in(Check_in &check_in);

    void add_live(Live &live);

    void change_audience(std::string const &new_target);

    //getters
    std::string get_username();

    int get_followers() const;

    int get_following() const;

    void show_post(unsigned int id);

    void show_posts();

    std::string get_audience();

    void show_my_likes();

    void sort_posts_by_likes();

    // find
    std::shared_ptr<Post> find_post_by_theme(const std::string &searched_theme);

    void share(unsigned int id, const std::shared_ptr<Account> &cont2);

    void show_shared();

    void pin_post(unsigned int id);

    void delete_pin();

    void show_pin();

    [[nodiscard]] const std::vector<std::shared_ptr<Post>> &getPosts() const;


    // Destructor
    ~Account();
};


#endif //OOP_ACCOUNT_H

