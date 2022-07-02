//
// Created by jreis on 28.06.2022.
//

#include "buchungssatz.h"

using namespace  std;

buchungssatz::buchungssatz()
{



}

void buchungssatz::printBuchungssatz(string kontoSoll, string kontoHaben, int betrag, bool language)
{

    if(language){
    cout << "Der Buchungssatz lautet:" << endl;
    cout << setw(10) << kontoSoll << setw(10)  <<betrag << setw(10) <<"Euro  "<< "an"<< setw(10) << kontoHaben << endl;
    }
    else if(!language){
        cout << "The booking looks as follows:" << endl;
        cout << setw(10) << kontoSoll << setw(10)  <<betrag << setw(10) <<"Euro  "<< "to"<< setw(10) << kontoHaben << endl;
    }

}



buchungssatz::buchungssatz(int datum, string von, string an, int betrag) : datum(datum),
an(an),
von(von),
betrag(betrag)
{ steuersatz = 0.11;

}

int buchungssatz::getDatum() const {
    return datum;
}

const string &buchungssatz::getAn() const {
    return an;
}

const string &buchungssatz::getVon() const {
    return von;
}

int buchungssatz::getBetrag() const {
    return betrag;
}

double buchungssatz::getSteuersatz() const {
    return steuersatz;
}

bool buchungssatz::isLanguage() const {
    return language;
}








