//
// Created by jreis on 28.06.2022.
//

#ifndef ACS_BUCHUNGSSATZ_H
#define ACS_BUCHUNGSSATZ_H
#include <string>
#include <iomanip>
#include "iostream"
#include "string"
using namespace std;

class buchungssatz
{
public:
    buchungssatz();
    buchungssatz(int datum, string von, string  an, int betrag, int steuersatz);

    buchungssatz(int datum, const string &an, const string &von, int betrag, int steuersatz);


    virtual void printBuchungssatz(string kontoSoll, string kontoHaben, int betrag, bool language);



    //Konstruktor schreiben in .cpp
    //bestimmtes Datum ausgeben
    //  ganzen Monat ausgeben
    //  ganzes Jahr ausgeben -> vollständiges array
    //  read write
private:
    int datum;
    string an;
public:
    int getDatum() const;

    const string &getAn() const;

    const string &getVon() const;

    int getBetrag() const;

    int getSteuersatz() const;

    bool isLanguage() const;

private:
    string von;
    int betrag;
    int steuersatz;
    bool language;

};


#endif //ACS_BUCHUNGSSATZ_H
