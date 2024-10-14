#include "CentreVT.h"

//#include"Client.h"
CentreVT::CentreVT()
{
    //ctor
}
void CentreVT::creer(fstream &f)
{    f.open( "C:\CentreVT.txt", ios ::out| ios ::in |ios ::trunc) ;
     if( !(f.is_open()))
        exit(-1);
}
ostream& operator<<(ostream& out,CentreVT& C)
{
    out<<C.nom<<endl;
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        out<<*C.equipements[i]<<endl;
    }
    for(unsigned i=0;i<C.personnes.size();i++)
    {
        out<<*C.personnes[i]<<endl;
    }
    return out;
}
ostream& operator<<(ostream& out,CentreVT* C)
{
    out<<C->nom<<endl;
     for (int i=0; i<C->equipements.size(); i++)
            out<<*C->equipements[i]<<endl;


     for(int i=0;i<C->personnes.size();i++)
        {
            if(typeid(*C->personnes[i])==typeid(Personne))
                    out<<"1"<<*C->personnes[i]<<endl;
       /*   else if(typeid(*C->personnes[i])==typeid(Agent))
                    out<<"2"<<static_cast<Agent&>(*C->personnes[i])<<endl;
            else if(typeid(*C->personnes[i])==typeid(Client))
                    out<<"3"<<static_cast<Client&>(*C->personnes[i])<<endl;*/
        }
    /* for(int i=0;i<C->visites.size();i++)
        out<<*c.visites[i]<<endl;*/
     return out;
}
istream& operator>>(istream& in,CentreVT* C)
{   int choix;
    in.seekg(0);
    getline(in,C->nom,'\n');
    int i=0;
    while(1)
    {
        if(in.eof())break;
        Equipement * E = new Equipement() ;
        in>>*E;
        C->equipements.push_back(E);
    }
    return in;
}

VisiteTech* CentreVT::ajouterVisite(Reservation* r){
VisiteTech* v = new VisiteTech();
v->setRes(r);
visites.push_back(v);
return v;
}

void CentreVT::creerFichierPersonne(fstream &f)
{
 f.open("Personnes.txt",ios::in | ios::out | ios::trunc);
 if (!f) cout<<"Erreur Fichier";
}


void CentreVT::enregistrerPers(Personne* p)
{
 ofstream Fichier("Personnes.txt",ios::app);
 if (!Fichier) cout<<"Erreur Fichier";
 Fichier<<p;
Fichier.close();
}

void CentreVT::recupererPers()
{
 ifstream Fichier("Personnes.txt",ios::app);
 if (!Fichier) cout<<"Le fichier n'existe pas ";
string ch;
 while(1)
 {
/* Personne* p=new Personne();
    cout<<"etape1";
   Fichier>>p;*/
    Fichier>>ch;
         if(ch=="Agent")
{
    Agent* ag =new Agent();
    Fichier>>ag;
    personnes.push_back(ag);
    //p=ag;
}

else
    if(ch=="Admin")
        {
        Admin* ad =new Admin();
       Fichier>>ad;
       personnes.push_back(ad);
        //p=ad;
        }
    else if(ch=="Client")
    {

        Client* clt =new Client();
        Fichier>>clt;
        personnes.push_back(clt);
        //p=clt;
    }
   if(Fichier.eof()) break;
}
//cvt->consulterVisite();
Fichier.close() ;
}

void CentreVT::reloadPers(){
fstream f;
 creerFichierPersonne(f);
 f.clear();
for(unsigned int i=0;i<personnes.size();i++)
 {

   f<<personnes[i];
}
}
void CentreVT::afficherListPersonne(){
for(int i=0;i<personnes.size();i++)
    if(typeid(*personnes[i])==typeid(Agent)){
        cout<<"-----AGENT------"<<endl;
        cout<<static_cast<Agent&>(*personnes[i])<<endl;
    }else if (typeid(*personnes[i])==typeid(Admin)){
        cout<<"-----ADMIN------"<<endl;
        cout<<static_cast<Admin&>(*personnes[i])<<endl;
    }else if (typeid(*personnes[i])==typeid(Client)){
        cout<<"-----Client------"<<endl;
        cout<<static_cast<Client&>(*personnes[i]);
    }
}


CentreVT::~CentreVT()
{
    //dtor
}

