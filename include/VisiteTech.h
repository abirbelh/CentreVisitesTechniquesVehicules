#ifndef VISITETECH_H
#define VISITETECH_H

#include"CentreVT.h"
#include"Vehicule.h"
#include"Exterieur.h"
#include"Interieur.h"
#include "Reservation.h"
#include "list"
using namespace std;
//class CentreVT;

class VisiteTech
{
    static int nbVisite;
    int codeV;
    list<Test*> test;
    bool etatTestFinal;
    Reservation *res;

    public:
        VisiteTech();
        VisiteTech(const VisiteTech & v);
        VisiteTech& operator=(const VisiteTech & v);

        virtual ~VisiteTech();

        friend ostream& operator<<(ostream& out,const VisiteTech& V);
        friend istream& operator>>(istream& in, VisiteTech& V);

        void afficherVisite(Vehicule V);
        void modifierVisite(CentreVT,string);
        void saisiEtatInt(Vehicule*);
        void saisitEtatExt(Vehicule*);
        void setRes(Reservation* r){this->res=r;}
        Reservation getRes(){return *res;}
        int getCode(){return codeV;}
        Date getDate(){return res->getDate();}
        void setEtatFinal(bool e){
        etatTestFinal = e ;}
        friend class Test;
        friend class Reservation;
        friend class Agent;


};

#endif // VISITETECH_H
