#include "kontenmanagement.h"

Kontenmanagement::Kontenmanagement()
{
    vector<Konto>Management;
}

void Kontenmanagement::kontoHinzufuegen(Konto & konto)
{
    Management.push_back(konto);
}