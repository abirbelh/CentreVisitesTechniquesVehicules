#include "Agent.h"

Agent::Agent()
{
    //ctor
}

Agent::Agent(const Agent& ag) {
    *this=ag;
    listVisites = ag.listVisites;

}
void Agent::menuAgent(CentreVT* c){
    Exterieur testExt;
    Interieur testInt;
    bool etatExt,etatInt;
     int ad,cd;
     string rf;
     char verif;
     bool tst=false;
     VisiteTech * vt;
        cout<<"\n********Espace Agent*******\n"<<endl;
        authentifier(*c);
        //cin>>*this;
cout << "Bienvenue Cher Agent "<<getNomP()<<endl;

 do{
             try
            {
        cout<<"_________________________"<<endl;
         cout << "1: rechercher un equipement" <<endl;
         cout <<"2: Consulter la liste des equipements" <<endl;
         cout<<"3: Consulter ma liste des visites"<<endl;
         cout<<"4: accéder à une visite"<<endl;
         cout <<"5: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>ad;
         if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(ad)
         {
             case 1:
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 rechEq(rf,*c);break;
             case 2 :ConsulterEq(*c) ;break;
             case 3:consulterVisites();break;
             case 4:
                do{
                cout<<"entrer le code de la visite"<<endl;
                 cin>>cd;
                 for(unsigned int i=0;i<listVisites.size();i++)
                    if(cd==listVisites[i]->getCode())
                       {
                            tst=true;
                          vt = listVisites[i];
                          break;
                       }
                cout<<"code Introuvable"<<endl;
                }while(!tst);
                cout<<*vt;
                cout<<"Commencer la visite"<<endl;
                        testExt.testCarrosserie(vt->res->v);
                        testExt.testFeux(vt->res->v);
                        testExt.testRoues(vt->res->v);
                        testInt.testDirection(vt->res->v);
                        testInt.testFrein(vt->res->v);
                        vt->test.push_front(&testInt);
                        vt->test.push_front(&testExt);
                        cout << "\n Les etats de votre vehicule Apres la visite: \n";
                        etatExt = testInt.getEtatFinal();
                        etatInt = testInt.getEtatFinal();
                        if(etatInt == false || etatExt == false)
                            vt->setEtatFinal(false);
                    break;

         }
         }catch(runtime_error& e)
        {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while(ad!=5);

}
ostream& operator<<(ostream& out,Agent& ag){
    Personne *p=&ag;
    out<<*p;
    cout<<"Poste : "<<ag.poste<<endl;
    cout<<"Liste des visites"<<endl;
        if(ag.listVisites.size()==0)
            cout<<"aucune visite affectee"<<endl;
        else
        for(unsigned int i=0;i<ag.listVisites.size();i++)
            out<<*ag.listVisites[i];

}
istream& operator>>(istream& in,Agent& A)
{
    Personne *P=&A;
    in>>*P;
    cout<<"poste :";
    getline(in,A.poste);
}

//ostream& operator<<(ostream&, Agent&);
void Agent::sinscrire(CentreVT& C)
{
   char rep;
    do{
        Agent *A=new Agent();
        cin>>*A;
        C.personnes.push_back(A);
        cout<<"ajouter un agent"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');
}
void Agent::authentifier(CentreVT& C)
{
    string mdp;
    Agent A;
    int cn;
    char choix;
    bool cnCorr= false;
    bool auth=false;
    while(!auth)
    {
        cout<<"entrez votre cin"<<endl;
        cin>>cn;
        cout<<"entrez votre mot de passe "<<endl;
        cin>>mdp;
        for(unsigned i=0;i<C.personnes.size();i++)
        {
            cnCorr=true;
            if(cn==C.personnes[i]->getcn())
            {
                if(mdp.compare(C.personnes[i]->getmdp())==0)
                {
                    cout<<"vous etes connecte avec succes "<<endl;
                    Agent* ag = new Agent(static_cast<const Agent&>(*C.personnes[i]));
                    *this = *ag;
                    auth=true;
                    break;
                }
                else
                {
                    cout<<"mot de passe incorrect !"<<endl;
                    break;
                }
            }
        }
        if(!cnCorr){
            cout<<"cn introuvable !"<<endl;
            cout<<"Taper 'r' pour retourner et 'c' pour continuer"<<endl;
            cin>>choix;
            if((choix == 'r' )|| (choix == 'R'))
                throw MyExceptions("erreur d'authentification");
        }

    }
}
void Agent::ConsulterEq(CentreVT& C)
{
    for(unsigned i=0;i<C.equipements.size();i++)
        cout<<C.equipements[i]<<'\t';
}
Equipement& Agent::rechEq(string rf, CentreVT& C)
{
    Equipement E("","",0);
    bool trouver=false;
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        if(rf==C.equipements[i]->rf)
        {
            return *C.equipements[i];
            trouver=true;
            break;
        }
    }
    if(trouver==false)
    {
        cout<<"equipement introuvable !"<<endl;
        return E;
    }
}
void Agent::modifierD(CentreVT& C)
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
/*void Agent::validerEtatVisite(VisiteTech vt,Vehicule* v)
{
    if(vt.testExt.getEtat()==false || vt.testInt.getEtat()==false)
        vt.etatTest = false;


}*/
void Agent::consulterVisites(){
cout<<"vous avez au total "<<listVisites.size()<<" visite(s)"<<endl;
for(unsigned int i=0;i<listVisites.size();i++)
    cout<<*listVisites[i];
}
Agent::~Agent()
{
    //dtor
}

