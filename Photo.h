//
// Created by Anne Messner on 26.04.2022.
//

#ifndef OOP_PHOTO_H
#define OOP_PHOTO_H

#include "Post.h"
#include <memory>
#include <ostream>

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


    friend std::ostream &operator<<(std::ostream &os, const Photo &photo);

    int scor_relevanta() override;

    virtual ~Photo();

    int getBrightness() const;

    void setBrightness(int &b);

    int getContrast() const;

    void setContrast(int c);

    int getSaturation() const;

    void setSaturation(int s);

    const std::string &getFilter() const;

    void setFilter(const std::string &f);

    const std::string &getFilePath() const;

    void setFilePath(const std::string &filePath);

    void edit_photo(int &new_brightness, int &new_contrast, int &new_saturation);

};


#endif //OOP_PHOTO_H
