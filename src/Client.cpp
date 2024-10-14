#include "Client.h"

Client::Client()
{
    //ctor
}
int Client::getCin(){
    return this->cn ;
}
Client::Client(const Client& clt) : Personne(clt) {
    this->listRes = clt.listRes;
    this->MapVisites = clt.MapVisites;
}
vector<Reservation> Client::getList()
{
    vector<Reservation> tab;
    for(unsigned i=0;this->listRes.size();i++)
        tab.push_back(this->listRes[i]);
    return tab;
}
Client& Client::operator=(const Client& clt) {
    if (this != &clt) {
        Personne::operator=(clt);
        this->listRes = clt.listRes;
        this->MapVisites = clt.MapVisites;
    }
    return *this;
}
ostream& operator<<(ostream& out, Client* c)
{
    Personne *p =c;
    //out<<p;
   /* for(int i=0;i<c->listRes.size();i++)
    out<<&c->listRes[i]<<endl;*/
    return out;
}
istream& operator>>(istream& in, Client* c)
{
    Personne *p=c;
    in>>p;
   /* for(int i=0;i<c->listRes.size();i++)
    in>>&c->listRes[i];*/
    return in;
}

void Client::menuClient(CentreVT* cvt){
    int cl,c;
        cout<<"\n********Espace Client*******\n"<<endl;
        do{
        cout<<"1: S'authentifier "<<endl;
        cout<<"2: Creer un compte"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>c ;
        if(c == 1)
        try{
        authentifier(*cvt);
        //cin>>*this;
        break;
        }catch(MyExceptions e){}
    else
        if(c == 2)
            try{
         sinscrire(*cvt);
         break ;
        }catch(exception const &e)
        {
            cerr<<"ERREUR: "<<e.what()<<endl;
        }
    }while(this);
cout << "Bienvenue Cher Client "<<getNomP()<<endl;
//consulterRes();
//cout<<*this;
    //do{
    do{
    try
    {
        cout<<"_________________________"<<endl;
         cout << "1: Effectuer une reservation" <<endl;
         cout << "2: Annuler une reservation" <<endl;
         cout << "3: Modifier une reservation" <<endl;
         cout << "4: Consulter votre liste des reservations" <<endl;
         cout << "5: Modifier ses donnees" <<endl;
         cout << "6: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>cl;
        if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(cl)
         {
             case 1 : effectuerRes(cvt);break;
             case 2 : supprimerRes();break;
             case 3 : modifierRes();break;
             case 4 : consulterRes();break;
             case 5 : modifierD(*cvt);break;
         }

    }catch(runtime_error& e)
    {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    }while(cl!=6);
cvt->reloadPers();
}
void Client::authentifier(CentreVT& C)
{
    string email,mdp;
    Client c;
    char choix;
    bool cnCorr= false;
    bool auth=false;
    while(!auth)
    {
        cout<<"entrez votre email"<<endl;
        cin>>email;
        cout<<"entrez votre mot de passe "<<endl;
        cin>>mdp;
        for (unsigned i = 0; i < C.personnes.size(); i++)
        {
            cnCorr = true;
            Client* clt = dynamic_cast<Client*>(C.personnes[i]);
            if (clt != nullptr && email == clt->getEmail())
            {
                if (mdp.compare(clt->getmdp()) == 0)
                {
                    cout << "vous etes connecte avec succes " << endl;
                    Client* cl = new Client(static_cast<const Client&>(*C.personnes[i]));
                    *this = *clt;
                    auth = true;
                    break;
                }
                else
                {
                    cout << "mot de passe incorrect !" << endl;
                    break;
                }
            }
        }
        if (!cnCorr)
        {
            cout << "cn introuvable !" << endl;
            cout << "Taper 'r' pour retourner ou 'c' pour continuer" << endl;
            cin >> choix;
            if ((choix == 'r') || (choix == 'R'))
                throw MyExceptions("erreur d'authentification");
        }
    }
}
void Client::modifierD(CentreVT& C)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le cin de la personne a modifier "<<endl;
    cin>>this->cn;
    while(i<C.personnes.size()) //modifier la condition de while.
    {
        if(this->cn==C.personnes[i]->getcn())
        {
            cin>>*C.personnes[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"personne non trouve !"<<endl;

}


void Client::sinscrire(CentreVT& c)
{
    int nbP =0,codeCIN;
    do{
    Client* clt = new Client();
        cin>>*this;
        codeCIN = cn;
        nbP = count_if(c.personnes.begin(), c.personnes.end(),[codeCIN](Personne* p) { return p->getcn() == codeCIN; });
        if(nbP!=0)
            {
                cout<<"cin doit etre unique"<<endl;
            }else{
        //clt=this;
        c.personnes.push_back(this);
        c.enregistrerPers(this);
        cout<<"compte creer avec succees"<<endl;
        cout<<*c.personnes[0];}
    }while(nbP!=0);
}

//******************** AFFICHER LES RESERVATIONS *************************** //

void Client::consulterRes(){
    int i;
    cout<<"la liste des reservations"<<endl;
    cout<<"vous avez au total "<<listRes.size()<< " reservation(s)"<<endl;
for(unsigned int i=0;i<listRes.size();i++)
{
    cout<<"------- RESERVATION NUM"<<i+1<<" -------"<<endl;
    cout<<listRes[i];
}

}

//******************** EFFECTUER UNE RESERVATION *************************** //

void Client::effectuerRes(CentreVT* cvt){
    Reservation* r=new Reservation();
    VisiteTech* v;
    try{
    do{
    cin>>*r;
    }while(existDate(r->getDate(),r->getHeure()));

    }catch(exception const &e)
    {
            cerr<<"ERREUR: "<<e.what()<<endl;
    }
    v=cvt->ajouterVisite(r);
    MapVisites.ajouterElement(r->getCodeR(),*v);
    listRes.push_back(*r);
    enregistrer(*r);
}

//******************** SUPPRIMER UNE RESERVATION *************************** //

void Client::supprimerRes()
{
    int cd;
    if(listRes.size()==0) cout<<"vous n'avez pas des reservations"<<endl;
    else{
    cout<<"Entrer le code du reservation a supprimer"<<endl;
    cin>>cd;
    for(int i=0;i<listRes.size();i++)
    {
        if(listRes[i].getCodeR()==cd)
        {
            listRes.erase(listRes.begin()+i);
            reload();
            cout<<"suppression effectuer avec sucees"<<endl;
            return;
        }

    }
    cout<<"code introuvable"<<endl;
    }
}


void Client::modifierRes(){
    //vector<Reservation> L;
    int i=0,rf;
    bool trouver=false;
    cout<<"entrer le code de reservation a modifie"<<endl;
    cin>>rf;
    for(int i=0;i<listRes.size();i++)
    {
        if(rf==listRes[i].getCodeR())
        {
            listRes[i].modifierRes();
            trouver = true;
        }
    }
    if(trouver==false)
        cout<<"Reservation introuvable !"<<endl;
    else
        cout<<"modification terminee"<<endl;

reload();
}
bool Client::existDate(Date d,int h)
{
    for(unsigned int i=0;i< listRes.size();i++)
        if((listRes[i].getDate() == d )&&(listRes[i].getHeure()==h))//TESTER DATE ET HEURE,
        {
          cout<<"date indisponible"<<endl;
          cout<<"on a une autre réservation la meme date a "<<listRes[i].getHeure()<<" H"<<endl;
          return true;
        }else
        {
          cout<<"date disponible Vous etes la bienvenue"<<endl;
          cout<<"votre réservation est le "<<d<<" a "<<h<<"H"<<endl;
          return false;
        }

}


//******************** FICHIER *************************** //

void Client::creer(fstream &f)
{
 f.open("Reservations.txt",ios::in | ios::out | ios::trunc);
 if (!f) cout<<"Erreur Fichier";
}


void Client::enregistrer(Reservation r)
{
 ofstream Fichier("Reservations.txt",ios::app);
 if (!Fichier) cout<<"Erreur Fichier";
 Fichier<<&r;
Fichier.close();
}

void Client::recuperer(CentreVT* cvt)
{
 ifstream Fichier("Reservations.txt",ios::app);
 if (!Fichier) cout<<"Le fichier n'existe pas ";

 while(1)
 {
 Reservation* r=new Reservation();
   Fichier>>r;
   //cout<<*r;
   if(Fichier.eof()) break;
//Fichier>>ws;
//r.getDate().affiche();
cvt->ajouterVisite(r);
 listRes.push_back(*r);
}
//cvt->consulterVisite();
Fichier.close() ;
}

void Client::reload()
{
fstream f;
 creer(f);
 f.clear();

for(unsigned int i=0;i<listRes.size();i++)
 {
   f<<&listRes[i];
}
f.close() ;
}

//******************** SURCHARGE DES OPERATEURS *************************** //

ostream& operator<<(ostream& out, Client& c)
{
    Personne *p=&c;
    out<<*p;
     for(unsigned int i=0;i< c.listRes.size();i++)
        out<<c.listRes[i];

}
istream& operator>>(istream& in, Client& c)
{
    Personne *p=&c;
    in>>*p;
   /* for(unsigned int i=0;i< c.listRes.size();i++)
        in>>c.listRes[i];*/
}

template<class K, class V>
void ElementsMap<K, V>::ajouterElement(const K& cle, const V& valeur) {
    elements.insert(make_pair(cle, valeur));
}


Client::~Client()
{
    //dtor
}
