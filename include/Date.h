#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
#include <time.h>
#include<string>

using namespace std;

class Date
{
    public:
    int jour,mois,annee;
   // Date* dateAct;
    public:
        Date(int j,int m,int a)
        {
            jour=j;mois=m;annee=a;
        }
        Date();
        void affiche();
        friend istream& operator>>(istream& in,Date& D);
        friend ostream& operator<<(ostream& out,Date& D);
        friend istream& operator>>(istream& in,Date* D);
        friend ostream& operator<<(ostream& out,Date* D);
        friend bool operator==(const Date&,const Date&);
        friend bool operator<(const Date&,const Date&);
        Date dateCourante();
        bool verifDate(Date);
        virtual ~Date();
};

#endif // DATE_H
