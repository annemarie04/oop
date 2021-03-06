//
// Created by Anne Messner on 08.06.2022.
//

#include "Checkin_builder.h"

Checkin_builder::Checkin_builder() {}


Checkin_builder &Checkin_builder::likes(int no_likes) {
    post.no_likes = no_likes;
    return *this;
}

Checkin_builder &Checkin_builder::hashtags(const std::vector<std::string> &hashtags) {
    post.hashtags = hashtags;
    return *this;
}

Checkin_builder &Checkin_builder::comments(int no_comments) {
    post.no_comments = no_comments;
    return *this;
}

Checkin_builder &Checkin_builder::theme(const std::string &theme) {
    post.theme = theme;
    return *this;
}

Checkin_builder &Checkin_builder::adress(const std::string &adress) {
    post.adress = adress;
    return *this;
}

Checkin_builder &Checkin_builder::city(const std::string &city) {
    post.city = city;
    return *this;
}

Checkin_builder &Checkin_builder::country(const std::string &country) {
    post.country = country;
    return *this;
}

Check_in Checkin_builder::build() {
    return post;
}

Checkin_builder::~Checkin_builder() {}

