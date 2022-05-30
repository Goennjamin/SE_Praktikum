//
// Created by leonw on 23.05.22.
//

#include "account.h"

account::account(const std::string &username, const std::string &password) : username(username),
                                                                                           password(password),
                                                                                           acc_level(1) {}

const std::string &account::getUsername() const {
    return username;
}

const std::string &account::getPassword() const {
    return password;
}

int account::getAccLevel() const {
    return acc_level;
}

void account::setAccLevel(int accLevel) {
    acc_level = accLevel;
}

void account::setUsername(const std::string &name) {
    account::username = name;
}

void account::setPassword(const std::string &pword) {
    account::password = pword;
}

account::~account() {

}
