#ifndef PERSONNE_H
#define PERSONNE_H
#include "MyExceptions.h"
#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include"Date.h"
#include"Reservation.h"
//#include"CentreVT.h"
using namespace std;
class CentreVT;
class Personne
{
    protected:
    int cn;
    string email;
    string mdp;
    string nom;
    string prenom;
    int numTel;
    Date dateNaiss;
    vector<string*> professions;
    public:
        personne(int cn,string email,string mdp)
        {
            this->cn=cn;
            this->email= email;
            this->mdp=mdp;
        }
        Personne();
        Personne& operator=(const Personne& p);
        Personne(const Personne& p);
        virtual void sinscrire(CentreVT&)=0;
        virtual void authentifier(CentreVT&)=0;
        virtual void modifierD(CentreVT&)=0;
        int getcn(){return cn;};
        string getmdp(){return mdp;};
        string getEmail(){return email;};
        string getNomP(){
        return this->nom +" " + this->prenom ;
        }
        void ajouterProfession(string* p){
        professions.push_back(p);}
        vector<string*> getProfessions(){
        return professions;
        }
        friend ostream& operator<<(ostream& out, Personne& P);
        friend istream& operator>>(istream& in, Personne& P);
        friend ostream& operator<<(ostream& out, Personne* P);
        friend istream& operator>>(istream& in, Personne* P);
        virtual ~Personne();
};

#endif // PERSONNE_H
