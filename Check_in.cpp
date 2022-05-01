//
// Created by Anne Messner on 01.05.2022.
//

#include "Check_in.h"

Check_in::Check_in(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
                   const std::string adress, const std::string city, const std::string country) : Post(noLikes,
                                                                                                       noComments,
                                                                                                       hashtags, theme),
                                                                                                  adress(adress),
                                                                                                  city(city),
                                                                                                  country(country) {}

void Check_in::show_post() {
    {
        Post *post = this;
        std::cout << *post << "\n\tAdress: " << this->adress << "\n\tCity: " << this->city
                  << "\n\tCountry: " << this->country << "\n";
    }
}

Check_in::~Check_in() {}
