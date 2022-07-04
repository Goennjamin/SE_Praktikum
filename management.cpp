#include "management.h"
#include <fstream>

management::management()
{
    vector<konto>Management;
}

void management::kontoHinzufuegen(konto & konto)
{
    Management.push_back(konto);
}

void management::speicherBuchungssatz(bool language, buchungssatz bs) {


    ofstream fout;
    string line;
    if (language) {



        //
        fout.open((R"(..\Uebersicht_Buchungssaetze.txt)"));

        // Execute a loop If file successfully opened

            fout << setw(10) << bs.getAn() << setw(10) << bs.getBetrag() << setw(10) << "Euro " << "an " << setw(10)
                 << bs.getVon() << setw(10) << "mit Steuersatz von: " << bs.getSteuersatz() <<" Prozent "<< endl;
            fout << endl;
            fout << endl;


        fout.close();

    } else {

        //
        fout.open((R"(..\Uebersicht_Buchungssaetze.txt)"));

        // Execute a loop If file successfully opened

        fout << setw(10) << bs.getAn() << setw(10) << bs.getBetrag() << setw(10) << "Euro " << "to " << setw(10)
             << bs.getVon() << setw(10) << "with a tax percentage of: " << bs.getSteuersatz() <<" percent "<< endl;
        fout << endl;
        fout << endl;


        fout.close();


    }
}

    bool management::ueberpruefeExistenz(string kname) {

        for (int i = 0; i < Management.size(); i++) {
            if (Management.at(i).getName() == kname)
                return true;
        }
        return false;
    }

    bool management::leeresManagement() {
        if (Management.empty()) return true;

        return false;
    }

vector<konto> management::getManagement() {
    return Management;
}

const vector<buchungssatz> &management::getJahr() const {
    return Jahr;
}

void management::printBilanz() {

    std::ofstream fout;

    fout.open(R"(..\ausgabe.txt)");

    int aktiva = 54;
    int umlauf = 45;

    int eigen = 40;
    int passiva = 50;

    int summeA = aktiva + umlauf;
    int summeP = eigen + passiva;

    std::string anlagespacer ="";
    std::string umlaufspacer ="";
    std::string summenspacer ="";

    std::string spacer ="";
    if(summeA > 99) spacer = " ";
    if(summeA > 999) spacer = "  ";
    if(summeA > 9999) spacer = "   ";
    if(summeA > 99999) spacer = "    ";
    if(summeA > 999999) spacer = "     ";
    if(summeA > 9999999) spacer = "      ";
    if(summeA > 99999999) spacer = "       ";
    summenspacer = spacer;


    fout   <<"SOLL---------------------------------------------------HABEN"<<"\n"
           <<"Anlage: "<<aktiva<<"                 |"<<"Eigenkapital: "<<eigen<<"\n"
           <<spacer<<"                          |                   "<<"\n"
           <<spacer<<"                          |                   "<<"\n"
           <<spacer<<"                          |                   "<<"\n"
           <<"Umlauf: "<<umlauf<<"                 |"<<"Schulden: "<<passiva<<"\n"
           <<spacer<<"                          |                   "<<"\n"
           <<spacer<<"                          |                   "<<"\n"
           <<"Summe: "<<summeA<<"                  |"<<"Summe: "<<summeP<<"\n";




    fout.close();


}

void management::menuBuchung(bool sprache) {
    string kontoSoll{};
    string kontoHaben{};
    int betrag{};
    // schaut, ob schon Konten angelegt wurden
    if(sprache){
        cout << "Bitte geben Sie das Konto ein von dem Sie buchen wollen" << endl;
        cin >> kontoSoll;

        if(leeresManagement()){ cout << "Es wurden noch keine Konten angelegt. Sie werden zum Hauptmenue zurückgeführt." << endl;

        }else{
            bool namecorrect = true;
            while(namecorrect){

                if(ueberpruefeExistenz(kontoSoll)){
                    cout << "Das Konto ist nicht vorhanden. Ueberpruefen Sie die Rechtschreibung oder geben Sie ein anderes Konto an. " << endl;
                }
                else if(ueberpruefeExistenz(kontoSoll)){
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

        BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);

        //gibt buchungssatz in der konsole aus

        printBuchungssatz(kontoSoll, kontoHaben, betrag, true);

        speicherBuchungssatz(sprache,Jahr.at(0));
    }else{

        cout << "Please insert the Account name, that you would like to access" << endl;
        string konto;
        cin >> konto;
        if(leeresManagement()){ cout << "There are no Accounts yet, you will be redirected to the main menu." << endl;

        }else{
            bool namecorrect = true;
            while(namecorrect){

                if(ueberpruefeExistenz(konto)){
                    cout << "This Account doesn't exist. Plese check your spelling, or try another Account." << endl;
                }
                else if(ueberpruefeExistenz(konto)){
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

        BuchungssatzDurchfuehren(kontoSoll, kontoHaben, betrag);
        printBuchungssatz(kontoSoll, kontoHaben, betrag, true);
    }


}


