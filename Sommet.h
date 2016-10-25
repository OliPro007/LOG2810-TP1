#pragma once

#include <iostream>
#include <vector>

#include "Arc.h"
#include "TypeCarburant.h"
#include "Arc.h"
#include <vector>

class Arc;
class Sommet {
public:
	Sommet(char nom, TypeCarburant valeur);
    Sommet(Sommet* sommet);
	~Sommet();

    char getName() const;
    std::vector<Arc*> getArcs();
    void addArc(Arc* arc);
    friend std::ostream& operator<<(std::ostream& o, const Sommet& sommet);

private:
    char _nom;
    TypeCarburant _valeur;
    std::vector<Arc*> _arcs;
};