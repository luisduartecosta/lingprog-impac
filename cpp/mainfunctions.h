#include <iostream>
#include <iomanip>
#include <vector>
#include "util.h"
#include "p2cpp.h"
#include "alarm.h"

using namespace std;

class MainFunctions {
	public:
		MainFunctions();

		// void importAlarm(string); 
		void listAllAlarms();
		void removeAlarm(string);
		void editAlarm(string, string);
		void detailAlarm(string);
		void choosingOption();

		Alarm loadAlarm(string);

	private:
		Util utilidades;
		P2CPP perlwrapper;	
		vector <Alarm *> vAlarms; 
};
