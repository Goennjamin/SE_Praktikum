#ifndef KONTO_H
#define KONTO_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


using namespace std;
class Konto
{
public:
    Konto();
    Konto(string name,string kontoart);
    vector <Konto> Konten ;

    void BuchungssatzDurchfuehren(string kontoSoll,string kontoHaben, int betrag);

    const string &getName() const;

    const vector<Konto> &getKonten() const;

    const string &getArt() const;

    const vector<int> &getSoll() const;

    const vector<int> &getHaben() const;

    void printBuchungssatz(string kontoSoll, string kontoHaben, int betrag);

private:
    Konto sucheKonto(string kontoname);
    // vector<Konto> KontoHinzufuegen(Konto & k);
    string name;
    string art;
    vector<int> Soll;
    vector<int> Haben;

};

#endif // KONTO_H