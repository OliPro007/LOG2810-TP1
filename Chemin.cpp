#include "Chemin.h"



Chemin::Chemin(const std::vector<Sommet*>& sommets, int distance) : _sommets(sommets), _distance(distance)
{
}

Chemin::Chemin()
{

}

Chemin::Chemin(Chemin & chemin)
{
    _sommets = chemin.getSommets();
    _distance = chemin.getDistance();
}


Chemin::~Chemin()
{
}

bool Chemin::contains(Sommet * sommet)
{
    for (int i = 0; i < _sommets.size(); i++) {
        if (_sommets[i]->getName() == sommet->getName()) return true;
    }
    return false;
}

int Chemin::getDistance()
{
    return _distance;
}

std::vector<Sommet*> Chemin::getSommets()
{
    return _sommets;
}

void Chemin::addSommet(Sommet * sommet, int distance)
{
    _sommets.push_back(sommet);
    _distance += distance;
}

std::ostream& operator<<(std::ostream& o,  Chemin& chemin) {
    o << "Chemin : ";
    for (auto sommet : chemin.getSommets()) {
        o << sommet->getName() << ",";
    }
    o << " Distance : " << chemin.getDistance();
    
    
    return o;
}
