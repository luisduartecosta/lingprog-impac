#include "util.h"

//trata a escolha do usuario 
int Util::option(string message){

  int opt;
  cout << "\n" << message << endl;
  cin >> opt;

  while (cin.fail() || opt < MIN || opt > MAX){
	cin.clear();// cin.fail verifica se a entrada eh int clear limpa o flag
	cin.ignore(10000,'\n');
	
	cout  << "ENTRADA INVALIDA!\nA  entrada deve ser um numero inteiro dentre as opcoes fornecidas" << endl;
	cin >> opt;
  }
   
return opt;	
}  // verificar aqui se retorna int ou static int   !!!!!!


// EXIBE MENU
void Util::menu(){

cout << "\n------------- MENU -------------\n" <<endl;
cout << "1 - iMPORTAR ALARME"<< endl;
cout << "2 - LISTAR TODOS OS ALARMES" << endl;
cout << "3 - REMOVER ALARME" << endl;
cout << "4 - EDITAR ALARME" << endl;
cout << "5 - MOSTRAR DETALHES DO ALARME" << endl;
cout << "0 - SAIR" << endl;

} 

