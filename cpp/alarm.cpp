#include "alarm.h"

Alarm::Alarm() {};

void Alarm::setAlarmDate(string newDate) {date = newDate;};

string Alarm::getAlarmDate() {return date;};

void Alarm::setAlarmTime(string newTime) {time = newTime;};

string  Alarm::getAlarmTime() {return time;};

void Alarm::setAlarmFileName(string newFileName) {fileName = newFileName;};

string Alarm::getAlarmFileName() {return fileName;};

void Alarm::setAlarmStatus(string newStatus) {status = newStatus;};

string Alarm::getAlarmStatus() {return status;};

void Alarm::setAlarmPlant(string newPlant) {plant = newPlant;};

string Alarm::getAlarmPlant() {return plant;};

void Alarm::setAlarmType(string newType) {type = newType;};

string Alarm::getAlarmType() {return type;};

void Alarm::setAlarmProtocol(string newProtocol) {protocol = newProtocol;};

string Alarm::getAlarmProtocol() {return protocol;};

void Alarm::addSensor(Sensor &newSensor) {
    vSensors.push_back(&newSensor);
};

void Alarm::deleteSensor(string sensorName) {
    for (unsigned i=0; i < this->vSensors.size(); i++) {
        string tmpName = this->vSensors.at(i)->getSensorName();
        if (!tmpName.compare(sensorName)) {
            vSensors.erase(vSensors.begin() + i);
            break;
        }
    }
};

void Alarm::showAlarm() {
    cout << getAlarmDate() << " " << getAlarmTime() << " from " << getAlarmType() << "at " << getAlarmPlant() << " : \n\n" << endl;
    for (unsigned i=0; i < vSensors.size(); i++) {
        vSensors.at(i)->showData();
    }
    cout << "\n\n-----------------------------------------------" << endl;
    cout << "File: " << getAlarmFileName() << " , Protocol: " << getAlarmProtocol() << "Total Sensors: " << vSensors.size() << endl;
};

