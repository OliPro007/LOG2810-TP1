#include "Chemin.h"



Chemin::Chemin(const std::vector<Sommet*>& sommets, int distance, Vehicule* vehicule) : _sommets(sommets), _distance(distance), _vehicule(vehicule)
{
}

Chemin::Chemin()
{

}

Chemin::Chemin(Chemin & chemin)
{
    _sommets = chemin.getSommets();
    _distance = chemin.getDistance();
    _vehicule = new Vehicule(chemin._vehicule);
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

Vehicule* Chemin::getVehicule() { return _vehicule; }

std::vector<Sommet*> Chemin::getSommets()
{
    return _sommets;
}

void Chemin::addSommet(Sommet * sommet, int distance)
{
    _sommets.push_back(sommet);
    _distance += distance;
    if (sommet->getType() == _vehicule->getTypeCarburant() || sommet->getType() == 'h') {
        _vehicule->setAutonomieActuelle(_vehicule->getAutonomieMax());
    } else {
        _vehicule->setAutonomieActuelle(_vehicule->getAutonomieActuelle() - distance);
    }
}

std::ostream& operator<<(std::ostream& o,  Chemin& chemin) {
    o << "Chemin : ";
    for (auto sommet : chemin.getSommets()) {
        o << sommet->getName() << ",";
    }
    o << " Distance : " << chemin.getDistance();
    
    
    return o;
}
