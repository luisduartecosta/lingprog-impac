#include <iostream>
#include <string>
#include "sensor.h"
#include "plant.h"

using namespace std;

class Alarm {
    public:
        Alarm();

        void setAlarmDate(string);
        string getAlarmDate();
        void setAlarmTime(string);
        string getAlarmTime();
        void setAlarmFileName(string);
        string getAlarmFileName();
        void setPlant(Plant);
        Plant getPlant();
        void setAlarmStatus(string);
        string getAlarmStatus();

        void addSensor(Sensor &);
        void deleteSensor(string);
        void showAlarm();
        
    private:
        Plant plant;
        vector <Sensor *> vSensors;
        string date;
        string time;
        string fileName;
        string status;
};