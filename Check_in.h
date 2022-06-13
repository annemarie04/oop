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

    friend class Checkin_builder;

public:
    Check_in();


    void show_post() override;

    [[nodiscard]] std::shared_ptr<Post> clone() const override;


    friend std::ostream &operator<<(std::ostream &os, const Check_in &in);

    int scor_relevanta() override;

    ~Check_in() override;

};

#endif //OOP_CHECK_IN_H
