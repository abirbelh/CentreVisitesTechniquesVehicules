#include "Camion.h"

Camion::Camion()
{
    tarif=30.0;
    nbRoues=4;
}

void Camion::affiche(){
    Vehicule::affiche();
    cout<<"charge: "<<charge<<endl;
    cout<<"nbRouesSupp: "<<nbRouesSupp<<endl;
    cout<<"etatRoueSupp: ";
    {
    if(etatRoueSupp==1)
        cout<<"valide "<<endl;
    else
        cout<<"non valide X"<<endl;
    if(!this->visiteEff1.empty())
   {
     cout<<"visite effectuee"<<endl;
     while(!this->visiteEff1.empty())
     {
         cout<<this->visiteEff1.top()<<endl;
         this->visiteEff1.pop();
     }
   }
}
}
void Camion::saisie(){
   Vehicule::saisie();
    cout<<"entrer le nombre de roue supplementaire"<<endl;
    cin>>nbRouesSupp;
    cout<<"entrer la charge du camion"<<endl;
    cin>>charge;
}
ostream& operator<<(ostream& out, Camion& c)
{
out<<c;
cout<<"charge: ";
out<<c.charge<<endl ;
cout<<"nombre de roues: ";
out<<c.nbRouesSupp<<endl ;
cout<<"etat roues :";
out<<c.etatRoueSupp<<endl;
if(!c.visiteEff1.empty())
   {
     cout<<"visite effectuee"<<endl;
     while(!c.visiteEff1.empty())
     {
         out<<c.visiteEff1.top()<<endl;
         c.visiteEff1.pop();
     }
   }
return out;
}
istream& operator>>(istream& in, Camion& c)
{
in>>c;
c.nbRoues=4;
cout<<"entrer la charge du camion"<<endl;
in>>c.charge;
cout<<"entrer le nombre des roues supp"<<endl;
in>>c.nbRouesSupp;
//c.charge=11.3;
return in;
}

ostream& operator<<(ostream& out, Camion* c)
{
    Vehicule *v =c;
    out<<v;
    out<<c->charge<<endl;
    out<<c->nbRouesSupp<<endl;
    out<<c->etatRoueSupp<<endl;

    return out;
}
stack<int*> Camion::getVE1()
{
    stack<int*> L;
    for(unsigned i=0;this->visiteEff1.size();i++)
       {
           L.push(this->visiteEff1.top());
           this->visiteEff1.pop();
       }
    return L;
}
istream& operator>>(istream& in, Camion* c)
{
     Vehicule *v=c;
    in>>v;
   in>>c->charge;
   in>>c->nbRouesSupp;
    in>>c->etatRoueSupp;
    return in;
}
Camion::~Camion()
{
    //dtor
}
