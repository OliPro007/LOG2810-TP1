////////////////////////////////////////////////////////////////////////////////
/// @file		Vehicule.cpp
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#include "Vehicule.h"

Vehicule::Vehicule()
    : _type('r'), _autonomieMax(0), _autonomieActuelle(0) {}

Vehicule::Vehicule(char type, int autonomieMax, int autonomieActuelle)
    : _type(type), _autonomieMax(autonomieMax), _autonomieActuelle(autonomieActuelle) {}

Vehicule::Vehicule(Vehicule* vehicule) {
    _type = vehicule->_type;
    _autonomieMax = vehicule->_autonomieMax;
    _autonomieActuelle = vehicule->_autonomieActuelle;
}

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
