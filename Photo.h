//
// Created by Anne Messner on 26.04.2022.
//

#ifndef OOP_PHOTO_H
#define OOP_PHOTO_H

#include "Post.h"

class Photo : public Post {
    int brightness;
    int contrast;
    int saturation;
    std::string filter;
    std::string file_path;

public:
    Photo(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
          int brightness, int contrast, int saturation, const std::string &filter, const std::string &filePath);

    void show_post() override;

    [[nodiscard]] std::shared_ptr<Post> clone() const override {
        return std::make_shared<Photo>(*this);
    }


};


#endif //OOP_PHOTO_H
