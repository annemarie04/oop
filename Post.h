//
// Created by Anne Messner on 06.04.2022.
//

#ifndef OOP_POST_H
#define OOP_POST_H

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>

class Post {
    int no_likes;
    int no_comments;
    std::vector<std::string> hashtags;
    std::string theme;
public:
    // Constructor de Initiere
    Post(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme);

    // Operator ==(de egalitate)
    bool operator==(const Post &postare) const;

    // Operator <
    bool operator<(const Post &other) const;

    // Operator =
    Post &operator=(const Post &other);

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Post &post);

    // Constructor Copiere
    Post(const Post &other);

    // Destructor
    virtual ~Post();

    //setter
    void increment_no_likes();

    void decrement_no_likes();

    void add_hashtag(std::string hashtag);

    void change_theme(std::string const &new_theme);

    //getter
    int get_likes();

    std::vector<std::string> get_hashtags();

    std::string get_theme();
};


#endif //OOP_POST_H
