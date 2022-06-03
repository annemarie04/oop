//
// Created by Anne Messner on 26.04.2022.
//

#include "Photo.h"

Photo::Photo(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
             int brightness, int contrast, int saturation, const std::string &filter, const std::string &filePath)
        : Post(noLikes, noComments, hashtags, theme), brightness(brightness), contrast(contrast),
          saturation(saturation), filter(filter), file_path(filePath) {}

std::ostream &operator<<(std::ostream &os, const Photo &photo) {
    os << static_cast<const Post &>(photo) << " brightness: " << photo.brightness << " contrast: " << photo.contrast
       << " saturation: " << photo.saturation << " filter: " << photo.filter << " file_path: " << photo.file_path;
    return os;
}

int Photo::getBrightness() const {
    return brightness;
}

void Photo::setBrightness(const int &b) {
    this->brightness = b;
}

int Photo::getContrast() const {
    return contrast;
}

void Photo::setContrast(int c) {
    Photo::contrast = c;
}

int Photo::getSaturation() const {
    return saturation;
}

void Photo::setSaturation(int s) {
    Photo::saturation = s;
}

const std::string &Photo::getFilter() const {
    return filter;
}

void Photo::setFilter(const std::string &f) {
    Photo::filter = f;
}

const std::string &Photo::getFilePath() const {
    return file_path;
}

void Photo::setFilePath(const std::string &filePath) {
    file_path = filePath;
}

void Photo::show_post() {
    std::cout << *this;
}

int Photo::scor_relevanta() {
    int scor = (this->get_likes() * 3 + this->getNoComments() * 7) / 10;
    if (this->filter == "clarendon") { scor = scor * 2; }
    if (brightness >= 50) { scor += 20; }
    if (contrast >= 20) { scor += 10; }
    if (saturation < 60) { scor += 5; }

    return scor;
}

void Photo::edit_photo(const int &new_brightness, const int &new_contrast, const int &new_saturation) {
    this->setBrightness(new_brightness);
    this->setContrast(new_contrast);
    this->setSaturation(new_saturation);
}

std::shared_ptr<Post> Photo::clone() const {
    return std::make_shared<Photo>(*this);
}

Photo::~Photo() {}

