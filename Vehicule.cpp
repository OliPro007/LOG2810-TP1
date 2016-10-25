#include "Vehicule.h"

Vehicule::Vehicule()
    : _type('r'), _autonomieMax(0), _autonomieActuelle(0) {}

Vehicule::Vehicule(char type, int autonomieMax, int autonomieActuelle)
    : _type(type), _autonomieMax(autonomieMax), _autonomieActuelle(autonomieActuelle) {}

Vehicule::~Vehicule() {}

char Vehicule::getTypeCarburant() const {
    return  _type;
}

int Vehicule::getAutonomieMax() const {
    return _autonomieMax;
}

int Vehicule::getAutonomieActuelle() const {
    return _autonomieActuelle;
}

void Vehicule::setAutonomieActuelle(int autonomie) {
    _autonomieActuelle = autonomie;
}
