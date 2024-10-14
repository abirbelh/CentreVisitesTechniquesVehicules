#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <iostream>
#include <fstream>
#include<stack>
#include"CentreVT.h"
#include"Date.h"
#include"TimeDate.h"
using namespace std;
class CentreVT;
class Equipement
{
    string rf;
    string libelle;
    int quantite;
    stack<TimeDate*> modeff;
    public:
        Equipement();
        Equipement(string,string,int);
        friend istream& operator>>(istream& in,Equipement* E);
        friend istream& operator>>(istream& in,Equipement& E);
        friend ostream& operator<<(ostream& out,const Equipement& E);
        friend ostream& operator<<(ostream& out,const Equipement* E);
        void ajouterEq(CentreVT& );
        void suppEq(string,CentreVT&);
        void modifierEq(string,CentreVT&);
        void afficherEq(CentreVT&);
        virtual ~Equipement();
    friend class Agent;
};

#endif // EQUIPEMENT_H
