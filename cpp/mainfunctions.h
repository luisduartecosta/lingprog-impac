#include <iostream>
#include <iomanip>
#include <vector>
#include "util.h"
#include "perlToC++.h"

using namespace std;

class MainFunctions {

	public:
	MainFunctions();
	~MainFunctions();
	vector<string> importAlarms(); 
	void showAlarms();
	void removeAlarm(string);
	void editAlarm(string);
	void addNewPlant();	
	void getUpdateAlarms(); // atualiza a variavel alarms qd necessario ou ao iniciar o programa
	void choosingOption();



	private:
	Util utilidades;	
	vector <string> alarms; 
	
};
