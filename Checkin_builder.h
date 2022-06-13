//
// Created by Anne Messner on 08.06.2022.
//

#ifndef OOP_CHECKIN_BUILDER_H
#define OOP_CHECKIN_BUILDER_H


#include "Check_in.h"

class Checkin_builder {
private:
    Check_in post;
public:
    Checkin_builder();

    Checkin_builder &likes(int no_likes);

    Checkin_builder &hashtags(const std::vector<std::string> &hashtags);

    Checkin_builder &comments(int no_comments);

    Checkin_builder &theme(const std::string &theme);

    Checkin_builder &adress(const std::string &adress);

    Checkin_builder &city(const std::string &city);

    Checkin_builder &country(const std::string &country);

    Check_in build();

    ~Checkin_builder();

};


#endif //OOP_CHECKIN_BUILDER_H
