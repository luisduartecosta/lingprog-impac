#include <EXTERN.h>
#include <perl.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class P2CPP {
    public:
        P2CPP();
        ~P2CPP();

        void runInterpreterPerlFile (char *file);
        vector<string> perlGetHeaderData(string);
        
    private:
        PerlInterpreter *my_perl;
        char *my_argv [2];
};
