#include "Vehicule.h"

Vehicule::Vehicule(string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,float tarif,bool etatFeux,bool etatFrein,bool etatCarosserie,bool etatDirection)
{
    this->matricule=matricule;
    this->marque=marque ;
    this->age=age ;
    this->typeCons=typeCons ;
    this->nbRoues=nbRoues ;
    //this->tarif=10.0;
}
void Vehicule::saisie(){
cin>>*this ;
}
void Vehicule::affiche(){
cout<<*this;
}
string afficheValide(bool e)
{
    if(e==1)
        return "valide ";
return "non valide X";
}
ostream& operator<<(ostream& out, Vehicule& v)
{
    //string ag;
    cout<<"matricule: ";
    out<<v.matricule<<endl;
    cout<<"marque: ";
    out<<v.marque<<endl;
    cout<<"age: ";
    out<<v.age<<endl;
    cout<<"nb Roues:";
    out<<v.nbRoues<<endl;
    cout<<"Type de consommation : ";
    switch(v.typeCons){
    case Diesel : out<<"Diesel"<<endl;break;
    case Electrique : out<<"Electrique"<<endl;break;
    case Essence : out<<"Essence"<<endl;break;
    case Hybride : out<<"Hybride"<<endl;break;
    }
    cout<<"Tarif: ";
    out<<v.tarif<<endl;
    cout<<"etat Roues: ";
    out<<afficheValide(v.etatRoues)<<endl;
    cout<<"etat Carosserie: ";
    out<<afficheValide(v.etatCarosserie)<<endl;
    cout<<"etat direction: ";
    out<<afficheValide(v.etatDirection)<<endl;
    cout<<"etat Frein: ";
    out<<afficheValide(v.etatFrein)<<endl;
    cout<<"etat Feux: ";
    out<<afficheValide(v.etatFeux)<<endl;

}
istream& operator>>(istream& in, Vehicule& v)
{
    int t;
    cout<<"entrer votre matricule"<<endl;
    in>>v.matricule;
    cout<<"entrer votre marque"<<endl;
    in>>v.marque;
    cout<<"entrer l'age du vehicule"<<endl;
    in>>v.age;
    //cout<<"entrer le nombre des roues"<<endl;
    //in>>v.nbRoues;
    cout<<"entrer le type de consommation"<<endl;
    do{
        cout<<"\t 1 : Diesel "<<endl;
        cout<<"\t 2 : Electrique "<<endl;
        cout<<"\t 3 : Essence "<<endl;
        cout<<"\t 4 : Hybride "<<endl;
        cin>>t;
        switch(t)
        {
            case 1 : v.typeCons=Diesel;break;
            case 2 : v.typeCons=Electrique;break;
            case 3 : v.typeCons=Essence;break;
            case 4 : v.typeCons=Hybride;break;
        }
    }while(t <0 || t>4);
    return in;
}
ostream& operator<<(ostream& out, Vehicule* v)
{
    out<<v->matricule<<endl;
    out<<v->marque<<endl;
    out<<v->nbRoues<<endl;
    out<<v->age<<endl;
    if(v->typeCons == Diesel )
        out<<"Diesel"<<endl;
    else
        if(v->typeCons==Electrique)
            out<<"Electrique"<<endl;
        else
            if(v->typeCons==Essence)
                out<<"Essence"<<endl;
            else
                out<<"Hybride"<<endl;

    out<<v->tarif<<endl;
    out<<v->etatRoues<<endl;
    out<<v->etatCarosserie<<endl;
    out<<v->etatDirection<<endl;
    out<<v->etatFeux<<endl;
    out<<v->etatFrein<<endl;
/*
    out<<v->matricule<<endl;
    out<<v->marque<<endl;
    out<<v->age<<endl;
    switch(v->typeCons){
    case Diesel : out<<"Diesel"<<endl;break;
    case Electrique : out<<"Electrique"<<endl;break;
    case Essence : out<<"Essence"<<endl;break;
    case Hybride : out<<"Hybride"<<endl;break;
    }
    out<<v->tarif<<endl;
*/
    return out;
}
istream& operator>>(istream& in, Vehicule* v)
{
    string ch;
    int e;
    in>>v->matricule;
    in>>v->marque;
    in>>v->nbRoues;
    in>>v->age;
    in>>ch;
        if( ch == "Diesel" )
        v->typeCons = Diesel;
    else
        if(ch=="Electrique")
            v->typeCons=Electrique;
        else
            if(ch=="Essence")
                v->typeCons=Essence;
            else
                v->typeCons=Hybride;

    in>>v->tarif;
in>>v->etatRoues;
    in>>v->etatCarosserie;
    in>>v->etatDirection;
    in>>v->etatFeux;
    in>>v->etatFrein;
   //cout<<"nbRoures"<<v->nbRoues;
    return in;
}


Vehicule::~Vehicule()
{
    //dtor
}
