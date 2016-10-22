#pragma once

#include <iostream>

#include "TypeCarburant.h"

class Sommet {
public:
    Sommet(char nom, TypeCarburant valeur);
    ~Sommet();

    friend std::ostream& operator<<(std::ostream& o, const Sommet& sommet);

private:
    char _nom;
    TypeCarburant _valeur;

};