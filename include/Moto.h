#ifndef MOTO_H
#define MOTO_H
#include<stack>
#include <Vehicule.h>


class Moto : public Vehicule
{
    stack<int*> visiteEff2;
    public:
        Moto();
        virtual ~Moto();
        void affiche();
        void saisie();
        stack<int*> getVE2();
        friend istream& operator>>(istream&, Moto&);
    protected:

    private:
};

#endif // MOTO_H
