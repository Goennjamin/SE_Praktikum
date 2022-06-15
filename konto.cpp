#include "konto.h"

Konto::Konto()
{

}

Konto::Konto(string name, string kontoart) : name(name), art(kontoart)
{
    Soll ={};
    Haben={};
}

const vector<Konto> &Konto::getKonten() const
{
    return Konten;
}


Konto Konto::sucheKonto(string kontoname)
{Konto gefKonto{};
    for(const auto& value: Konten ){
        if(value.name == kontoname)
            gefKonto = value;
    }

    return gefKonto;
}



const vector<int> &Konto::getHaben() const
{
    return Haben;
}

void Konto::printBuchungssatz(string kontoSoll, string kontoHaben, int betrag)
{
    cout << "Der Buchungssatz lautet:" << endl;
    cout << setw(10) << kontoSoll << setw(10)  <<betrag << setw(10) <<"Euro  "<< "an"<< setw(10) << kontoHaben << endl;


}

const vector<int> &Konto::getSoll() const
{
    return Soll;
}

const string &Konto::getArt() const
{
    return art;
}

void Konto::BuchungssatzDurchfuehren(string kontoSoll, string kontoHaben, int betrag)
{ Konto KontoSoll = sucheKonto(kontoSoll);
    Konto KontoHaben = sucheKonto(kontoHaben);
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

const string &Konto::getName() const
{
    return name;
}