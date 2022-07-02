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
    if(language){



        //
        fout.open((R"(..\Uebersicht_Buchungssaetze.txt)"));

        // Execute a loop If file successfully opened
        while (fout) {

            fout << setw(10) << bs.getAn() << setw(10)  <<bs.getBetrag() << setw(10) <<"Euro"<< "an"<< setw(10) << bs.getVon() << setw(10) << "mit Steuersatz von" << bs.getSteuersatz() <<endl;
            fout << endl;
            fout << endl;

        }

        fout.close();

    }else{

    }
void management::
}

bool management::ueberpruefeExistenz(string kname) {

    for(int i=0;i < Management.size(); i++){
        if(Management.at(i).getName() == kname)
            return true;
    }
    return false;
}

bool management::leeresManagement() {
    if(Management.empty())return true;

    return false;
}
