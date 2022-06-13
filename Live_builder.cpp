//
// Created by Anne Messner on 08.06.2022.
//
#include "Live_builder.h"


Live_builder::Live_builder() = default;

Live_builder::~Live_builder() {}

Live_builder &Live_builder::likes(int no_likes) {
    post.no_likes = no_likes;
    return *this;
}

Live_builder &Live_builder::hashtags(const std::vector<std::string> &hashtags) {
    post.hashtags = hashtags;
    return *this;
}

Live_builder &Live_builder::comments(int no_comments) {
    post.no_comments = no_comments;
    return *this;
}

Live_builder &Live_builder::theme(const std::string &theme) {
    post.theme = theme;
    return *this;
}

Live_builder &Live_builder::people_watching(int people_watching) {
    post.people_watching = people_watching;
    return *this;
}

Live_builder &Live_builder::starting_time(int starting_time) {
    post.starting_time = starting_time;
    return *this;
}

Live_builder &Live_builder::ending_time(int ending_time) {
    post.ending_time = ending_time;
    return *this;
}

Live Live_builder::build() {
    return post;
}


