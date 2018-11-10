/*
main so cria a classa mainfuctions e chama as opcoes. mainfunctions vai executar as funcoes necessarias no programa
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "mainfunctions.h"
#include "perlToC++.h"
#include "util.h"
using namespace std;


int main () {

PerlWrapper perlwrapper;
MainFunctions functions;

perlwrapper.runInterpreterPerlFile("main.pl");
functions.choosingOption();

return 0;
}
