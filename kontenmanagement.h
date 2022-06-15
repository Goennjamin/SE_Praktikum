#ifndef KONTENMANAGEMENT_H
#define KONTENMANAGEMENT_H
#include "konto.h"
#include <vector>

class Kontenmanagement : public Konto
{
public:
    Kontenmanagement();
    void kontoHinzufuegen(Konto & konto);
private:
    vector<Konto> Management;

};

#endif // KONTENMANAGEMENT_H