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

template<typename T>
class Manager;

template<typename T>
std::ostream &operator<<(std::ostream &o, const Manager<T> &manager);


template<typename T>

class Manager {
    std::string name;
    std::vector<std::shared_ptr<Account>> accounts;
    T contact;
public:
    //Constructor de Initiere
    explicit Manager(const std::string &name, const T &contact);

    //Operator == (de verificare)
    bool operator==(const Manager &mg) const;

    // Operator <<
    friend std::ostream &operator<<<>(std::ostream &os, const Manager &manager);


    //setters
    void change_name(std::string const &new_name);

    void add_account(const std::shared_ptr<Account> &new_account);

    //getters
    std::string get_name();

    std::shared_ptr<Account> get_top_account();

    // find account by username
    std::shared_ptr<Account> find_account_by_username(const std::string &searched_username);

    void swap_accounts(const std::shared_ptr<Manager<T>> &manager, const int id_account1, const int id_account2);

    void changeContact(const T &new_contact);

    T getContact();

    // Destructor
    ~Manager();
};


#endif //OOP_MANAGER_H
