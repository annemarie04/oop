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
#include "Check_in.h"

class Account {
    std::string username;
    int followers;
    int following;
    std::string target_audience;
    std::vector<Post *> posts;
    std::map<Post *, bool> likes;
    std::vector<std::shared_ptr<Post>> shares;
    Post *pinned_post = nullptr;


public:
    // Constructor de Initiere
    Account(const std::string &username, int followers, int following, const std::string &targetAudience);

    // Operator == (de egalitate)
    bool operator==(const Account &cont) const;

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    static void swap(Account &a1, Account &a2);

    Account &operator=(const Account &other);

    // Destructor
    virtual ~Account();

    //setters
    void do_like(unsigned int id);

    void do_unlike(unsigned int id);

    void new_follower();

    void new_following();

//    void add_post(Post postare);
    void add_photo(const std::vector<std::string> &hashtags, const std::string &theme,
                   int brightness, int contrast, int saturation, const std::string &filter,
                   const std::string &file_path);

    void add_check_in(const std::vector<std::string> &hashtags, const std::string &theme,
                      const std::string &adress, const std::string &city, const std::string &country);

    void add_live(const std::vector<std::string> &hashtags, const std::string &theme,
                  int people_watching, int starting_time, int ending_time);

    void change_audience(std::string const &new_target);

    //getters
    std::string get_username();

    int get_followers();

    int get_following();

    void get_post(unsigned int id);

    void get_posts();

    std::string get_audience();

    void show_my_likes();

    void get_top_post();

    // find
    void find_post_by_theme(const std::string &searched_theme);

    static Post *dcast(Post *postare);

    void share(unsigned int id, Account *cont2);

    void show_shared();

    void pin_post(unsigned int id);

    void delete_pin();

    void show_pin();
};


#endif //OOP_ACCOUNT_H

