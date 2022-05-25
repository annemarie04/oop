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
    std::vector<std::shared_ptr<Account>> accounts;
public:
    //Constructor de Initiere
    explicit Manager(const std::string &name);

    //Operator == (de verificare)
    bool operator==(const Manager &mg) const;

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Manager &manager);



    //setters
    void change_name(std::string const &new_name);

    void add_account(const std::shared_ptr<Account> &new_account);

    //getters
    std::string get_name();

    std::shared_ptr<Account> get_top_account();

    // find account by username
    std::shared_ptr<Account> find_account_by_username(const std::string &searched_username);

    void swap_accounts(Manager &manager, const int id_account1, const int id_account2);

    // Destructor
    ~Manager();
};


#endif //OOP_MANAGER_H
