#pragma once

#include <vector>

#include "Sommet.h"
#include "Vehicule.h"

class Chemin
{
public:
    Chemin(const std::vector<Sommet*>& sommets, int distance, Vehicule* vehicule);
    Chemin();
    Chemin(Chemin& chemin);
    ~Chemin();

    bool contains(Sommet* sommet);

    int getDistance();
    Vehicule* getVehicule();
    std::vector<Sommet*> getSommets();

    void addSommet(Sommet* sommet, int distance);

    friend std::ostream& operator<<(std::ostream& o, Chemin& chemin);

private:
    std::vector<Sommet*> _sommets;
    int _distance;
    Vehicule* _vehicule;
};

