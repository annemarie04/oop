//
// Created by Anne Messner on 01.05.2022.
//

#include "Live.h"

Live::Live(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
           int people_watching, int starting_time, int ending_time) : Post(noLikes, noComments, hashtags, theme),
                                                                      people_watching(people_watching),
                                                                      starting_time(starting_time),
                                                                      ending_time(ending_time) {}

void Live::show_post() {
    Post *post = this;
    std::cout << *post << "\n\tPeople watching: " << this->people_watching << "\n\tStarting time: "
              << this->starting_time
              << "\n\tEnding time: " << this->ending_time << "\n";

}