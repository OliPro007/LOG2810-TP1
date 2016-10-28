#pragma once

#include <vector>

#include "Sommet.h"
#include "Vehicule.h"

class Chemin
{
public:
	Chemin() = delete;
    Chemin(Vehicule* vehicule);
    Chemin(Chemin& chemin);
    ~Chemin();

    bool contains(Sommet* sommet) const;

    int getDistance() const;
    Vehicule* getVehicule() const;
    std::vector<Sommet*> getSommets() const;

    void addSommet(Sommet* sommet, int distance);

    friend std::ostream& operator<<(std::ostream& o, const Chemin& chemin);

private:
    std::vector<Sommet*> _sommets;
    int _distance;
    Vehicule* _vehicule;
};
