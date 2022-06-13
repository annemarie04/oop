//
// Created by Anne Messner on 01.05.2022.
//
#include "Post.h"
#include "Live.h"

Live::Live() : people_watching(0), starting_time(0), ending_time(0) {}

std::ostream &operator<<(std::ostream &os, const Live &live) {
    os << static_cast<const Post &>(live) << " people_watching: " << live.people_watching << " starting_time: "
       << live.starting_time << " ending_time: " << live.ending_time;
    return os;
}

void Live::show_post() {
    std::cout << *this;
}

int Live::scor_relevanta() {
    int scor = (this->get_likes() * 3 + this->getNoComments() * 7) / 10;
    scor += this->people_watching * 2;
    int time = this->ending_time - this->starting_time;
    scor += time;
    return scor;

}

std::shared_ptr<Post> Live::clone() const {
    return std::make_shared<Live>(*this);
}


Live::~Live() = default;
