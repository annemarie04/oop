//
// Created by Anne Messner on 08.06.2022.
//
#include "Photo_builder.h"

Photo_builder::Photo_builder() {}

Photo_builder::~Photo_builder() {}

Photo_builder &Photo_builder::likes(int no_likes) {
    post.no_likes = no_likes;
    return *this;
}

Photo_builder &Photo_builder::hashtags(const std::vector<std::string> &hashtags) {
    post.hashtags = hashtags;
    return *this;
}

Photo_builder &Photo_builder::comments(int no_comments) {
    post.no_comments = no_comments;
    return *this;
}

Photo_builder &Photo_builder::theme(const std::string &theme) {
    post.theme = theme;
    return *this;
}

Photo_builder &Photo_builder::brightness(int brightness) {
    post.brightness = brightness;
    return *this;
}

Photo_builder &Photo_builder::contrast(int contrast) {
    post.contrast = contrast;
    return *this;
}

Photo_builder &Photo_builder::saturation(int saturation) {
    post.saturation = saturation;
    return *this;
}

Photo_builder &Photo_builder::filter(const std::string &filter) {
    post.filter = filter;
    return *this;
}

Photo_builder &Photo_builder::file_path(const std::string &file_path) {
    post.file_path = file_path;
    return *this;
}

Photo Photo_builder::build() {
    return post;
}

