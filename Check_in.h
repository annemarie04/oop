//
// Created by Anne Messner on 01.05.2022.
//

#ifndef OOP_CHECK_IN_H
#define OOP_CHECK_IN_H

#include "Post.h"
#include <memory>


class Check_in : public Post {
    std::string adress;
    std::string city;
    std::string country;

public:
    Check_in(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
             std::string adress, std::string city, std::string country);

    void show_post() override;

    [[nodiscard]] std::shared_ptr<Post> clone() const override {
        return std::make_shared<Check_in>(*this);
    }
};

#endif //OOP_CHECK_IN_H
