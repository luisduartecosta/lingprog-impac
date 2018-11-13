#include <EXTERN.h>
#include <perl.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef P2CPP_H
#define P2CPP_H

class P2CPP {
    public:
        P2CPP();
        ~P2CPP();

        void runInterpreterPerlFile (char *file);
        string perlGetHeaderData(string);
        
    private:
        PerlInterpreter *my_perl;
        char *my_argv [2];
};

#endif