#include "sensor.h"

Sensor::Sensor(string newName, string newTime, string newStatus, string newLevel, string newObs)
    : name(newName), time(newTime), status(newStatus), level(newLevel), obs(newObs) {};

void Sensor::setTime(string newTime) {time = newTime;};

string Sensor::getTime() {return time;};

void Sensor::setName(string newName) {name = newName;};

string Sensor::getName() {return name;};

void Sensor::setStatus(string newStatus) {status = newStatus;};

string Sensor::getStatus() {return status;};

void Sensor::setLevel(string newLevel) {level = newLevel;};

string Sensor::getLevel() {return level;};

void Sensor::setObs(string newObs) {obs = newObs;};

string Sensor::getObs() {return obs;};

void Sensor::showData() {
    cout    << getTime() << " "
            << getName() << "\t"
            << getStatus() << "\t"
            << getLevel() << "\t"
            << getObs() << endl;
};
