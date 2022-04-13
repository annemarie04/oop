//
// Created by Anne Messner on 06.04.2022.
//

#ifndef OOP_MANAGER_H
#define OOP_MANAGER_H

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include "Account.h"
#include "Post.h"

class Manager {
    std::string name;
    std::vector<Account> accounts;
public:
    //Constructor de Initiere
    Manager(const std::string &name, const std::vector<Account> &accounts);

    //Operator == (de verificare)
    bool operator==(const Manager &mg) const;

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Manager &manager);

    // Destructor
    virtual ~Manager();

    //setters
    void change_name(std::string const &new_name);

    void add_account(const Account &new_account);

    //getters
    std::string get_name();

    Account get_top_account();

    // find account by username
    Account find_account_by_username(const std::string &searched_username);
};


#endif //OOP_MANAGER_H
