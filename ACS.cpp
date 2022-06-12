//
// Created by leonw on 22.05.22.
//

#include "ACS.h"




void ACS::createAccount(std::string un, std::string pw) {

    account a1(un,pw);
    acclist.push_back(a1);

}



void ACS::print_list() {

    for(int i = 0; i < acclist.size(); i++){


        std::cout<<"ID: "<<"\n";
        std::cout<<i<<"\n";

        std::cout<<"Username: "<<"\n";
        std::cout<<acclist.at(i).getUsername()<<"\n";

        std::cout<<"Password: "<<"\n";
        std::cout<<acclist.at(i).getPassword()<<"\n";

        std::cout<<"Account Level(1-3): "<<"\n";
        std::cout<<acclist.at(i).getAccLevel()<<"\n";
        std::cout <<"\n";

    }

}

void ACS::set_acc_level(account &a, int l) {


    if (l > 0 && l < 4){

        a.setAccLevel(l);

    }else{

        std::cout<<"invalid integer"<<"\n";

    }



}

const std::vector<account> &ACS::getAcclist() const {
    return acclist;
}

void ACS::manage_accounts(int access) {

bool looploop = true;

while(looploop) {

    //int access = login();

    if (access!= 0) {

        bool loop = true;
        int id;
        int x;
        int y;

        while (loop) {


            std::cout << "What would you like to do?" << "\n"
                      << "1. Create a new Account" << "\n";
            if(access == 3) {
                std::cout<< "2. Manage existing Accounts" << "\n";}
            std::cout<< "3. Exit the ACS" << "\n";

            std::cin >> y;
            std::cin.clear();


            if (y == 1) {

                std::string name, password;

                std::cout << "Please enter the Username" << "\n";
                std::cin >> name;
                std::cout << "Please enter the Password" << "\n";
                std::cin >> password;

                createAccount(name, password);

            }

            if (y == 2 && access > 2) {

                if (has_account()) {

                    print_list();
                    std::cout << "Which account would you like to manage? Insert the id please" << "\n";

                    std::cin >> id;


                    if (id > acclist.size() - 1) {
                        id = {};

                        std::cout << "Invalid ID, please try again" << "\n";

                    } else {


                        std::cout << "What would you like to change?" << "\n";
                        std::cout << "1. Username" << "\n"
                                                      "2. Password" << "\n"
                                                                       "3. access level"<<"\n";



                        std::cin >> x;


                        if (x == 1) {

                            std::string n;

                            std::cout << "Please insert the new Username" << "\n";
                            std::cin >> n;

                            set_acc_username(const_cast<account &>(getAcclist().at(id)), n);

                            x = 0;
                        }

                        if (x == 2) {

                            std::string n;

                            std::cout << "Please insert the new Password" << "\n";
                            std::cin >> n;

                            set_acc_password(const_cast<account &>(getAcclist().at(id)), n);

                            x = 0;
                        }

                        if (x == 3) {

                            int level;

                            std::cout << "Which account level should be set?" << "\n";
                            std::cin >> level;

                            set_acc_level(const_cast<account &>(getAcclist().at(id)), level);

                            x = 0;
                        }
                    }
                } else if(y == 2 && access < 3){

                    std::cout << "You have no permission to perform this action"<<"\n";

                }else{

                    std::cout << "There are no accounts to manage, please create an account first" << "\n";

                }
            }

            std::cout << "\n";

            if (y == 3) {
                y = 0;
                looploop = false;
                break;

            }
        }


    } else {

    }
}
}

void ACS::set_acc_username(account &a, std::string name) {

    a.setUsername(name);


}

void ACS::set_acc_password(account &a, std::string password) {

    a.setPassword(password);

}

bool ACS::has_account() {

    if(acclist.empty()){
        return false;
    }else{
        return true;
    }



}

ACS::~ACS() {

    std::cout<<"System closed"<<"\n";

}

int ACS::login() {

    std::string name;

    std::cout<<"Please enter your Username"<<"\n";
    std::cin >> name;


    bool succ = false;
    int i = 0;

    for(i; i <= acclist.size(); i++){

        if(acclist.at(i).getUsername() != name){

            continue;


        }else{
            succ = true;
            break;
        }
    }

    if(!succ){
        std::cout<<"Invalid username, please try again"<<"\n";
    }else {
        std::cout << "Please enter your Password" << "\n";
        std::cin.clear();

        std::string pw;
        std::cin >> pw;
        if (acclist.at(i).getPassword() != pw) {

            std::cout << "Invalid password, please try again" << "\n";
            return 0;

        } else {

            std::cout << "Welcome " << acclist.at(i).getUsername() << "\n";
            return acclist.at(i).getAccLevel();
        }
    }//else succ
}


ACS::ACS(){

    createAccount("root","root");

    acclist.at(0).setAccLevel(3);


}

int ACS::logout() {

    return 0;

};

