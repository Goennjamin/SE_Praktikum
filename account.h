//
// Created by leonw on 23.05.22.
//

#ifndef ACS_ACCOUNT_H
#define ACS_ACCOUNT_H
#include "string"
#include "iostream"

class account {


private:

    std::string username, password;
    int acc_level;


public:
    account(const std::string &username, const std::string &password);

    const std::string &getUsername() const;
    void setUsername(const std::string &name);


    const std::string &getPassword() const;

    void setPassword(const std::string &pword);

    int getAccLevel() const;
    void setAccLevel(int accLevel);

    virtual ~account();
};


#endif //ACS_ACCOUNT_H
