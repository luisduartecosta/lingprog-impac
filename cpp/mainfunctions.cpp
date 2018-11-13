#include "mainfunctions.h"
#include "p2cpp.h"
MainFunctions::MainFunctions () {}

//caso 2
void MainFunctions::listAllAlarms () {
	cout << "Alarme \t Data \t Hora \t Status\n\n" << endl;
	for (unsigned i=0; i < vAlarms.size(); i++) {
		cout 	<< vAlarms.at(i)->getAlarmFileName() << "\t"
				<< vAlarms.at(i)->getAlarmDate() << "\t"
				<< vAlarms.at(i)->getAlarmTime() << "\t"
				<< vAlarms.at(i)->getAlarmStatus() << endl;
	}
} //fim listAllAlarms

//caso 3
void MainFunctions::removeAlarm (string target) {
	for (unsigned i=0; i < this->vAlarms.size(); i++) {
        string tmp = this->vAlarms.at(i)->getAlarmFileName();
        if (!tmp.compare(target)) {
            vAlarms.erase(vAlarms.begin() + i);
            break;
        }
    }
	cout << "Alarme removido." << endl;
} //fim removeAlarm

void MainFunctions::editAlarm (string target, string tatus) {
	// for (unsigned i=0; i< this->vAlarms.size(); i++) {
	// 	string tmp = this->vAlarms.at(i)->getAlarmFileName();
	// 	if (!tmp.compare(target)) {
	// 		vAlarms.at(i)->setAlarmStatus(status);
	// 	}
	// }
	cout << "Status do alarme alterado." << endl;
} //fimm editAlarm

//caso 5
void MainFunctions::detailAlarm(string target) {
	// for (unsigned i=0; i < vAlarms.size(); i++) {
	// 	string tmp = this->vAlarms.at(i)->getAlarmFileName();
	// 	if (!tmp.compare(target)) {
	// 		vAlarms.at(i)->showAlarm();
	// 	}
	// }
	cout << "DETAILALARM" << endl;
} //fim detailAlarm


void MainFunctions::choosingOption (string dado){
	int op=1;
	string target;  // ja nem lembro mais pra q serve
	string tmp;

	tmp = dado;
	
	//tmp =perlwrapper.perlGetHeaderData("../ANHANG101347.X3");
		
	do {
	utilidades.menu();
	op = utilidades.option("Qual opção desejada?");

	switch (op) {
		case 1:
			for (unsigned i=0; i < tmp.size(); i++){
				cout << tmp[i];
			}
			break;
		case 2:
			listAllAlarms();
			break;
		case 3:
			cout << "Digite o nome do alarme a ser removido: " << endl;
			cin >> target;
			removeAlarm(target); 
			break;
		case 4:
			cout << "Digite o nome do alarme que deseja editar: " << endl;
			cin >> target;
			//editAlarm(target);
			break;
		case 5:
			cout << "Digite o nome do alarme que deseja visualizar: " << endl;
			cin >> target;
			detailAlarm(target);
			break;
		case 0:
			break;	
		} // end switch
	} while (op !=0);

}; //fim choosingOption

