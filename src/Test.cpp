#include "Test.h"

Test::Test()
{
    //ctor
}
void Test::ajouterEtatTest(string nom,bool* e){
etatsTest.insert(pair<string,bool*>(nom, e));
}
void Test::modifierEtat(string nom){

}
void Test::supprimerEtat(string nom){
}
void Test::affichierEtats(){
    multimap<string, bool*>::iterator it;
    if(etatsTest.size()==0)
        cout<<"Vous n'avez pas encore fait la visite"<<endl;
    else{
    for (it = etatsTest.begin(); it != etatsTest.end(); ++it) {
        cout <<"\t etat "<<it->first <<" : "<<it->second<<endl;
    }
    }
}
bool Test::getEtatFinal(){
    bool etatFinal = true;
        multimap<string, bool*>::iterator it;
    for (it = etatsTest.begin(); it != etatsTest.end(); ++it) {
        if(*it->second == true)
            cout <<"\t etat "<<it->first <<" : "<<" valide "<<endl;
        else{
            cout <<"\t etat "<<it->first <<" : "<<" INvalide "<<endl;
            etatFinal=false;
        }

    }
    return etatFinal;


}
Test::~Test()
{
    //dtor
}
