#ifndef RESERVATION_H
#define RESERVATION_H

#include <time.h>
#include"Date.h"
#include"Vehicule.h"
#include"Moto.h"
#include"Voiture.h"
#include"Camion.h"
#include<limits>
#include<iomanip>
#include <string.h>
#include<stack>
#include"TimeDate.h"
using namespace std;

class Client;
class Reservation
{
    static int nbInstance;
    int codeR;
    Date dateR;
    int heure;
    //float paiement;
    stack<TimeDate*> modifcationEff;
    Vehicule *v ;
    bool payee = false ;
    public:
        Reservation();
        friend ostream& operator<<(ostream&, Reservation&);
        friend istream& operator>>(istream&, Reservation&);
        friend istream& operator>>(istream&, Reservation*);
        friend ostream& operator<<(ostream&, Reservation*);
        void saisieRes();
       // void modifierRes(int,Client& );
        void modifierRes();
        void setPayee(){ payee = true ;}
        void setVehicule(Vehicule&);
        Date getDate(){return dateR;}
        int getHeure(){return heure;}
        int getCodeR(){return codeR;}
        Vehicule getVeh(){return *v;}
        Reservation(const Reservation &);
        Reservation & operator=(const Reservation &);
        friend class Agent;
        //virtual ~Reservation(){ delete []v;}


    protected:

    private:
};

#endif // RESERVATION_H
