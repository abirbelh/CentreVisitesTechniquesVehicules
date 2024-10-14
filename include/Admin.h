#ifndef ADMIN_H
#define ADMIN_H
#include "CentreVT.h"
#include <vector>
#include "Personne.h"
#include "Travailleur.h"
using namespace std;

class Admin: public Personne , public Travailleur
{
    vector<string*> roles;
    public:
        Admin();
        virtual ~Admin();
        void consulterVisite(CentreVT&);
        void affecterAgentsVisites(CentreVT&);
        void ajouterAgent(CentreVT&);
        void afficherAgents(CentreVT&);
        int nombreAgents(CentreVT&);
        void sinscrire(CentreVT&);
        void authentifier(CentreVT&);
        void modifierD(CentreVT&){}
        void ajouterR(string* r)
        {
            roles.push_back(r);
        }
        void modifierR(string* r)
        {
            for(int i=0;i<roles.size();i++)
                if(*r == *roles[i])
                    roles.at(i) = r;
        }
        void supprimerR(string* r)
        {
            for(int i=0;i<roles.size();i++)
                if(*r == *roles[i])
                    roles.erase(roles.begin() + i);
        }
        friend istream& operator>>(istream& ,Admin&);
        friend ostream& operator<<(ostream&,Admin&);

    protected:

    private:
};

#endif // ADMIN_H
