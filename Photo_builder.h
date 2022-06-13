//
// Created by Anne Messner on 08.06.2022
//

#ifndef OOP_PHOTO_BUILDER_H
#define OOP_PHOTO_BUILDER_H

#include <vector>
#include <string>
#include "Photo.h"

class Photo_builder {
    Photo post;
public:
    Photo_builder();

    Photo_builder &likes(int no_likes);

    Photo_builder &hashtags(std::vector<std::string> hashtags);

    Photo_builder &comments(int no_comments);

    Photo_builder &theme(std::string theme);

    Photo_builder &brightness(int brightness);

    Photo_builder &contrast(int contrast);

    Photo_builder &saturation(int saturation);

    Photo_builder &filter(std::string filter);

    Photo_builder &file_path(std::string file_path);

    Photo build();

    ~Photo_builder();
};

#endif //OOP_PHOTO_BUILDER_H
