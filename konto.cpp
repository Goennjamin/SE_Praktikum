#include "konto.h"
#include <vector>

konto::konto()
{

}

konto::konto(string name, string kontoart,vector<buchungssatz> bs ) : name(name), art(kontoart)
{
    id = 5;
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

map<string, int> &konto::getUmlaufvermoegen()
{
    return Umlaufvermoegen;
}

void konto::setUmlaufvermoegen(map<string, int> &newUmlaufvermoegen)
{
    Umlaufvermoegen = newUmlaufvermoegen;
}

map<string, int> &konto::getFremdkapital()
{
    return Fremdkapital;
}

void konto::setFremdkapital(map<string, int> &newFremdkapital)
{
    Fremdkapital = newFremdkapital;
}

map<string, int> &konto::getAnlagevermoegen()
{
    return Anlagevermoegen;
}

void konto::setAnlagevermoegen(map<string, int> &newAnlagevermoegen)
{
    Anlagevermoegen = newAnlagevermoegen;
}

map<string, int> &konto::getEigenkapital()
{
    return Eigenkapital;
}

void konto::setEigenkapital(map<string, int> &newEigenkapital)
{
    Eigenkapital = newEigenkapital;
}

unsigned int konto::getId() const
{
    return id;
}

void konto::setId(unsigned int newId)
{
    id = newId;
}









const string &konto::getArt() const
{
    return art;
}

void konto::BuchungssatzDurchfuehren(string kontoSoll, string kontoHaben, int betrag)
{ konto KontoSoll = sucheKonto(kontoSoll);
    konto KontoHaben = sucheKonto(kontoHaben);
// schaut, ob Konten schon einmal für eine Buchung verwendet wurde
// wenn nicht, wird das konto mit dem betrag 0 hinzugefügt
    if(KontoSoll.getId()==0){

        bool kontoVorhanden = ueberpruefeAnlagevermoegen(KontoSoll.getName());

        if(!(kontoVorhanden)){

            std::pair<std::string, int> p1(KontoSoll.getName(), - betrag);
            getAnlagevermoegen().insert(p1);

        }
    }




}

const string &konto::getName() const
{
    return name;
}

bool konto::ueberpruefeAnlagevermoegen(string name) {
    return false;
}
