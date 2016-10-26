#include "Chemin.h"
#include <iterator>

Chemin::Chemin(Vehicule* vehicule) 
	: _sommets(std::vector<Sommet*>()), _distance(0), _vehicule(vehicule) {}

Chemin::Chemin(Chemin& chemin) {
    _sommets = chemin._sommets;
    _distance = chemin._distance;
    _vehicule = new Vehicule(chemin._vehicule);
}

Chemin::~Chemin() {
    delete _vehicule;
}

bool Chemin::contains(Sommet* sommet) const {
    for (size_t i = 0; i < _sommets.size(); i++) {
        if (_sommets[i]->getName() == sommet->getName()) return true;
    }
    return false;
}

int Chemin::getDistance() const {
    return _distance;
}

Vehicule* Chemin::getVehicule() const { return _vehicule; }

std::vector<Sommet*> Chemin::getSommets() const {
    return _sommets;
}

void Chemin::addSommet(Sommet * sommet, int distance) {
    _sommets.push_back(sommet);
    _distance += distance;
    if (sommet->getType() == _vehicule->getTypeCarburant() || sommet->getType() == 'h') {
        _vehicule->setAutonomieActuelle(_vehicule->getAutonomieMax());
    } else {
        _vehicule->setAutonomieActuelle(_vehicule->getAutonomieActuelle() - distance);
    }
}

std::ostream& operator<<(std::ostream& o, const Chemin& chemin) {
    o << "Chemin : ";
	for (auto it = chemin._sommets.begin(); it != chemin._sommets.end(); it++) {
		o << (*it)->getName();
		if (it != chemin._sommets.end() - 1) o << " -> ";
	}
    o << std::endl << "Distance : " << chemin.getDistance();
    
    return o;
}
