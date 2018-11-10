#include <EXTERN.h>
#include <perl.h>
#include <iostream>
#include <string>
using namespace std;

class PerlWrapper {
    public:
    PerlWrapper();
    ~PerlWrapper();
    void runInterpreterPerlFile (char *file);
    int checkPlant (string, string ,string perlFunc);
    
    private:
    PerlInterpreter *my_perl;
    char *my_argv [2];
};
