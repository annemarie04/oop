//
// Created by Anne Messner on 08.06.2022.
//

#ifndef OOP_ACCOUNT_FACTORY_H
#define OOP_ACCOUNT_FACTORY_H


#include "Account.h"

class Account_factory {
public:
    static std::shared_ptr<Account> create_fast_account(std::string username);

    static std::shared_ptr<Account> create_crypto_influencer(std::string username);

    static std::shared_ptr<Account> create_fashion_influencer(std::string username);

    static std::shared_ptr<Account> create_travel_influencer(std::string username);

    static std::shared_ptr<Account> create_kid_account(std::string username);
};


#endif //OOP_ACCOUNT_FACTORY_H
