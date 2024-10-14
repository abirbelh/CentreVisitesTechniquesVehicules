#include "Interieur.h"

Interieur::Interieur()
{
    //ctor
}
char confirm()
{
    char t;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer n"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='n'));
    return t;
}
bool Interieur::testDirection(Vehicule* v)
{
    char t;
    bool*e;
    cout<<"\n********** Tester la direction **********"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatDirection();
    *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Direction",e);
    return * e;
}
bool Interieur::testFrein(Vehicule* v)
{
    char t;
    bool *e;
    cout<<"\n********** Tester les freins **********"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatFrein();
    *e=false;
    }else
    *e=true ;
    ajouterEtatTest("Freins",e);
    return *e;
}
Interieur::~Interieur()
{
    //dtor
}
