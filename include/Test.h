#ifndef TEST_H
#define TEST_H
#include<map>
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class Test
{
    protected:
    multimap<string,bool*> etatsTest;
    public:
        Test();
        void ajouterEtatTest(string,bool*);
        void modifierEtat(string);
        void supprimerEtat(string);
        void affichierEtats();
        bool getEtatFinal();
        multimap<string,bool*> getEtatsTest(){
        return etatsTest;
        }
        friend ostream& operator<<(ostream& out, Test& T);
        virtual ~Test();
};

#endif // TEST_H
