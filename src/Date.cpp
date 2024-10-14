#include "Date.h"

Date::Date()
{
    //ctor
}
istream& operator>>(istream& in,Date& D)
{
    in>>D.jour;
    in>>D.mois;
    in>>D.annee;
    return in;
}
ostream& operator<<(ostream& out,Date& D)
{
    out<<D.jour<<"/";
    out<<D.mois<<"/";
    out<<D.annee<<endl;
    return out;
}
void Date::affiche()
{
    cout<<jour<<"/";
    cout<<mois<<"/";
    cout<<annee<<endl;
}
istream& operator>>(istream& in,Date* D)
{
    in>>D->jour;
    in>>D->mois;
    in>>D->annee;
    return in;
}
ostream& operator<<(ostream& out,Date* D)
{
    out<<D->jour<<endl;
    out<<D->mois<<endl;
    out<<D->annee<<endl;
    return out;
}
bool operator==(const Date& d1,const Date& d2)
{
    if((d1.jour==d2.jour)&&(d1.mois==d2.mois)&&(d1.annee==d2.annee))
        return true;
    return false;
}
bool operator<(const Date& d1, const Date& d2) {
    if (d1.annee < d2.annee) {
        return true;
    } else if (d1.annee > d2.annee) {
        return false;
    } else if (d1.mois < d2.mois) {
        return true;
    } else if (d1.mois > d2.mois) {
        return false;
    } else {
        return d1.jour < d2.jour;
    }
}
Date Date::dateCourante(){
Date d;
time_t now;
int day, mois, an;
time(&now);
struct tm *local = localtime(&now);

d.jour = local->tm_mday;
d.mois = local->tm_mon + 1;
d.annee = local->tm_year + 1900;
return d ;
}

bool Date::verifDate(Date d){
    Date d1=dateCourante();
if(annee > d.annee)
    return true ;
else
    if((annee == d.annee)&&(mois > d.mois))
    {
        return true ;
    }

    else
        if ((annee == d.annee)&&(mois == d.mois)&&(jour > d.jour))
        {
            return true ;
        }

cout<<"date de reservation doit etre superieur au "<<d1<<endl;
return false ;

}
Date::~Date()
{
    //dtor
}
