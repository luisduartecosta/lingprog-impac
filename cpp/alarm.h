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
        void setAlarmStatus(string);
        string getAlarmStatus();
        void setAlarmPlant();
        string getAlarmPlant();
        void setAlarmType();
        string getAlarmType();
        void setAlarmProtocol();
        string getAlarmProtocol();

        void addSensor(Sensor &);
        void deleteSensor(string);
        void showAlarm();
        
    private:
        vector <Sensor *> vSensors;
        string date;
        string time;
        string fileName;
        string status;
        string plant;
        string protocol;
        string type;
};