//
// Created by Anne Messner on 06.04.2022.
//
#include <iostream>
#include <vector>
#include<algorithm>
#include "Post.h"

// Constructor de Initiere
Post::Post() {
    no_likes = 0;
    no_comments = 0;
}

// Constructor Copiere
Post::Post(const Post &other) : no_likes{other.no_likes}, no_comments{other.no_comments}, hashtags{other.hashtags},
                                theme{other.theme} {}

// Operator ==(de egalitate)
bool Post::operator==(const Post &postare) const {
    return (no_likes == postare.no_likes) &&
           (no_comments == postare.no_comments) &&
           (hashtags == postare.hashtags) &&
           (theme == postare.theme);
}

bool Post::operator<(const Post &other) const {
    if (no_likes == other.no_likes) {
        return no_comments < other.no_comments;
    } else {
        return no_likes < other.no_likes;
    }
}

// Operator =
Post &Post::operator=(const Post &other) {
    no_likes = other.no_likes;
    no_comments = other.no_comments;
    theme = other.theme;
    std::copy(other.hashtags.begin(), other.hashtags.end(), hashtags.begin());
    return *this;
}

// Operator << // avea friend
std::ostream &operator<<(std::ostream &os, const Post &post) {
    os << "\fNo. of Likes: " << post.no_likes << ", No of Comments: " << post.no_comments
       << ", Theme: " << post.theme;
    os << "\n\fHashtags: ";
    for (const std::string &hashtag : post.hashtags) {
        os << hashtag << " ";
    }
    return os;
}


// Destructor
Post::~Post() = default;

//setter
void Post::increment_no_likes() {
    ++this->no_likes;
}

//
void Post::decrement_no_likes() {
    --this->no_likes;
}

//getter
int Post::get_likes() const {
    return this->no_likes;
}

std::string Post::get_theme() {
    return this->theme;
}

int Post::getNoComments() const {
    return no_comments;
}

void Post::setNoComments(int noComments) {
    no_comments = noComments;
}

int Post::scor_relevanta() {
    return (this->no_likes * 3 + this->no_comments * 7) / 10;
}




