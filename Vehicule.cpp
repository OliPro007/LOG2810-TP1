#include "TypeCarburant.h"
#include "Vehicule.h"

Vehicule::Vehicule()
    : _type(TypeCarburant::rien), _autonomieMax(0), _autonomieActuelle(0) {}

Vehicule::Vehicule(TypeCarburant type, int autonomieMax, int autonomieActuelle)
    : _type(type), _autonomieMax(autonomieMax), _autonomieActuelle(autonomieActuelle) {}

Vehicule::~Vehicule() {}

TypeCarburant  Vehicule::getTypeCarburant() { return  _type; }

int Vehicule::getAutonomieMax() { return _autonomieMax; }

int Vehicule::getAutonomieActuelle() { return _autonomieActuelle; }

void Vehicule::setAutonomieActuelle(int autonomie) { _autonomieActuelle = autonomie; }
