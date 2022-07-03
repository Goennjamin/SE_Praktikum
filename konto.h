#ifndef KONTO_H
#define KONTO_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include "buchungssatz.h"
#include <bits/stdc++.h>
#include "utility"

using namespace std;
class konto : public buchungssatz
{
public:
    konto();
    konto(string name, string kontoart,vector<buchungssatz> bs);
    vector <konto> Konten;

    void BuchungssatzDurchfuehren(string kontoSoll,string kontoHaben, int betrag);

    const string &getName() const;

    const vector<konto> &getKonten() const;

    const string &getArt() const;




    bool ueberpruefeAnlagevermoegen(string name);
    bool ueberpruefeEigenkaptal(string name);
    bool ueberpruefeFremdkapital(string name);
    bool ueberpruefeUmlaufvermoegen(string name);
    unsigned int getId() const;
    void setId(unsigned int newId);

    map<string, int> &getEigenkapital();
    void setEigenkapital(map<string, int> &newEigenkapital);

    map<string, int> &getAnlagevermoegen();
    void setAnlagevermoegen(map<string, int> &newAnlagevermoegen);

    map<string, int> &getFremdkapital();
    void setFremdkapital(map<string, int> &newFremdkapital);

    map<string, int> &getUmlaufvermoegen();
    void setUmlaufvermoegen(map<string, int> &newUmlaufvermoegen);

    map<string,int> Anlagevermoegen = {};

private:
    konto sucheKonto(string kontoname);
    //vector<konto> KontoHinzufuegen(konto & k);
    string name;
    string art;
    unsigned int id;
    int Aktiva,Passiva;
    string Soll,Haben;
    vector<buchungssatz> bs;
    map<string,int> Eigenkapital;

    map<string,int> Fremdkapital;
    map<string,int> Umlaufvermoegen;
};

#endif // KONTO_H