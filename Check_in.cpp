//
// Created by Anne Messner on 01.05.2022.
//

#include "Check_in.h"

Check_in::Check_in() = default;

std::ostream &operator<<(std::ostream &os, const Check_in &in) {
    os << static_cast<const Post &>(in) << " adress: " << in.adress << " city: " << in.city << " country: "
       << in.country;
    return os;
}

void Check_in::show_post() {
    std::cout << *this;
}

int Check_in::scor_relevanta() {
    int scor = (this->get_likes() * 3 + this->getNoComments() * 7) / 10;
    if (this->city == "Bucuresti") {
        scor *= 2;
    }
    if (this->country == "Romania") {
        scor += 100;
    }
    return scor;
}

std::shared_ptr<Post> Check_in::clone() const {
    return std::make_shared<Check_in>(*this);
}

Check_in::~Check_in() = default;
