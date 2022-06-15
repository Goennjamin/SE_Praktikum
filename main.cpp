#include <iostream>
#include "ACS.h"
#include <string>
#include <fstream>
#include "kontenmanagement.h"

using namespace std;

bool rechte(false);
bool deutsch(false);

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

        cout << "Willkommen im Finanzsystem!" << endl;
        cout << "Welche Funktion des Finanzsystems wollen Sie verwenden?" << endl;
        cout << "Moechten Sie ... " << endl;
        cout << "1. Buchungssätze, Buchen?" << endl;
        cout << "2. Kontenplan ausgeben?" << endl;
        cout << "3. Anlagen Abschreiben?" << endl;
        cout << "4. Sprache aendern?" << endl;
        cout << "5. Account Management" << endl;
        cout << "6. Neues Konto eröffnen" <<"\n";
        cout << "7. Logout/Account wechseln" << endl;
        if (rechte) {
            cout << "8. Bilanz ausgeben?"
                 << endl; // Verschachteltes Menü, Bilanz zu einem gewissen Zeitpunkt ausgeben, aktuell ausgeben?
            cout << "9. Anfragen bearbeiten?" << endl;
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
                    std::ifstream f("Kontenplan.txt");

                    if (f.is_open()) {
                        std::cout << f.rdbuf();
                    }
                    break;
                } else {
                    cout << "Here is the current chart of Accounts: " << endl << endl;
                    std::ifstream f("ChartOfAccounts.txt");

                    if (f.is_open()) {
                        std::cout << f.rdbuf();
                    }
                    break;
                }
            }
            case 3: // Abschreibungen
            {
                int choice;
                cout << "Moechten Sie ein Gut Abschreiben [a] oder Anlegen? [b]" << endl;
                cin >> choice;
                cout << endl;
                switch (choice)
                    case 'a': {
                        ifstream abs("Goods.txt");
                    }

                //



                /*case 'b':
                {
                    cout << "Welches Gut moechten Sie Anlegen?" << endl;
                    int Kennung = 100000; //erste gut hat nummber 100000, daraufhin wird die letzte line genommen, atoi zum kennung auslesen, kennung++ für nächstes gut
                    string Bezeichnung;
                    int Wert;
                    int Dauer;
                    cout << "Bitte geben Sie die Bezeichnung, den Wert und die vorraussichtliche Dauer des Guts in Ihrem Unternehmen an" << endl;
                    cin >> Bezeichnung >> Wert >> Dauer;
                    for (Kennung;; Kennung++)
                    {
                        cout << Kennung << " " << Bezeichnung << " " << Wert << " " << Dauer;
                    }
                }
                }
                    break;
                    */
                case 4: // Sprache Ändern
                    cout << "Sprache Ändern" << endl;
                break;


                case 5:


                    acs1.manage_accounts(access);

                break;

                case 6:


                    kontoHinzufugen(KontoManager);

                    break;

                case 7:


                    access = acs1.logout();

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