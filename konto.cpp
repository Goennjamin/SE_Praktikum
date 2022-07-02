#include "konto.h"
#include <vector>

konto::konto()
{

}

konto::konto(string name, string kontoart,vector<buchungssatz> bs) : name(name), art(kontoart)
{
    map<string,int> Eigenkapital = {};
    map<string,int> Anlagevermoegen = {};
    map<string,int> Fremdkapital = {};
    map<string,int> Umlaufvermoegen ={};
}

const vector<konto> &konto::getKonten() const
{
    return Konten;
}


konto konto::sucheKonto(string kontoname)
{konto gefKonto{};
    for(const auto& value: Konten ){
        if(value.name == kontoname)
            gefKonto = value;
    }

    return gefKonto;
}









const string &konto::getArt() const
{
    return art;
}

void konto::BuchungssatzDurchfuehren(string kontoSoll, string kontoHaben, int betrag)
{ konto KontoSoll = sucheKonto(kontoSoll);
    konto KontoHaben = sucheKonto(kontoHaben);


}

const string &konto::getName() const
{
    return name;
}