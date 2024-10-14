#include "Exterieur.h"

Exterieur::Exterieur()
{
    //ctor
}
char confirmer()
{
    char t;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer n"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='n'));
    return t;
}
bool Exterieur::testCarrosserie(Vehicule* v)
{
    char t;
    bool* e;
    cout<<"\n********** Tester la carrosserie **********"<<endl;
    t=confirmer();
    if(t=='n'){
    v->changeEtatCarosserie();
    *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Carrosserie",e);
    return *e;
}
bool Exterieur::testFeux(Vehicule* v)
{
        char t;
        bool*e;
    cout<<"\n********** Tester Feux **********"<<endl;
    t=confirmer();
    if(t=='n'){
     v->changeEtatFeux();
     *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Feux",e);
    return *e;
}
bool Exterieur::testRoues(Vehicule* v)
{
Voiture *vt;
    Moto m;
    Camion*c;
    char t;
    bool*e;
    if(typeid(*v) == typeid(Camion))
        {
    cout<<"\n---------- Tester les roues ----------\n"<<endl;
    cout<<"********** Tester roue Supplementaire **********\n"<<endl;
    t=confirmer();
    if(t=='n'){
     static_cast<Camion*>(v)->changeEtatRoueSupp();
     *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Roues Supplementaires",e);
    }
    cout<<"********** Tester les roues normal **********"<<endl;
    t=confirmer();
    if(t=='n'){
    v->changeEtatRoues();
    *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Roues normals",e);
    return *e;
}

Exterieur::~Exterieur()
{
    //dtor
}
