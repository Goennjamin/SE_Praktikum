#include <iostream>
#include "ACS.h"
#include <string>
#include <fstream>
#include "sstream"
#include "kontenmanagement.h"

using namespace std;

bool rechte(false);
bool deutsch(true);

void kontoHinzufugen(Kontenmanagement & km);
void menuBuchung(Kontenmanagement & km);

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
    ACS acs1;

    Kontenmanagement KontoManager = Kontenmanagement();

    int access = acs1.login();

    while(true) {

        if (access == 0) {

            access = acs1.login();

        }

        if(deutsch) {

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
            std::cout << "x: Das Programm beenden"<<"\n";
        }else{

            cout << "Welcome to the financial system" <<"\n"
                 << "Which function would you like to use?" <<"\n"
                 << "Would you like to ..."<<"\n"
                 << "1. book posting records?"<<"\n"
                 << "2. look at the chart of accounts?"<<"\n"
                 << "3. write off investments?"<<"\n"
                 << "4. change the language?"<<"\n"
                 << "5. manage the employee accounts?"<<"\n"
                 << "6. open a new bank account?"<<"\n"
                 << "7. Logout/switch accounts?" << "\n";
                 if(access > 2){
                     cout << "8. look at the balance?"<<"\n"
                          << "9. process requests?"<<"\n";
                 }
                 cout << "x: Exit the program"<<"\n";
        }

        cout << endl;
        int userinput;
        cin >> userinput;
        cout << endl;

        switch (userinput) {
            case 1: // Buchungssätze
            {

                for (int i = 0; i < 3; i++) {
                    KontoManager.kontoHinzufuegen(KontoManager);

                }


                menuBuchung(KontoManager);
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
                if (deutsch)
                {

                    string line;

                    ifstream fascilities("fascilities.txt");
                    fstream fascilities_edited("fascilities_edited.txt");
                    if (fascilities)
                    {
                        while (getline(fascilities, line))
                        {
                            istringstream ss(line);

                            int artikelnummer;
                            string artikelname;
                            int listenpreis;
                            int restwert;
                            int dauer;
                            int restdauer;
                            ss >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer << " " << restdauer;


                            istringstream ss2;
                            restwert = restwert - (listenpreis / dauer);
                            restdauer--;
                            ss2 >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                            cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer << " " << restdauer;
                            if (fascilities_edited.is_open())
                            {
                                fascilities_edited << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer;
                                fascilities_edited << " " << restdauer << "\n";
                            }
                        }
                    }
                    else
                    {
                        string line;
                        ifstream fasilitieseng("fascilitieseng.txt");
                        fstream fascilitieseng_edited("fascilitieseng_edited.txt");
                        if (fascilities)
                        {
                            while (getline(fasilitieseng, line))
                            {
                                istringstream ss(line);
                                int artikelnummer;
                                string artikelname;
                                int listenpreis;
                                int restwert;
                                int dauer;
                                int restdauer;
                                ss >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                                cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer << " " << restdauer;


                                istringstream ss2;
                                restwert = restwert - (listenpreis / dauer);
                                restdauer--;
                                ss2 >> artikelnummer >> artikelname >> listenpreis >> restwert >> dauer >> restdauer;
                                cout << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer << " " << restdauer;
                                if (fascilitieseng_edited.is_open())
                                {
                                    fascilitieseng_edited << artikelnummer << " " << artikelname << " " << listenpreis << " " << restwert << " " << dauer;
                                    fascilitieseng_edited << " " << restdauer << "\n";
                                }
                            }
                        }

                    }
                }
                case 4: // Sprache Ändern
                    //cout << "Sprache aendern" << endl;

                    if(deutsch){
                        deutsch = false;
                    }else{
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


                    break;
                /*if (rechte)
                {
                    case 6: // Bilanz
                        cout << "Bilanz " << endl;
                    break;
                    case 7: // Anfragen Bearbeiten -- Anfragen Erstellen?
                        cout << "Rechte Vorhanden" << endl;
                    break;
                }*/

                /*
                    ifstream txt;
                    txt.open("C:\\Users\\GRyzL\\source\\repos\\michaellord\\txt.txt");
                    if (!txt)
                    {
                        ofstream txtcreate("C:\\Users\\GRyzL\\source\\repos\\michaellord\\txt.txt");
                    }
                    if (txt)
                    {
                        ofstream outfile("edited.txt"); //erstellen der edited.txt
                        fstream edited; //opened for output and input
                        edited.open("C:\\Users\\GRyzL\\source\\repos\\michaellord\\edited.txt");
                        if (!edited)
                        {
                            cerr << "Unable to open file edited.txt";
                            exit(1);
                        }

                        if (edited)
                        {
                            int index;
                            string line;
                            const string searchfor("such begriff");
                            const string exchangewith("exchange begriff");
                            //getline(lord, line);
                            //cout << line << endl; eine zeile
                            getline(txt, line);
                            for (int i = 0; i < 147; i++)
                            {
                                getline(txt, line);
                                cout << line << endl;
                                if (line.find(searchfor))
                                {
                                    while ((index = line.find(searchfor)) != string::npos)
                                    {
                                        line.erase(index, searchfor.length());
                                        line.insert(index, exchangewith);

                                    }
                                }
                                outfile << line << endl;

                            }
                            edited.close();
                        }

                    }
                    txt.close();
                    return 0;
                    */
            }
        }

    }
    }


void kontoHinzufugen(Kontenmanagement & km){
    cout << "Hiermit legen Sie ein neues Konto an:" << endl;
    cout << "Bitte geben Sie den Namen des Kontos ein:" << endl;
    string name{};
    cin >> name;
    cout << "Bitte geben Sie die Art des Kontos ein(Aktivkonto,Passivkonto,Aufwandskonto, Ertragskonto):" << endl;
    string art;
    cin >> art;
    Konto k(name,art);
    km.kontoHinzufuegen(k);
}

void menuBuchung(Kontenmanagement & km) {
    string kontoSoll{};
    string kontoHaben{};
    int betrag{};
    cout << "Bitte geben Sie das Konto ein von dem Sie buchen wollen" << endl;
    cin >> kontoSoll;
    cout << "Bitte geben Sie das Konto ein auf welches Sie buchen wollen" << endl;
    cin >> kontoHaben;
    cout << "Bitte geben Sie den zu verbuchenden Betrag ein" << endl;
    cin >> betrag;

    cout << "Der Buchunssatz lautet:" << endl;
    cout << setw(10) << kontoSoll << setw(10) << betrag << setw(10) << "an" << setw(10) << kontoHaben << endl;

    cout << "Ist das so korrekt ? (j/n)" << endl;
    string eingabe{};
    cin >> eingabe;

    km.BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);
    km.printBuchungssatz(kontoSoll, kontoHaben, betrag);
}