#include <iostream>
#include "ACS.h"
#include <string>
#include <fstream>
#include "sstream"
#include "management.h"

using namespace std;

bool rechte(false);
bool deutsch;

void kontoHinzufugen(management & km, bool sprache);
void menuBuchung(management & km, bool sprache);
int idzuKontoart(string id);
//funktion des logins mit login daten

void printer()
{
    std::string line;
    while (std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }
}

int main() // txt = read file, edited = save file. buchungen in txt speichern und auslesen. multiple files?
{

    std::string selection;
    std::cout<<"Select language"<<"\n";
    std::cout<<"d = German, e = English"<<"\n";
    std::cin >> selection;
    if(selection == "d" || selection == "e"){
        if(selection == "d"){
            deutsch = true;
        }else if(selection == "e"){
            deutsch = false;
        }
    }else if(selection != "d" || selection != "e"){
        std::cout << "Invalid input, english has been selected as the default language"<<"\n";
        deutsch = false;
    }

    ACS acs1;

    management KontoManager = management();

    int access = acs1.login(deutsch);
    bool loop = true;
    while (loop) {

        if (access == 0) {

            access = acs1.login(deutsch);

        }

        if (deutsch) {

            cout << "Willkommen im Finanzsystem!" << endl;
            cout << "Welche Funktion des Finanzsystems wollen Sie verwenden?" << endl;
            cout << "Moechten Sie ... " << endl;
            cout << "1. Buchungssätze, Buchen?" << endl;
            cout << "2. Kontenplan ausgeben?" << endl;
            cout << "3. Anlagen Abschreiben?" << endl;
            cout << "4. Sprache aendern?" << endl;
            cout << "5. Account Management" << endl;
            cout << "6. Neues Konto eröffnen" << "\n";
            cout << "7. Logout/Account wechseln" << endl;
            if (rechte) {
                cout << "8. Bilanz ausgeben?"
                     << endl; // Verschachteltes Menü, Bilanz zu einem gewissen Zeitpunkt ausgeben, aktuell ausgeben?
                cout << "9. Anfragen bearbeiten?" << endl;
            }
            std::cout << "10: Das Programm beenden" << "\n";
        } else {

            cout << "Welcome to the financial system" << "\n"
                 << "Which function would you like to use?" << "\n"
                 << "Would you like to ..." << "\n"
                 << "1. book posting records?" << "\n"
                 << "2. look at the chart of accounts?" << "\n"
                 << "3. write off investments?" << "\n"
                 << "4. change the language?" << "\n"
                 << "5. manage the employee accounts?" << "\n"
                 << "6. open a new bank account?" << "\n"
                 << "7. Logout/switch accounts?" << "\n";
            if (access > 2) {
                cout << "8. look at the balance?" << "\n"
                     << "9. process requests?" << "\n";
            }
            cout << "10: Exit the program" << "\n";
        }

        cout << endl;
        int userinput;
        cin >> userinput;
        cout << endl;

        switch (userinput) {
            case 1:// Buchungssätze
            {       // validiere input -> gibt es die konten überhaupt?, ertstelle ein objekt des typs buchungssatz
                // buchungssatz schreiben in file
                // gehe in konten rein und führe die buchung durch






                //optional steuersatz verändern

                menuBuchung(KontoManager, deutsch);
                break;
            }





            case 2: // Kontenplan
            {

                if (deutsch) {
                    cout << "Hier der aktuelle Kontenplan des Unternehmens: " << endl << endl;
                    std::ifstream f(R"(..\Kontenplan.txt)");

                    if (f.is_open()) {
                        std::cout << f.rdbuf();
                    }
                    break;
                } else {
                    cout << "Here is the current chart of Accounts: " << endl << endl;
                    std::ifstream f(R"(..\ChartOfAccounts.txt)");

                    if (f.is_open()) {
                        std::cout << f.rdbuf();
                    }
                    break;
                }
            }
            case 3: // Abschreibungen
            {
                if (deutsch) {

                    string line;

                    ifstream fascilities(R"(..\fascilities.txt)");
                    fstream fascilities_edited(R"(..\fascilities_edited.txt)");
                    if (fascilities) {
                        while (getline(fascilities, line)) {
                            istringstream ss(line);

                            int artikelnummer;
                            string artikelname;
                            int listenpreis;
                            int restwert;
                            int dauer;
                            int restdauer;
                            ss >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " "
                                 << dauer << " " << restdauer << "\n";


                            istringstream ss2;
                            restwert = restwert - (listenpreis / dauer);
                            restdauer--;
                            ss2 >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " "
                                 << dauer << " " << restdauer << "\n";
                            if (fascilities_edited.is_open()) {
                                fascilities_edited << artikelnummer << " " << artikelname << " " << listenpreis << " "
                                                   << restwert << " " << dauer;
                                fascilities_edited << " " << restdauer << "\n";
                            }
                        }
                    }
                    break;
                } else {
                    string line;
                    ifstream fasilitieseng(R"(..\fascilitieseng.txt)");
                    fstream fascilitieseng_edited(R"(..\fascilitieseng_edited.txt)");
                    if (fasilitieseng) {
                        while (getline(fasilitieseng, line)) {
                            istringstream ss(line);
                            int artikelnummer;
                            string artikelname;
                            int listenpreis;
                            int restwert;
                            int dauer;
                            int restdauer;
                            ss >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " "
                                 << dauer << " " << restdauer << "\n";


                            istringstream ss2;
                            restwert = restwert - (listenpreis / dauer);
                            restdauer--;
                            ss2 >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " "
                                 << dauer << " " << restdauer << "\n";
                            if (fascilitieseng_edited.is_open()) {
                                fascilitieseng_edited << artikelnummer << " " << artikelname << " " << listenpreis
                                                      << " " << restwert << " " << dauer;
                                fascilitieseng_edited << " " << restdauer << "\n";
                            }
                        }
                    }

                }
                break;
            }
            case 4: // Sprache Ändern
                //cout << "Sprache aendern" << endl;

                if (deutsch) {
                    deutsch = false;
                } else {
                    deutsch = true;
                }
                break;


            case 5:


                acs1.manage_accounts(access, deutsch);


                break;

            case 6:


                kontoHinzufugen(KontoManager, deutsch);

                break;

            case 7:

                access = acs1.logout();

                break;

            case 10:


                loop = false;

                break;


        }
    }

}



