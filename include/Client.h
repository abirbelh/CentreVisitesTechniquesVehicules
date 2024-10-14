#ifndef CLIENT_H
#define CLIENT_H
#include <fstream>
#include <iostream>
#include<string>
#include <Personne.h>
#include<cctype>
#include<limits>
#include"Date.h"
#include <vector>
#include "CentreVT.h"
#include "ElementsMap.h"
#include <VisiteTech.h>
#include <algorithm>
using namespace std;


class Client : public Personne
{    vector<Reservation> listRes ;
     ElementsMap<int,VisiteTech> MapVisites;
    public:
        Client();
        virtual ~Client();
        Client(const Client &);
        Client& operator=(const Client &);
        void menuClient(CentreVT*);
        void sinscrire(CentreVT&);
        void authentifier(CentreVT&);

        void modifierD(CentreVT&);
        void effectuerRes(CentreVT*);
        void consulterRes();
        void supprimerRes();
        void modifierRes();
       // Reservation & operator[](int);

        int getCin();
        vector<Reservation> getList();
        bool existDate(Date,int);
      //  void ajouterRes(Reservation&);
        void enregistrer(Reservation);
        void recuperer(CentreVT*);
        void creer(fstream &);
        void reload();
        friend ostream& operator<<(ostream&, Client&);
        friend istream& operator>>(istream&, Client&);
        friend ostream& operator<<(ostream&, Client*);
        friend istream& operator>>(istream&, Client*);

};

#endif // CLIENT_H
