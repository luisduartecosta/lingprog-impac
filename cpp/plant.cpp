#include "plant.h"

void Plant::setPlantName(string newName) {name = newName;};

string Plant::getPlantName() {return name;};

void Plant::setPlantType(string newType) {type = newType;};

string Plant::getPlantType() {return type;};

void Plant::setPlantProtocol(string newProtocol) {protocol = newProtocol;};

string Plant::getPlantProtocol() {return protocol;};

void Plant::addPlant(string newName, string newType, string newProtocol) {
    setPlantName(newName);
    setPlantType(newType);
    setPlantProtocol(newProtocol);
};

void Plant::showPlant() {
    cout << getPlantName() << " - " << getPlantType() << " - " << getPlantProtocol() << endl;
};
