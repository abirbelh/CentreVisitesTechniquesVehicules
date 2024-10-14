#include "Admin.h"

Admin::Admin()
{
    //ctor
}

ostream& operator<<(ostream& out,Admin& ad){
    Personne *p=&ad;
    out<<*p;
   /* cout<<"Poste : "<<ag.poste<<endl;
    cout<<"Liste des visites"<<endl;
        if(ag.listVisites.size()==0)
            cout<<"aucune visite affectee"<<endl;
        else
        for(unsigned int i=0;i<ag.listVisites.size();i++)
            out<<*ag.listVisites[i];*/

}
istream& operator>>(istream& in,Admin& A)
{
    Personne *P=&A;
    in>>*P;
    /*cout<<"poste :";
    getline(in,A.poste);*/
}
/*bool compareVisitesPatDate(const VisiteTech* v1, const VisiteTech* v2) {
    return v1->getDate() < v2->getDate();
}*/

void Admin::consulterVisite(CentreVT& cvt){
cout<<"la liste des Visites Techniques :"<<endl;
cout<<"vous avez au total "<<cvt.visites.size()<< " visites(s)"<<endl;
//sort(cvt.visites.begin(), cvt.visites.end(), compareVisitesParDate);
sort(cvt.visites.begin(), cvt.visites.end(), [](VisiteTech* v1, VisiteTech* v2) {
    return v1->getDate() < v2->getDate();
});
for(unsigned int i=0;i<cvt.visites.size();i++)
{
    cout<<"------- Visite NUM"<<i+1<<" -------"<<endl;
    cout<<*cvt.visites[i];
}

}

void Admin::affecterAgentsVisites(CentreVT& cvt){
int nb,j=0;;
nb=nombreAgents(cvt);
if(nb==0)
    cout<<"vous devez avoir au minimum un agent"<<endl;
else{
for(unsigned int i=0;i<cvt.personnes.size();i++)
    if(typeid(*cvt.personnes[i])==typeid(Agent))
        {
            Agent* ag;
           ag=new Agent(static_cast<Agent&>(*cvt.personnes[i]));
            while(ag->getNbVisites()<(cvt.visites.size()/nb)){
                 ag->ajouterVisite(cvt.visites[j]);
                 j++;
                 cvt.personnes[i]=ag;
            }

        }
}
}
//error: invalid use of incomplete type 'class Agent'|
int Admin::nombreAgents(CentreVT& cvt){
int n=0;
for(unsigned int i=0;i<cvt.personnes.size();i++)
    if(typeid(*cvt.personnes[i])==typeid(Agent))
            n++;
return n;
}

void Admin::ajouterAgent(CentreVT& cvt){
char rep;
    do{
        Agent *A=new Agent();
        cin>>*A;
        cvt.personnes.push_back(A);
        cvt.enregistrerPers(A);
        cout<<"vous voulez ajouter un autre un agent(o/n)"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}

void Admin::afficherAgents(CentreVT& cvt){
for(unsigned int i=0;i<cvt.personnes.size();i++)
{
    //cout<<new Agent(static_cast<Agent&>(*personnes[i]));
    if(typeid(*cvt.personnes[i])==typeid(Agent))
    {
         Agent* ag=new Agent(static_cast<Agent&>(*cvt.personnes[i]));
        cout<<*ag;
    }

}
}
void Admin::sinscrire(CentreVT& C)
{
        cn=11;
        email="AA";
        mdp="11";
        dateNaiss = Date(22,12,2000);
        nom="Administrateur";
        prenom="Centre";
        numTel=54209618;
        C.personnes.push_back(this);
        C.enregistrerPers(this);
}
void Admin::authentifier(CentreVT& C)
{
    string mdp;
    Admin A;
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
        for (unsigned i = 0; i < C.personnes.size(); i++)
        {
            cnCorr = true;
            Admin* admin = dynamic_cast<Admin*>(C.personnes[i]);
            if (admin != nullptr && cn == admin->getcn())
            {
                if (mdp.compare(admin->getmdp()) == 0)
                {
                    cout << "vous etes connecte avec succes " << endl;
                    Admin* ad = new Admin(static_cast<const Admin&>(*C.personnes[i]));
                    *this = *ad;
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


/*void Admin::ajouterAdmin(CentreVT& cvt){
char rep;
    do{
        Admin *A=new Admin();
        cin>>*A;
        cvt.personnes.push_back(A);
        cout<<"vous voulez ajouter un autre admin(o/n)"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}*/

Admin::~Admin()
{
    //dtor
}
