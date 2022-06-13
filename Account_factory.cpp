//
// Created by Anne Messner on 08.06.2022.
//

#include "Account_factory.h"
#include "Photo_builder.h"
#include "Live_builder.h"
#include "Checkin_builder.h"

std::shared_ptr<Account> Account_factory::create_fast_account(std::string username) {
    return std::make_shared<Account>(username, 0, 0, "");
}

std::shared_ptr<Account> Account_factory::create_kid_account(std::string username) {
    return std::make_shared<Account>(username, 100, 100, "children");
}

std::shared_ptr<Account> Account_factory::create_crypto_influencer(std::string username) {
    Photo_builder pb;
    Photo p = pb
            .likes(13242352)
            .comments(124124)
            .hashtags({"crypto", "btc"})
            .theme("crypto")
            .file_path("sample_btc.jpg")
            .build();
    std::shared_ptr a = std::make_shared<Account>(username, 250000, 10, "crypto");
    a->add_photo(p);
    return a;
}

std::shared_ptr<Account> Account_factory::create_fashion_influencer(std::string username) {
    Live_builder lb;
    Live l = lb
            .theme("fashion")
            .people_watching(210000)
            .starting_time(18)
            .ending_time(21)
            .build();
    std::shared_ptr a = std::make_shared<Account>(username, 250000, 12, "fashion");
    a->add_live(l);
    return a;
}

std::shared_ptr<Account> Account_factory::create_travel_influencer(std::string username) {
    Checkin_builder cb;
    Check_in c = cb
            .likes(159341)
            .hashtags({"dubai", "travel", "magicplace"})
            .theme("travel")
            .adress("Dubai Marina")
            .city("Dubai")
            .country("UAE")
            .build();
    std::shared_ptr a = std::make_shared<Account>(username, 213214, 2134, "travel");
    a->add_check_in(c);
    return a;
}

