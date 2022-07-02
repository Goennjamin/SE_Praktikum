#ifndef KONTO_H
#define KONTO_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include "buchungssatz.h"

using namespace std;
class konto : public buchungssatz
{
public:
    konto();
    konto(string name, string kontoart);
    vector <konto> Konten ;

    void BuchungssatzDurchfuehren(string kontoSoll,string kontoHaben, int betrag);

    const string &getName() const;

    const vector<konto> &getKonten() const;

    const string &getArt() const;




    bool ueberpruefeAnlagevermoegen(string name);
    bool ueberpruefeEigenkaptal(string name);
    bool ueberpruefeFremdkapital(string name);
    bool ueberpruefeUmlaufvermoegen(string name);
private:
    konto sucheKonto(string kontoname);
    // vector<Konto> KontoHinzufuegen(Konto & k);
    string name;
    string art;
    unsigned int id;
    int Aktiva,Passiva;
    string Soll,Haben;

};

#endif // KONTO_H