void kontoHinzufugen(management & km, bool sprache){


    if(sprache){
        cout << "Hiermit legen Sie ein neues Konto an:" << endl;
        cout << "Bitte geben Sie den Namen des Kontos ein:" << endl;
    }else if(!sprache){
        cout << "You are in the process of creating a new account"<<"n";
        cout << "Please insert the accountname"<<"\n";

    }

    string name{};
    cin >> name;

    if(sprache){

        cout << "Bitte geben Sie die Art des Kontos ein(Aktivkonto,Passivkonto,Aufwandskonto, Ertragskonto):" << endl;

    }else if(!sprache){

        cout <<" Please insert the accounttype (activeaccount, passiveaccount,....account,....account)"<<"\n";

    }

    string art;
    cin >> art;

    vector<buchungssatz> leeresbsArray;
    konto k = konto(name, art, leeresbsArray);
    unsigned int id = idzuKontoart(art);
    k.setId(id);



    km.kontoHinzufuegen(k);
    /*for(int i = 0; i < km.getManagement().size(); i++){

        std::cout<<km.getManagement().at(i).getName();

    }*/ //Debug
}

void menuBuchung(management & km, bool sprache) {
    string kontoSoll{};
    string kontoHaben{};
    int betrag{};
    // schaut, ob schon Konten angelegt wurden
    if(sprache){
        cout << "Bitte geben Sie das Konto ein von dem Sie buchen wollen" << endl;
        cin >> kontoSoll;

        if(km.leeresManagement()){ cout << "Es wurden noch keine Konten angelegt. Sie werden zum Hauptmenue zurückgeführt." << endl;

        }else{
            bool namecorrect = true;
            while(namecorrect){

                if(!km.ueberpruefeExistenz(kontoSoll)){
                    cout << "Das Konto ist nicht vorhanden. Ueberpruefen Sie die Rechtschreibung oder geben Sie ein anderes Konto an. " << endl;
                }
                else if(km.ueberpruefeExistenz(kontoSoll)){
                    namecorrect =false;

                }
                cout << setw(20) << kontoSoll << setw(20) << " wurde akzeptiert" << endl;


            }
        }



        cout << "Bitte geben Sie das Konto ein auf welches Sie buchen wollen" << endl;
        cin >> kontoHaben;

        //TODO Validierung
        cout << "Bitte geben Sie den zu verbuchenden Betrag ein" << endl;
        cin >> betrag;

        cout << "Der Buchunssatz lautet:" << endl;
        cout << setw(10) << kontoSoll << setw(10) << betrag << setw(10) << "an" << setw(10) << kontoHaben << endl;

        cout << "Ist das so korrekt? (j/n)" << endl;
        string eingabe{};
        cin >> eingabe;

        km.BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);
        // gibt buchungssatz in der konsole aus
        km.printBuchungssatz(kontoSoll, kontoHaben, betrag, true);
    }else{
        cout << "Please insert the Account name, that you would like to access" << endl;
        string konto;
        cin >> konto;
        if(km.leeresManagement()){ cout << "There are no Accounts yet, you will be redirected to the main menu." << endl;

        }else{
            bool namecorrect = true;
            while(namecorrect){

                if(!km.ueberpruefeExistenz(konto)){
                    cout << "This Account doesn't exist. Plese check your spelling, or try another Account." << endl;
                }
                else if(km.ueberpruefeExistenz(konto)){
                    namecorrect = false;

                }


            }
        }


        cout << "Please enter the Account name from which you would like to book" << endl;
        cin >> kontoSoll;
        cout << "Please enter the name from the receiving account" << endl;
        cin >> kontoHaben;
        cout << "Please insert the Amount" << endl;
        cin >> betrag;

        cout << "The Booking looks as follows:" << endl;
        cout << setw(10) << kontoSoll << setw(10) << betrag << setw(10) << "an" << setw(10) << kontoHaben << endl;

        cout << "Is this correct? (j/n)" << endl;
        string eingabe{};
        cin >> eingabe;

        km.BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);
        km.printBuchungssatz(kontoSoll, kontoHaben, betrag, true);
    }


}


int idzuKontoart(string id){
    if (id == "Anlagevermoegen")return 0;
    if (id == "Umlaufvermoegen")return 1;
    if (id == "Eigenkapital")return 2;
    if (id == "Fremdkapital")return 3;

    return -1;
}