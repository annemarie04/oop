//
// Created by Anne Messner on 01.05.2022.
//

#ifndef OOP_CHECK_IN_H
#define OOP_CHECK_IN_H

#include "Post.h"
#include <memory>
#include <ostream>


class Check_in : public Post {

    std::string adress;
    std::string city;
    std::string country;

public:
    Check_in(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
             const std::string &adress, const std::string &city, const std::string &country);


    void show_post() override;

    [[nodiscard]] std::shared_ptr<Post> clone() const override {
        return std::make_shared<Check_in>(*this);
    }


    friend std::ostream &operator<<(std::ostream &os, const Check_in &in);

    int scor_relevanta() override;

    ~Check_in() override;

};

#endif //OOP_CHECK_IN_H
