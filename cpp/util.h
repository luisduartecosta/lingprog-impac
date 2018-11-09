#include <iostream>
#include <iomanip>
using namespace std;

#ifndef UTIL_H
#define UTIL_H

#define MAX	5  // referente as opcoes 
#define MIN	0  // do menu

class Util {
      public:
	int option(string); // obtem opcao do teclado - tirei o static q imaginei
	void menu();

      private:


};
#endif


