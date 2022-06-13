//
// Created by Anne Messner on 06.04.2022.
//

#ifndef OOP_POST_H
#define OOP_POST_H

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include <memory>

class Post {
    int no_likes;
    int no_comments;
    std::vector<std::string> hashtags;
    std::string theme;

    friend class Photo_builder;

    friend class Live_builder;

    friend class Checkin_builder;

public:
    // Constructor de Initiere
    Post();

    // Operator ==(de verificare)
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

    //getter
    [[nodiscard]] int get_likes() const;


    std::string get_theme();

    // functii virtuale pure
    virtual void show_post() = 0;

    virtual std::shared_ptr<Post> clone() const = 0;

    virtual int scor_relevanta();

    int getNoComments() const;

    void setNoComments(int noComments);

    class Builder {
        Builder() {}

        Builder &no_likes(int no_likes);
    };

};
#endif //OOP_POST_H
