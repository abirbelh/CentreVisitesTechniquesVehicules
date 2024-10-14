#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include "string"
#include "exception"
using namespace std;

class MyExceptions : public exception{
    string msg;
    public:
        MyExceptions();
        MyExceptions(string m){msg=m;}
        virtual ~MyExceptions();

    protected:

    private:
};
#endif // MYEXCEPTIONS_H
