//
// Created by Anne Messner on 08.06.2022.
//

#ifndef OOP_LIVE_BUILDER_H
#define OOP_LIVE_BUILDER_H


#include "Live.h"

class Live_builder {
private:
    Live post;
public:
    Live_builder();

    Live_builder &likes(int no_likes);

    Live_builder &hashtags(const std::vector<std::string> &hashtags);

    Live_builder &comments(int no_comments);

    Live_builder &theme(const std::string &theme);

    Live_builder &people_watching(int people_watching);

    Live_builder &starting_time(int starting_time);

    Live_builder &ending_time(int ending_time);

    Live build();

    ~Live_builder();
};


#endif //OOP_LIVE_BUILDER_H
