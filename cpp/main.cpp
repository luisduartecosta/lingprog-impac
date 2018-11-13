/*
main so cria a classa mainfuctions e chama as opcoes. mainfunctions vai executar as funcoes necessarias no programa
*/

#include <iostream>
#include <string>
#include "mainfunctions.h"

using namespace std;

int main () {

string arquivo= "../ANHANG101347.X3";
char *perlFile = (char  *)"../perl/main.pl";
//vector<string> dados;
string dados;

P2CPP perlwrapper;
MainFunctions functions;

cout <<  "\nRODANDO" << endl;

perlwrapper.runInterpreterPerlFile(perlFile);
cout <<  "\n1" << endl;

dados = perlwrapper.perlGetHeaderData(arquivo);

cout <<"diz q ta chegando dados" << endl;
cout << "\n-------- "<< dados <<  "--------\n\n";
//so pra ver oretorno de perlGetHeaderData
// for (unsigned i=0; i < dados.size(); i++){
//     cout << dados[i] << endl;
// }

functions.choosingOption(dados);

return 0;
}
