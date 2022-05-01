//
// Created by Anne Messner on 06.04.2022.
//
#include <iostream>
#include <vector>
#include<algorithm>
#include "Manager.h"
#include "Account.h"

//Constructor de Initiere
Manager::Manager(const std::string &name) : name(name) {}

//Operator == (de egalitate)
bool Manager::operator==(const Manager &mg) const {
    return name == mg.name &&
           accounts == mg.accounts;
}

// Operator << // avea friend
std::ostream &operator<<(std::ostream &os, const Manager &manager) {
    os << "name: " << manager.name << "\naccounts: \n";
    int i = 1;
    for (const auto &conturi: manager.accounts) {
        std::cout << "contul " << i << " : " << conturi << '\n';
        i++;
    }
    return os;
}


// Destructor
Manager::~Manager() {}

//setters
void Manager::change_name(std::string const &new_name) {
    this->name = new_name;
}

void Manager::add_account(const Account &new_account) {
    this->accounts.push_back(new_account);
}

//getters
std::string Manager::get_name() {
    return this->name;
}

Account Manager::get_top_account() {
    std::vector<Account> copy_accounts;
    copy_accounts = this->accounts;

    sort(copy_accounts.begin(), copy_accounts.end(), [](Account lhs, Account rhs) {
        return lhs.get_followers() > rhs.get_followers();
    });
    return copy_accounts[0];
}

// find account by username
Account Manager::find_account_by_username(const std::string &searched_username) {
    auto it = std::find_if(this->accounts.begin(), this->accounts.end(), [searched_username](Account account) {
        return account.get_username() == searched_username;
    });
    return *it;
}

void Manager::swap_accounts(Manager &manager, const int id_account1, const int id_account2) {
    Account::swap(this->accounts[id_account1], manager.accounts[id_account2]);
}

