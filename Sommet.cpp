#include "Sommet.h"

using namespace std;

Sommet::Sommet(char nom, TypeCarburant valeur)
    : _nom(nom), _valeur(valeur) {}

Sommet::~Sommet() {
    for (auto arc : _arcs) {
        delete arc;
    }
}

char Sommet::getName() const
{
    return _nom;
}

std::vector<Arc*> Sommet::getArcs()
{
    return _arcs;
}

void Sommet::addArc(Arc* arc)
{
    _arcs.push_back(arc);
}

ostream& operator<<(ostream& o, const Sommet& sommet) {
    o << sommet._nom << ",";
    switch(sommet._valeur) {
        case TypeCarburant::rien:
            o << "rien";
            break;
        case TypeCarburant::electrique:
            o << "electrique";
            break;
        case TypeCarburant::essence:
            o << "essence";
            break;
        case TypeCarburant::hybrid:
            o << "hybrid";
    }
    return o;
}