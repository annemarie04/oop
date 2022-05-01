//
// Created by Anne Messner on 26.04.2022.
//

#include "Photo.h"

Photo::Photo(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
             int brightness, int contrast, int saturation, const std::string &filter, const std::string &filePath)
        : Post(noLikes, noComments, hashtags, theme), brightness(brightness), contrast(contrast),
          saturation(saturation), filter(filter), file_path(filePath) {}

void Photo::show_post() {
    Post *post = this;
    std::cout << *post << "\n\tBrightness: " << this->brightness << "\n\tContrast: " << this->contrast
              << "\n\tSaturation: " << this->saturation << "\n\tFilter: " << this->filter << "\n\tFile Path: "
              << this->file_path << "\n";
}
