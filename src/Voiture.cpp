#include "Voiture.h"

Voiture::Voiture()
{
    tarif=20.0;
    nbRoues=4;
}
void Voiture::affiche(){
    Vehicule::affiche();
      if(!this->visiteEff.empty())
   {
     cout<<"visite effectuee"<<endl;
     while(!this->visiteEff.empty())
     {
         cout<<this->visiteEff.top()<<endl;
         this->visiteEff.pop();
     }
   }
}
void Voiture::saisie(){
   Vehicule::saisie();
}

istream& operator>>(istream& in, Voiture& v)
{
in>>v;
}
ostream& operator<<(ostream& out, Voiture& v)
{
    Vehicule *Veh=&v;
    out<<*Veh;
    if(!v.visiteEff.empty())
   {
     out<<"visite effectuee"<<endl;
     while(!v.visiteEff.empty())
     {
         out<<v.visiteEff.top()<<endl;
         v.visiteEff.pop();
     }
   }
}
stack<int*> Voiture::getVE()
{
    stack<int*> L;
    for(unsigned i=0;this->visiteEff.size();i++)
       {
           L.push(this->visiteEff.top());
           this->visiteEff.pop();
       }
    return L;
}
Voiture::~Voiture()
{
    //dtor
}
