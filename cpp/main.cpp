/* como executar o codigo 
 
    NA PASTA CPP
    g++ teste -o util.cpp mainfunctions.cpp perlToC++.cpp main.cpp `perl -MExtUtils::Embed -e ccopts -e ldopts  `

    `` nao eh ''

*/

#include <iostream>
//#include <iomanip>
#include <string>
#include "mainfunctions.h"
#include "perlToC.h"
#include "util.h"
using namespace std;

/*

compilando: g++ -o  teste util.cpp mainfunctions.cpp perlToC.cpp main.cpp `perl -MextUtils::Embed -e ccopts -e ldopts`

*/

int main () {

PerlWrapper perlwrapper("oi");
perlwrapper.interpreterPerl();

cout << "\nValor é:" << perlwrapper.checkPlant("ANHANG101347.X3","ANHANG101347.X3","checkPlant");

MainFunctions functions;
//functions.choosingOption();  SO PRA TESTAR O PERL ANTE DE FZR AS FUNCOES

return 0;
}

