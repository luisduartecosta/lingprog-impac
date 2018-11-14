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
		return "ARQUIVO CORROMPIDO";
		//Move o arquivo para a pasta archive
		perlwrapper.perlMoveFile(file);
	}

	//Executa a função getHeaderData do Perl e passa os valores para o vector header
	perlwrapper.perlGetArray(file, "getHeaderData", header);
	
	//qro ver conteudo passado para header  --- EXCLUIR DEPOIS 
	// cout << "\n\nVETOR header\n\n";
	// for (unsigned i=1;i<7;i++)
	// 	cout << header.at(i) << endl; 
	
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
		return "ORIGEM INVALIDA";
		//Move o arquivo para a pasta archive
		perlwrapper.perlMoveFile(file);
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
	cout << "Alarme \t Data \t Hora \t Status\n\n" << endl;
	for (unsigned i=0; i < vAlarms.size(); i++) {
		cout 	<< vAlarms.at(i).getAlarmFileName() << "\t"
				<< vAlarms.at(i).getAlarmDate() << "\t"
				<< vAlarms.at(i).getAlarmTime() << "\t"
				<< vAlarms.at(i).getAlarmStatus() << endl;
	}
};

void MainFunctions::removeAlarm (string target) {
	for (unsigned i=0; i < vAlarms.size(); i++) {
        string tmp = vAlarms.at(i).getAlarmFileName();
        if (!tmp.compare(target)) {
            vAlarms.erase(vAlarms.begin() + i);
            break;
        }
    }
	cout << "Alarme removido." << endl;
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
	string target, target2;
	vector <string> files = listDir("./alarms/");
		
	do {
	utilidades.menu();
	cin >> op;

	switch (op) {
		case 1:
			cout << "-----Diretório de alarmes-----" << endl;
			for (unsigned i=0; i < files.size()-2; i++) {
				cout << i+1 << " - " << files.at(i) << endl;
			}
			cout << "Digite numero do alame a ser importado: ";
			cin >> selector;
			if (selector < 1 || selector > files.size()-2) {
				cout << "Opção inválida" << endl;
				break;
			}
			cout << "\nRESULTADO DE importAlarm: " << importAlarm(files.at(selector-1)) << endl;
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
			cout << "Digite o status que deseja colocar: ";
			cin >> target2;
			editAlarm(target, target2);
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

vector <string> MainFunctions::listDir (string dir) {
	vector <string> files;

	//Interpretador apondo para o arquivo perl
	perlwrapper.runInterpreterPerlFile((char*)"IMPAC.pl");

	perlwrapper.perlGetArray(dir, "listDir", files);

	return files;
};

