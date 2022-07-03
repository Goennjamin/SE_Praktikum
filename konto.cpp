#include "konto.h"
#include <vector>

konto::konto()
{

}

konto::konto(string name, string kontoart,vector<buchungssatz> bs) : name(name), art(kontoart)
{

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
{

    konto KontoSoll = sucheKonto(kontoSoll);
    konto KontoHaben = sucheKonto(kontoHaben);

    cout << "Bitte geben Sie ein Datum ein" << endl;
    int datum{};
    cin >> datum;
    //cout << "Welchen Steuersatz wollen Sie verwenden?"<< endl;


    buchungssatz b1 = buchungssatz(datum, KontoSoll.getName(), KontoHaben.getName(), betrag);
    //Konto Soll wird bearbeitet
    konto kS = kontentypIden(KontoSoll, betrag);
    (kS.ParseKontoartzuMap(kS.getId()), kS.getName(),  - betrag);
    //Konto Haben wird bearbeitet
    konto kH = kontentypIden(KontoSoll, betrag);
    (kH.ParseKontoartzuMap(kH.getId()), kH.getName(),  betrag);



}

const string &konto::getName() const
{
    return name;
}

bool konto::ueberpruefeVermoegen(string name, map<string,int> MyMap) {
    for (auto i = MyMap.begin(); i != MyMap.end(); i++){
        if(i->first ==name){
            return true;
        }
        else false;

    }


}

void konto::BuchungsseiteDurchfuehren(map<string, int> myMap, string name, int betrag) {

    for (auto i = myMap.begin(); i != myMap.end(); i++) {
        if (i->first == name) {
            i->second = i->second + betrag;
            cout << "Soll wurde verbucht" << endl;
        }
    }
}


konto konto::kontentypIden(konto k, int betrag){
    bool kontoVorhanden{};
    kontoVorhanden = ueberpruefeVermoegen(k.getName(), k.ParseKontoartzuMap(k.getId()));
    if (!(kontoVorhanden)) {

        k.ParseKontoartzuMap(k.getId()).insert(std::pair<string, int>(k.getName(), 0));


    }
    return k;
}

int konto::ParseIdzuKontoart(string id) {
    if (id == "Anlagevermoegen")return 0;
    if (id == "Umlaufvermoegen")return 1;
    if (id == "Eigenkapital")return 2;
    if (id == "Fremdkapital")return 3;
    return -1;
}

map<string, int> konto::ParseKontoartzuMap(int id) {
    if(id==0) return Anlagevermoegen;
    if(id==1) return Umlaufvermoegen;
    if(id==2) return Eigenkapital;
    if(id==3) return Fremdkapital;
}
