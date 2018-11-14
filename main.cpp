/* como executar o codigo 
 
    NA PASTA CPP
    g++ teste -o util.cpp mainfunctions.cpp perlToC++.cpp main.cpp `perl -MExtUtils::Embed -e ccopts -e ldopts  `

    `` nao eh ''

*/

#include <iostream>
#include <string>
#include <vector>
#include "mainfunctions.h"

using namespace std;

int main () {
    MainFunctions functions;
   
    functions.choosingOption();

    return 0;
}

