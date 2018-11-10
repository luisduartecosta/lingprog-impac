/*
main so cria a classa mainfuctions e chama as opcoes. mainfunctions vai executar as funcoes necessarias no programa
*/

#include <iostream>
//#include <iomanip>
#include <string>
#include "mainfunctions.h"
#include "perlToC++.h"
#include "util.h"
using namespace std;


int main () {

PerlWrapper perlwrapper;
perlwrapper.interpreterPerl();

cout << "\nValor é:" << perlwrapper.checkPlant("checkPlant","ANHANG101347.X3","ANHANG101347.X3");

MainFunctions functions;
//functions.choosingOption();  SO PRA TESTAR O PERL ANTE DE FZR AS FUNCOES

return 0;
}
