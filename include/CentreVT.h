#ifndef CENTREVT_H
#define CENTREVT_H
#include<Agent.h>
#include<Admin.h>
#include<Client.h>
//#include<Reservation.h>
//#include<string>
//#include <vector>
//#include"Personne.h"
//#include"VisiteTech.h"
//#include "Equipement.h"
#include <fstream>

using namespace std;

class Agent;
class VisiteTech;
class Personne;
class Equipement;
class CentreVT
{
    string nom="Centre Abir et Asma";
    vector <VisiteTech*> visites;
    vector <Personne*> personnes;
    vector <Equipement*> equipements;
    public:
        CentreVT();
        virtual ~CentreVT();
        static void creer(fstream&);
        friend ostream& operator<<(ostream& out,CentreVT& C);
        friend ostream& operator<<(ostream& out,CentreVT* C);
        friend istream& operator>>(istream& in,CentreVT* C);
        VisiteTech* ajouterVisite(Reservation* r);
        void enregistrerPers(Personne*);
        void recupererPers();
        void creerFichierPersonne(fstream &);
        void afficherListPersonne();
        void reloadPers();

       /* void consulterVisite();
        void affecterAgentsVisites();
        void ajouterAgent();
        void afficherAgents();
        int nombreAgents();*/

    friend class Equipement;
    friend class Personne;
    friend class Agent;
    friend class Client;
    friend class VisiteTech;
    friend class Admin;

};

#endif // CENTREVT_H
