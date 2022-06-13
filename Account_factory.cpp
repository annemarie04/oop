//
// Created by Anne Messner on 08.06.2022.
//

#include "Account_factory.h"

std::shared_ptr<Account> Account_factory::create_fast_account(const std::string &username) {
    return std::make_shared<Account>(Account(username, 1, 1, "none"));
}

std::shared_ptr<Account> Account_factory::create_kid_account(const std::string &username) {
    return std::make_shared<Account>(Account(username, 100, 100, "children"));
}

std::shared_ptr<Account> Account_factory::create_fashion_influencer(const std::string &username) {
    return std::make_shared<Account>(Account(username, 250000, 12, "fashion"));
}

std::shared_ptr<Account> Account_factory::create_travel_influencer(const std::string &username) {
    return std::make_shared<Account>(Account(username, 213214, 2134, "travel"));
}

Account_factory::~Account_factory() = default;
