#include <EXTERN.h>
#include <perl.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef     PERLTOC_H
#define     PERLTOC_H
class PerlWrapper {
    public:
    PerlWrapper(string);
    ~PerlWrapper();
    void interpreterPerl ();
    int checkPlant (string, string ,string perlFunc);
    
    private:
    PerlInterpreter *my_perl;
    char *my_argv [2];
};

#endif