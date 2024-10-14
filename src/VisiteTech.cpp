#include "VisiteTech.h"

int VisiteTech::nbVisite = 0;

VisiteTech::VisiteTech()
{
    nbVisite++;
    codeV=nbVisite;
    etatTestFinal=true;
}

VisiteTech::VisiteTech(const VisiteTech & v)
{
    list<Test*>::iterator it;
    list<Test*> t;
    codeV=v.codeV;
for(auto it = v.test.begin(); it!=v.test.end(); ++it)
{
    Test* te = new Test(**it);
    t.push_front(te);
}
    test=t;
    etatTestFinal=v.etatTestFinal;
    res=v.res;

}
VisiteTech& VisiteTech::operator=(const VisiteTech & v)
{
list<Test*>::iterator it;
list<Test*> t;
if(this!=&v)
{
delete[]v.res;
test.clear();

codeV=v.codeV;
for(auto it = v.test.begin(); it!=v.test.end(); ++it)
{
    Test* te = new Test(**it);
    t.push_front(te);
}
    test=t;
etatTestFinal=v.etatTestFinal;
res=v.res;
}
return *this;
}

ostream& operator<<(ostream& out,const VisiteTech& v)
{
    out<<"code : "<<v.codeV<<endl;
    out<<"test"<<endl;
    out<<v.etatTestFinal<<endl;
    out<<*(v.res)<<endl;
          return out;
}
istream& operator>>(istream& in, VisiteTech& V)
{
    cout<<"code"<<endl;
    in>>V.codeV;

}
void VisiteTech::modifierVisite(CentreVT C,string code)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le code de la visite a modifier "<<endl;
    cin>>this->codeV;
    while(i<C.visites.size())
    {
        if(this->codeV==C.visites[i]->codeV)
        {
            cin>>*C.visites[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"visite non trouve !"<<endl;

}

VisiteTech::~VisiteTech()
{
    //dtor
}
