#pragma once

#include "TypeCarburant.h"

class Vehicule {
public:
    Vehicule();
    Vehicule(TypeCarburant type, int autonomieMax, int autonomieActuelle);
    ~Vehicule();

    TypeCarburant  getTypeCarburant() const;
    int getAutonomieMax() const;

    int getAutonomieActuelle() const;
    void setAutonomieActuelle(int autonomie);

private:
    TypeCarburant  _type;
    int _autonomieMax, _autonomieActuelle;

};

