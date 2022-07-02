#include "konto.h"

konto::konto()
{

}

konto::konto(string name, string kontoart) : name(name), art(kontoart)
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



const vector<int> &konto::getHaben() const
{
    return Haben;
}



const vector<int> &konto::getSoll() const
{
    return Soll;
}

const string &konto::getArt() const
{
    return art;
}

void konto::BuchungssatzDurchfuehren(string kontoSoll, string kontoHaben, int betrag)
{ konto KontoSoll = sucheKonto(kontoSoll);
    konto KontoHaben = sucheKonto(kontoHaben);
//Soll_Konten
    if(KontoSoll.getArt() == "Aktivkonto"){
        Soll.push_back(betrag);

    }
    else if(KontoSoll.getArt() == "Passivkonto"){
        Soll.push_back(betrag * (-1));
    }
    else if(KontoSoll.getArt() == "Aufwandskonto"){
        Soll.push_back(betrag);
    }
    else{
        Soll.push_back(betrag);
    }
//Haben_Konten
    if(KontoSoll.getArt() == "Aktivkonto"){
        Haben.push_back(betrag);

    }
    else if(KontoSoll.getArt() == "Passivkonto"){
        Haben.push_back(betrag * (-1));
    }
    else if(KontoSoll.getArt() == "Aufwandskonto"){
        Haben.push_back(betrag);
    }
    else{
        Haben.push_back(betrag);
    }

}

const string &konto::getName() const
{
    return name;
}