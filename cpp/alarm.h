#include <iostream>
#include <string>
#include "sensor.h"
#include "plant.h"

using namespace std;

class Alarm {
    public:
        Alarm();
        void addSensor();
        void deleteAlarm(string);
        void editAlarm(string);
        void showAlarm();
        
    private:
        Plant plant;
        vector <Sensor *> vSensors;
        string date;
        string time;
        string fileName;
};