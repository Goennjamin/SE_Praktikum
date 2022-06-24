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

void ACS::manage_accounts(int access, bool language) {

bool looploop = true;

while(looploop) {

    setSprache(language);

    //int access = login();

    if (access!= 0) {

        bool loop = true;
        int id;
        int x;
        int y;

        while (loop) {


            if(language){
                std::cout   << "Was wuerden sie gerne tun?"<<"\n"
                            << "1. Erstelle einen neuen Account"<<"\n";
                if(access == 3){
                std::cout   << "2. Verwalte bereits existierende Accounts"<<"\n";
                //std::cout   << "3. Accounts löschen"<<"\n";
                }

                std::cout   << "4. Verlasse die Accountverwaltung"<<"\n";

            }else {

                std::cout << "What would you like to do?" << "\n"
                          << "1. Create a new Account" << "\n";
                if (access == 3) {
                    std::cout << "2. Manage existing Accounts" << "\n";
                    //std::cout<< "3. Delete Accounts"<<"\n";
                }
                std::cout << "4. Exit the ACS" << "\n";

            }
            std::cin >> y;
            std::cin.clear();


            if (y == 1) {

                std::string name, password;

                if(language){
                    std::cout << "Bitte geben Sie den Benutzernamen ein"<<"\n";
                }else{
                    std::cout << "Please enter the Username" << "\n";
                }
                std::cin >> name;
                if(language){
                    std::cout << "Bitte geben Sie das Passwort ein"<<"\n";
                }else {
                    std::cout << "Please enter the Password" << "\n";
                }
                std::cin >> password;

                createAccount(name, password);

            }

            if (y == 2 && access > 2) {

                if (has_account()) {

                    print_list();
                    if(language){
                        std::cout << "Welchen account würden sie gerne bearbeiten? Bitte geben sie die ID ein" << "\n";
                    }else {
                        std::cout << "Which account would you like to manage? Insert the id please" << "\n";
                    }
                    std::cin >> id;


                    if (id > acclist.size() - 1) {
                        id = {};

                        if(language){
                            std::cout << "Ungueltige ID, bitte erneut versuchen"<<"\n";
                        }else {
                            std::cout << "Invalid ID, please try again" << "\n";
                        }
                    } else {


                        if(language){
                            std::cout << "Was wuerden Sie gerne bearbeiten?" <<"\n";
                            std::cout << "1. Nutzernamen" <<"\n"
                                      << "2. Passwort" <<"\n"
                                      << "3. Account Stufe" <<"\n";

                        }else{

                            std::cout << "What would you like to change?" << "\n";
                            std::cout << "1. Username" << "\n"
                                                          "2. Password" << "\n"
                                                                       "3. access level"<<"\n";
                        }


                        std::cin >> x;


                        if (x == 1) {

                            std::string n;

                            if(language){
                                std::cout << "Bitte geben Sie den neuen Nutzernamen ein"<<"\n";
                            }else { std::cout << "Please insert the new Username" << "\n"; }


                            std::cin >> n;

                            set_acc_username(const_cast<account &>(getAcclist().at(id)), n);

                            x = 0;
                        }

                        if (x == 2) {

                            std::string n;

                            if(language){
                                std::cout << "Bitte geben Sie das neue Passwort ein"<<"\n";
                            }else {
                                std::cout << "Please insert the new Password" << "\n";
                            }

                            std::cin >> n;

                            set_acc_password(const_cast<account &>(getAcclist().at(id)), n);

                            x = 0;
                        }

                        if (x == 3) {

                            int level;

                            if(language){
                                std::cout << "Auf welches Level soll die Berechtigung des Accounts gesetzt werden?"<<"\n";
                            }else { std::cout << "Which account level should be set?" << "\n"; }
                            std::cin >> level;

                            set_acc_level(const_cast<account &>(getAcclist().at(id)), level);

                            x = 0;
                        }


                    }
                } else if(y == 2 && access < 3){

                    if(language){
                        std::cout << "Sie haben keine Berechtigung um diese Aktion auszufuehren"<<"\n";
                    }else {
                        std::cout << "You have no permission to perform this action" << "\n";
                    }
                }else{

                    if(language){
                        std::cout << "Es sind keine Accounts vorhanden, bitte erstellen Sie erst einen Account"<<"\n";
                    }else{
                        std::cout << "There are no accounts to manage, please create an account first" << "\n";
                    }

                }
            }

            if(y == 3 && access > 2){


                print_list();

                if(language){
                    std::cout << "Bitte geben sie die ID von dem zu löschenden Account ein"<<"\n";
                }else {
                    std::cout << "Please insert the account ID from the Account that you want to delete" << "\n";
                }
                int o;
                std::cin>> o;

            }

            std::cout << "\n";

            if (y == 4) {
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

    bool deutsch = getSprache();


    if(deutsch){
        std::cout<<"Bitte gib einen Benutzernamen ein"<<"\n";
    }else {

        std::cout << "Please enter your Username" << "\n";
    }
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
        if(deutsch){
            std::cout << "Ungueltiger Nutzername, bitte erneut versuchen"<<"\n";
        }else {
            std::cout << "Invalid username, please try again" << "\n";
        }
        return 0;
    }else {
        if(deutsch){
            std::cout << "Bitte geben Sie das Passwort ein"<<"\n";
        }else {

            std::cout << "Please enter your Password" << "\n";
        }
        std::cin.clear();

        std::string pw;
        std::cin >> pw;
        if (acclist.at(i).getPassword() != pw) {

            if(deutsch){
                std::cout << "Ungueltiges Passwort, bitte erneut versuchen"<<"\n";
            }
            else{
                std::cout << "Invalid password, please try again" << "\n";
            }
            return 0;

        } else {

            if(deutsch){
                std::cout << "Willkommen " << acclist.at(i).getUsername() << "\n";
            }else {
                std::cout << "Welcome " << acclist.at(i).getUsername() << "\n";
            }
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

}

void ACS::removeAccount() {



}

void ACS::setSprache(bool &s) {

    sprache = s;

}

bool ACS::getSprache() {
    return sprache;
};

