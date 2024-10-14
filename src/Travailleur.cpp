#include "Travailleur.h"

Travailleur::Travailleur()
{
    //ctor
}

void Travailleur::ajouter(string* sp){
specialites.push_back(sp);
}

void Travailleur::modifier(string* sp){
    list<string*>::iterator it;
    for (it = specialites.begin(); it != specialites.end(); ++it) {
        if(*it == sp)
            *it=sp;
    }
}
void Travailleur::supprimer(string* sp){
    specialites.remove(sp);
}

Travailleur::~Travailleur()
{
    //dtor
}
