#include "alarm.h"

Alarm::Alarm() {};

void Alarm::addSensor(Sensor &newSensor) {
    vSensors.push_back(&newSensor);
};

void Alarm::deleteSensor(string sensorName) {
    for (unsigned i=0; i < this->vSensors.size(); i++) {
        string tmpName = this->vSensors.at(i)->getName();
        if (!tmpName.compare(sensorName)) {
            vSensors.erase(vSensors.begin() + i);
            break;
        }
    }
};

