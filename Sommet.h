#pragma once

#include <iostream>
#include <vector>

#include "Arc.h"
#include <vector>

class Arc;
class Sommet {
public:
	Sommet() = delete;
	Sommet(char nom, char valeur);
    Sommet(Sommet* sommet);
	~Sommet();

    char getName() const;
    char getType() const;

    std::vector<Arc*> getArcs() const;
    void addArc(Arc* arc);

    friend std::ostream& operator<<(std::ostream& o, const Sommet& sommet);

private:
    char _nom, _valeur;
    std::vector<Arc*> _arcs;
};
