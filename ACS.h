//
// Created by leonw on 22.05.22.
//

#ifndef ACS_ACS_H
#define ACS_ACS_H

#include <utility>


#include "map"
#include "vector"
#include "account.h"


class ACS {


private:

    std::vector<account> acclist;
    bool sprache = true;


public:
    ACS();
    void createAccount(std::string un, std::string pw);
    void removeAccount();
    void manage_accounts(int access, bool language);
    void set_acc_username(account &a, std::string name);
    void set_acc_password(account &a, std::string password);
    void set_acc_level(account &a, int l);
    void print_list();
    bool has_account();
    int login();
    int logout();
    void setSprache(bool &s);
    bool getSprache();

    const std::vector<account> &getAcclist() const;

    ~ACS();
};


#endif //ACS_ACS_H
