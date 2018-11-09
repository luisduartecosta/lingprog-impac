#include "mainfunctions.h"

MainFunctions::MainFunctions () {
	//Util utilidades;
}

MainFunctions::~MainFunctions () {
	
}

vector<string> MainFunctions::importAlarms () {
	vector<string> exemplo  = {"arthur ","petito"};
	for (unsigned i=0;i<exemplo.size();i++)
		cout << exemplo[i];
	cout << endl;
	return exemplo;
} 

void MainFunctions::showAlarms () {
	cout << "\nshowAlarms" << endl;
}

void MainFunctions::removeAlarm (string target) {
	cout << "\nremoveAlarm" << endl;
}

void MainFunctions::editAlarm (string target) {
	cout << "\neditAlarms" << endl;
}

void MainFunctions::addNewPlant (){
	cout << "\naddNewplant" << endl;
}

void MainFunctions::choosingOption (){
	int op=1;
		
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n"; //abre espaco na tela para melhor visualizacao 

	do {
	utilidades.menu();
	op = utilidades.option("Qual opção desejada?");

	switch (op) {
		case 1:
			importAlarms();
			break;
		case 2:
			showAlarms();
			break;
		case 3:
			removeAlarm("ALARME"); 
			break;
		case 4:
			editAlarm("ALARME");
			break;
		case 5:
			addNewPlant();
			break;
		case 0:
			getUpdateAlarms();
			break;	
		} // end switch
	} while (op !=0);

} //fim choosingOption 

void MainFunctions::getUpdateAlarms (){
	cout << "\ngetUpdateAlarms" << endl;
}
