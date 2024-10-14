#include <iostream>
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include"Date.h"
#include"Personne.h"
#include"Agent.h"
#include"Client.h"
#include"Equipement.h"
#include"exception"
#include"VisiteTech.h"
#include"CentreVT.h"
#include "Admin.h"
using namespace std;

int main()
{
    int esp,cnClient,cl,ad;
    Client clt,clnt,C;
    Agent ag;
    Admin admin,adm;
    Equipement e;
    CentreVT c,C1;
    string rf;
    c.recupererPers();
    clnt.recuperer(&c);
    //c.afficherListPersonne();


            do{
        cout<<"_________________________"<<endl;
        cout<<"1: Espace Client "<<endl;
        cout<<"2: Espace Agent"<<endl;
        cout<<"3: Espace Admin"<<endl;
        cout<<"_________________________"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>esp ;
    // ******** ESPACE CLIENT ***********
    if(esp == 1){
         clt.menuClient(&c);
      /*   cout<<"affVisite"<<endl;
         c.consulterVisite();*/
        esp=0;

    }
    // ******** ESPACE AGENT ***********
    else
        if(esp==2){
            ag.menuAgent(&c);
    esp=0;

    }
    // ******** ESPACE ADMIN ***********
    else{
            //adm.sinscrire(c);
            admin.authentifier(c);
            do{
             try
            {
        cout<<"_________________________"<<endl;
         cout << "1: Ajouter un equipement" <<endl;
         cout << "2: modifier un equipement" <<endl;
         cout <<"3: supprimer un equipement"<<endl;
         cout <<"4: Consulter la liste des equipements" <<endl;
         cout <<"5: Ajouter un agent" <<endl;
         cout <<"6: Consulter la liste des agents" <<endl;
         cout <<"7: Affecter les visites aux agents" <<endl;
         cout <<"8: Consulter tous les visites" <<endl;
         cout <<"9: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>ad;
         if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(ad)
         {
             case 1 : e.ajouterEq(c);break;
             case 2 :
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 e.modifierEq(rf,c);break;
             case 3 :
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 e.suppEq(rf,c);break;
             case 4 : e.afficherEq(c) ;break;
             case 5 : admin.ajouterAgent(c);break;
             case 6 :admin.afficherAgents(c);break;
             case 7: admin.affecterAgentsVisites(c);break;
             case 8: admin.consulterVisite(c);break;
         }
         }catch(runtime_error& e)
        {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while(ad!=9);
    esp=0;
    }

    }while(esp>4 || esp<1);
    return 0;
}
