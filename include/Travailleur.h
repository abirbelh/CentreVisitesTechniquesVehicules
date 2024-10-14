#ifndef TRAVAILLEUR_H
#define TRAVAILLEUR_H

#include "list"
#include "string"
using namespace std;

class Travailleur
{
protected:
    list<string*> specialites;
    public:
        Travailleur();
        virtual ~Travailleur();
        void ajouter(string* sp);
        void modifier(string* sp);
        void supprimer(string* sp);

    protected:

    private:
};

#endif // TRAVAILLEUR_H
