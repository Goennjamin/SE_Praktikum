#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "konto.h"
#include "buchungssatz.h"
#include <vector>
#include <array>

using namespace  std;

class management : public konto{
public:
    management();


    void kontoHinzufuegen(konto &konto);

    void speicherBuchungssatz(bool language, buchungssatz bs);

    bool ueberpruefeExistenz(string kname);

    bool leeresManagement( );

    vector<buchungssatz> Jahr;

    static void printBilanz();

private:
    vector<konto> Management;

public:
    const vector<buchungssatz> &getJahr() const;
//bestimmtes Datum ausgeben
//ganzen Monat ausgeben
// ganzes Jahr ausgeben
//read write


public:
    vector<konto> getManagement();

    void menuBuchung(bool sprache);
};
#endif //MANAGEMENT_H