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
    else{
        // TODO
    }

}



buchungssatz::buchungssatz(int datum, string von, string an, int betrag, int steuersatz) : datum(datum),
an(an),
von(von),
betrag(betrag),
steuersatz(
        steuersatz)  {

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

int buchungssatz::getSteuersatz() const {
    return steuersatz;
}

bool buchungssatz::isLanguage() const {
    return language;
}






