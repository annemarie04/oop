//
// Created by Anne Messner on 06.04.2022.
//
#include <iostream>
#include <vector>
#include<algorithm>
#include "Manager.h"
#include "Account.h"

template<typename T>
//Constructor de Initiere
Manager<T>::Manager(const std::string &name, const T &contact) : name(name), contact(contact) {}
//Operator == (de egalitate)

template<typename T>
bool Manager<T>::operator==(const Manager &mg) const {
    return name == mg.name &&
           accounts == mg.accounts;
}

template<typename T>
// Operator << // avea friend
std::ostream &operator<<(std::ostream &os, const Manager<T> &manager) {
    os << "name: " << manager.name << "\naccounts: \n";
    int i = 1;
    for (const auto &conturi: manager.accounts) {
        std::cout << "contul " << i << " : " << *conturi << '\n';
        i++;
    }
    os << "contact: " << manager.contact << '\n';
    return os;
}

template<typename T>
// Destructor
Manager<T>::~Manager() {}

template<typename T>
//setters
void Manager<T>::change_name(std::string const &new_name) {
    this->name = new_name;
}

template<typename T>
void Manager<T>::add_account(const std::shared_ptr<Account> &new_account) {
    this->accounts.push_back(new_account);
}

template<typename T>
//getters
std::string Manager<T>::get_name() {
    return this->name;
}

template<typename T>
std::shared_ptr<Account> Manager<T>::get_top_account() {
    std::vector<std::shared_ptr<Account>> copy_accounts;
    copy_accounts = this->accounts;

    sort(copy_accounts.begin(), copy_accounts.end(),
         [](const std::shared_ptr<Account> &lhs, const std::shared_ptr<Account> &rhs) {
             return lhs->get_followers() > rhs->get_followers();
         });
    return copy_accounts[0];
}

template<typename T>
// find account by username
std::shared_ptr<Account> Manager<T>::find_account_by_username(const std::string &searched_username) {
    auto it = std::find_if(this->accounts.begin(), this->accounts.end(),
                           [searched_username](std::shared_ptr<Account> &account) {
                               return account->get_username() == searched_username;
                           });
    return *it;
}

template<typename T>
void
Manager<T>::swap_accounts(const std::shared_ptr<Manager<T>> &manager, const int id_account1, const int id_account2) {
    Account::swap(*this->accounts[id_account1], *manager->accounts[id_account2]);
}

template<typename T>
void Manager<T>::changeContact(const T &new_contact) {
    this->contact = new_contact;
}

template<typename T>
T Manager<T>::getContact() {
    return this->contact;
}
