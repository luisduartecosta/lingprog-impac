/*
main so cria a classa mainfuctions e chama as opcoes. mainfunctions vai executar as funcoes necessarias no programa
*/

#include <iostream>
#include <string>
#include "mainfunctions.h"

using namespace std;

int main () {

P2CPP perlwrapper;
MainFunctions functions;

perlwrapper.runInterpreterPerlFile("../perl/main.pl");
functions.choosingOption();

return 0;
}
