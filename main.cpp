#include <iostream>
#include "ACS.h"
#include <string>
#include <fstream>
#include "sstream"
#include "management.h"

using namespace std;

bool rechte(false);
bool deutsch;
vector<buchungssatz> jahr;

void kontoHinzufugen(management & km);
void menuBuchung(management & km, bool sprache);
int  ParseIdzuKontoart(string art);

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
                cout << "8. look at the balance?" << "\n";
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


                kontoHinzufugen(KontoManager);

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



void kontoHinzufugen(management & km){

    if(deutsch){
        cout << "Hiermit legen Sie ein neues Konto an:" << endl;
        cout << "Bitte geben Sie den Namen des Kontos ein:" << endl;
        string name{};
        cin >> name;
        cout << "Bitte geben Sie die Art des Kontos ein(Aktivkonto,Passivkonto,Aufwandskonto, Ertragskonto):" << endl;
        string art;
        cin >> art;
        std::vector<buchungssatz> bs;
        if(art != "Aktivkonto" && art != "Passivkonto" && art != "Aufwandskonto" && art != "Ertragskonto"){
            cout << "Ungueltige kontoart, bitte die Kontenerstellung nochmal versuchen" <<"\n";
        }else{
            konto k(name, art, bs);
            int id = k.ParseIdzuKontoart(art);
            k.setId(id);
            km.kontoHinzufuegen(k);
            cout << "Konto: " << k.getName() << " wurde erstellt"<<"\n";
        }
    }else{
        cout << "You are in the process of creating a new account:" << endl;
        cout << "Please enter the account name:" << endl;
        string name{};
        cin >> name;
        cout << "Please specify the account type (Aktivkonto,Passivkonto,Aufwandskonto, Ertragskonto)" << endl;
        string art;
        cin >> art;
        std::vector<buchungssatz> bs;
        if(art != "Aktivkonto" && art != "Passivkonto" && art != "Aufwandskonto" && art != "Ertragskonto"){
            cout << "Invalid account type, please start the account creation again" <<"\n";
        }else{
            konto k(name, art, bs);
            int id = k.ParseIdzuKontoart(art);
            k.setId(id);
            km.kontoHinzufuegen(k);
            cout << "The account: " << k.getName() << " has been created"<<"\n";
        }
    }



}

void menuBuchung(management & km, bool sprache) {
    string kontoSoll{};
    string kontoHaben{};
    int betrag{};

    if(sprache){
        cout << "Bitte geben Sie den Kontonamen ein, auf das Sie zugreifen wollen." << endl;
        string konto;
        cin >> konto;
        if(km.leeresManagement()){ cout << "Es wurden noch keine Konten angelegt. Sie werden zum Hauptmenue zurückgeführt." << endl;

        }else{
            bool namecorrect = true;
            while(namecorrect){

                if(!km.ueberpruefeExistenz(konto)){
                    cout << "Das Konto ist nicht vorhanden. Ueberpruefen Sie die Rechtschreibung oder geben Sie ein anderes Konto an. " << endl;
                }
                else if(km.ueberpruefeExistenz(konto)){
                    namecorrect =false;

                }
                cout << setw(20) << kontoSoll << setw(20) << " wurde akzeptiert" << endl;


            }
        }


        cout << "Bitte geben Sie das Konto ein von dem Sie buchen wollen" << endl;
        cin >> kontoSoll;
        cout << "Bitte geben Sie das Konto ein auf welches Sie buchen wollen" << endl;
        cin >> kontoHaben;
        cout << "Bitte geben Sie den zu verbuchenden Betrag ein" << endl;
        cin >> betrag;

        cout << "Der Buchunssatz lautet:" << endl;
        cout << setw(10) << kontoSoll << setw(10) << betrag << setw(10) << "an" << setw(10) << kontoHaben << endl;

        cout << "Ist das so korrekt? (j/n)" << endl;
        string eingabe{};
        cin >> eingabe;

        km.BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);
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
                    namecorrect =false;

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

       // km.getManagement().push_back()

        buchungssatz b1;
        km.speicherBuchungssatz(deutsch,b1);

    }


}

