#include "sensor.h"

Sensor::Sensor() {};

Sensor::Sensor(string newName, string newTime, string newStatus, string newLevel, string newObs)
    : name(newName), time(newTime), status(newStatus), level(newLevel), obs(newObs) {};

void Sensor::setSensorTime(string newTime) {time = newTime;};

string Sensor::getSensorTime() {return time;};

void Sensor::setSensorName(string newName) {name = newName;};

string Sensor::getSensorName() {return name;};

void Sensor::setSensorStatus(string newStatus) {status = newStatus;};

string Sensor::getSensorStatus() {return status;};

void Sensor::setSensorLevel(string newLevel) {level = newLevel;};

string Sensor::getSensorLevel() {return level;};

void Sensor::setSensorObs(string newObs) {obs = newObs;};

string Sensor::getSensorObs() {return obs;};

void Sensor::showData() {
    cout    << getSensorTime() << " "
            << getSensorName() << "\t"
            << getSensorStatus() << "\t"
            << getSensorLevel() << "\t"
            << getSensorObs() << endl;
};
