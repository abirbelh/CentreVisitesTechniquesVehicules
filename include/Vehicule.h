#ifndef VEHICULE_H
#define VEHICULE_H
#include <iostream>
#include <vector>
#include "TypeConsommation.h"
#include"string"
#include "MyExceptions.h"
#include<iomanip>
using namespace std;

class Vehicule
{
    protected:
    string matricule;
    string marque ;
    int age ;
    TypeConsommation typeCons ;
    int nbRoues ;
    float tarif;
    vector<string*> proprietaires;
   // string* proprietaires;
    bool etatRoues=true;
    bool etatFeux=true;
    bool etatFrein=true;
    bool etatCarosserie=true;
    bool etatDirection=true;
    public:
        Vehicule(){};
        Vehicule(string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,float tarif,bool etatFeux=true,bool etatFrein=true,bool etatCarosserie=true,bool etatDirection=true);
        virtual ~Vehicule();
        friend ostream& operator<<(ostream&, Vehicule&);
        friend istream& operator>>(istream&, Vehicule&);
        friend istream& operator>>(istream&, Vehicule*);
        friend ostream& operator<<(ostream&, Vehicule*);
        virtual void affiche();
        virtual void saisie();
        void changeEtatRoues(){ etatRoues = false;}
        void changeEtatCarosserie(){etatCarosserie = false;}
        void changeEtatFeux(){etatFeux = false;}
        void changeEtatFrein(){etatFrein = false;}
        void changeEtatDirection(){etatDirection = false;}
        void ajouterProprietaire(string* p){
        proprietaires.push_back(p);}
        vector<string*> getProprietaire(){
        return proprietaires;
        }

    protected:

    private:
};

#endif // VEHICULE_H
