#ifndef KONTENMANAGEMENT_H
#define KONTENMANAGEMENT_H
#include "konto.h"
#include "buchungssatz.h"
#include <vector>
#include <array>

using namespace  std;

class management : public konto, public buchungssatz {
public:
    management();

    void kontoHinzufuegen(konto &konto);

    void speicherBuchungssatz(bool language, buchungssatz bs);

    bool ueberpruefeExistenz(string kname);

    bool leeresManagement( );

private:
    vector<konto> Management;
    array<vector<buchungssatz>, 12> Jahr;
//bestimmtes Datum ausgeben
//ganzen Monat ausgeben
// ganzes Jahr ausgeben
//read write

};
#endif KONTENMANAGEMENT_H