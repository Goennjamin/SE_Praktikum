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
    konto(string name, string kontoart,vector<buchungssatz> bs );
    vector <konto> Konten;

    void BuchungssatzDurchfuehren(string kontoSoll,string kontoHaben, int betrag);

    const string &getName() const;

    const vector<konto> &getKonten() const;

    const string &getArt() const;

    unsigned int getId() const;
    void setId(unsigned int newId);

    void BuchungsseiteDurchfuehren(map<string, int> myMap, string name, int betrag);



    bool ueberpruefeVermoegen(string name, map<string, int> MyMap);
    konto kontentypIden(konto k, int betrag);

    int ParseIdzuKontoart(string id);
    map<string,int>ParseKontoartzuMap(int id);
    private:
    konto sucheKonto(string kontoname);
    //vector<konto> KontoHinzufuegen(konto & k);
    string name;
    string art;
    unsigned int id;
    int Aktiva,Passiva;
    string Soll,Haben;
    vector<buchungssatz> bs;
    map<string,int> Eigenkapital = {};
    map<string,int> Anlagevermoegen ={};
    map<string,int> Fremdkapital = {};
    map<string,int> Umlaufvermoegen ={};
};

#endif // KONTO_H