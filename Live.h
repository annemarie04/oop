//
// Created by Anne Messner on 01.05.2022.
//

#ifndef OOP_LIVE_H
#define OOP_LIVE_H

#include "Post.h"
#include <memory>


class Live : public Post {
    int people_watching;
    int starting_time;
    int ending_time;

public:
    Live(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme,
         int people_watching, int starting_time, int ending_time);

    void show_post() override;

    [[nodiscard]] std::shared_ptr<Post> clone() const override {
        return std::make_shared<Live>(*this);
    }

};


#endif //OOP_LIVE_H
