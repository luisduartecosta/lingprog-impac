#include "mainfunctions.h"

MainFunctions::MainFunctions () {}

string MainFunctions::importAlarm(string file) {
	vector <string> header;
	vector <string> sensorData;
	Alarm tmpAlarm;
	Sensor tmpSensor;
	int errors = 0;

	//Interpretador apondo para o arquivo perl
	perlwrapper.runInterpreterPerlFile((char*)"IMPAC.pl");

	//Valida o arquivo
	errors = perlwrapper.perlVerifyIntegrity(file);
	
	if (errors > 0) {
		//Arquivo corrompido
		//Move o arquivo para a pasta archive
			//Executa a função getHeaderData do Perl e passa os valores para o vector header
			perlwrapper.perlGetArray(file, "getHeaderData", header);

			//Atribui os valores para a varivavel alarm
			tmpAlarm.setAlarmProtocol("-");
			tmpAlarm.setAlarmFileName(header[2]);
			tmpAlarm.setAlarmPlant(header[3]);
			tmpAlarm.setAlarmType("-");
			tmpAlarm.setAlarmTime("-");
			tmpAlarm.setAlarmDate("-");
			tmpAlarm.setAlarmStatus("Arquivo corrompido");
			vAlarms.push_back(tmpAlarm);
		perlwrapper.perlMoveFile(file);
		return "ARQUIVO CORROMPIDO";
	}

	//Executa a função getHeaderData do Perl e passa os valores para o vector header
	perlwrapper.perlGetArray(file, "getHeaderData", header);
	
	//Atribui os valores para a varivavel alarm
	tmpAlarm.setAlarmProtocol(header[1]);
	tmpAlarm.setAlarmFileName(header[2]);
	tmpAlarm.setAlarmPlant(header[3]);
	tmpAlarm.setAlarmType(header[4]);
	tmpAlarm.setAlarmTime(header[5]);
	tmpAlarm.setAlarmDate(header[6]);

	//Valida a origem e destino

	if (tmpAlarm.getAlarmFileName().find(tmpAlarm.getAlarmPlant())) {
		//Origem inválida
		//Move o arquivo para a pasta archive
			tmpAlarm.setAlarmStatus("origem invalida");
			vAlarms.push_back(tmpAlarm);
		perlwrapper.perlMoveFile(file); 
		return "ORIGEM INVALIDA";
		
	}

	//Importa os dados de sensores
	perlwrapper.perlGetArray(file, "getSensorsData", sensorData);


	for (unsigned i=0; i < sensorData.size(); i+=5) {
		tmpSensor = Sensor(sensorData[i+3], sensorData[i+4], sensorData[i+2], sensorData[i+1], sensorData[i]);
	 	tmpAlarm.addSensor(tmpSensor);

	}
	
	//Alarme importado com sucesso
	//Altera o status para importado
	tmpAlarm.setAlarmStatus("Importado");

	vAlarms.push_back(tmpAlarm);

	//Move o arquivo para a pasta archive
	perlwrapper.perlMoveFile(file);

	return "OK";
};

void MainFunctions::listAllAlarms () {
	cout << "\nAlarme" << setw(20) <<"\t\tData" << setw (12) << "Hora" << setw(20) <<"Status\n" << endl;
	for (unsigned i=0; i < vAlarms.size(); i++) {
		cout 	<< vAlarms.at(i).getAlarmFileName() << setw(20)
				<< vAlarms.at(i).getAlarmDate() << setw(12)
				<< vAlarms.at(i).getAlarmTime() << setw(20)
				<< vAlarms.at(i).getAlarmStatus() << endl;
	}
};

void MainFunctions::removeAlarm (string target) {
	for (unsigned i=0; i < vAlarms.size(); i++) {
        string tmp = vAlarms.at(i).getAlarmFileName();
        if (!tmp.compare(target)) {
            vAlarms.erase(vAlarms.begin() + i);
			cout << "Alarme removido." << endl;
            break;
        }
    }
};

void MainFunctions::editAlarm (string target, string status) {
	for (unsigned i=0; i< vAlarms.size(); i++) {
		string tmp = vAlarms.at(i).getAlarmFileName();
		if (!tmp.compare(target)) {
			vAlarms.at(i).setAlarmStatus(status);
		}
	}
	cout << "Status do alarme alterado." << endl;
};

void MainFunctions::detailAlarm(string target) {
	for (unsigned i=0; i < vAlarms.size(); i++) {
		string tmp = vAlarms.at(i).getAlarmFileName();
		if (!tmp.compare(target)) {
			vAlarms.at(i).showAlarm();
		}
	}
};

void MainFunctions::choosingOption (){
	int op=1;
	int selector;
	string status;
	vector <string> files;
		
	do {
	utilidades.menu();
	cin >> op;

	switch (op) {
		case 1:
			files = listDir("./alarms/");
			cout << "\n-----Diretório de alarmes-----" << endl;
			for (unsigned i=0; i < files.size()-2; i++) {
				cout << i+1 << " - " << files.at(i) << endl;
			}
			cout << "\nDigite numero do alame a ser importado: ";
			cin >> selector;
			if (selector < 1 || selector > files.size()-2) {
				cout << "Opção inválida" << endl;
				break;
			}
			cout << "\nResultado de importAlarm: " << importAlarm(files.at(selector-1)) << endl;
			break;
		case 2:
			listAllAlarms();
			break;
		case 3:
			files = listDir("./archive/");
			cout << "\n-----Diretório de alarmes arquivados-----" << endl;
			for (unsigned i=0; i < files.size()-2; i++) {
				cout << i+1 << " - " << files.at(i) << endl;
			}
			cout << "\nDigite numero do alame a ser removido: ";
			cin >> selector;
			if (selector < 1 || selector > files.size()-2) {
				cout << "Opção inválida" << endl;
			// cout << "Digite o nome do alarme a ser removido: " << endl;
			// cin >> target;
			}
			removeAlarm(files.at(selector-1)); 
			break;
		case 4:
			files = listDir("./archive/");
			cout << "-----Diretório de alarmes arquivados-----" << endl;
			for (unsigned i=0; i < files.size()-2; i++) {
				cout << i+1 << " - " << files.at(i) << endl;
			}
			cout << "Digite numero do alame a ser editado: ";
			cin >> selector;
			if (selector < 1 || selector > files.size()-2) 
				cout << "Opção inválida" << endl;

			cout << "Digite o status que deseja colocar: ";
			cin >> status;
			editAlarm(files.at(selector-1), status);
			break;
		case 5:
			files = listDir("./archive/");
			cout << "-----Diretório de alarmes arquivados-----" << endl;
			for (unsigned i=0; i < files.size()-2; i++) {
				cout << i+1 << " - " << files.at(i) << endl;
			}
			cout << "Digite numero do alame que deseja visualzar: ";
			cin >> selector;
			if (selector < 1 || selector > files.size()-2) 
				cout << "Opção inválida" << endl;
			
			detailAlarm(files.at(selector-1));
			break;
		case 0:
			break;	
		} // end switch
	} while (op !=0);

}; //fim choosingOption

vector <string> MainFunctions::listDir (string dir) {
	vector <string> files;

	//Interpretador apondo para o arquivo perl
	perlwrapper.runInterpreterPerlFile((char*)"IMPAC.pl");

	perlwrapper.perlGetArray(dir, "listDir", files);

	return files;
};
