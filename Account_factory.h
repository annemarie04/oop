//
// Created by Anne Messner on 08.06.2022.
//

#ifndef OOP_ACCOUNT_FACTORY_H
#define OOP_ACCOUNT_FACTORY_H


#include "Account.h"

class Account_factory {
public:
    static std::shared_ptr<Account> create_fast_account(const std::string &username);

    static std::shared_ptr<Account> create_fashion_influencer(const std::string &username);

    static std::shared_ptr<Account> create_travel_influencer(const std::string &username);

    static std::shared_ptr<Account> create_kid_account(const std::string &username);

    ~Account_factory();
};


#endif //OOP_ACCOUNT_FACTORY_H
