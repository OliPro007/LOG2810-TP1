#include "Sommet.h"

using namespace std;

Sommet::Sommet(char nom, char valeur)
    : _nom(nom), _valeur(valeur) {}

Sommet::Sommet(Sommet *sommet) {
    _nom = sommet->_nom;
    _valeur = sommet->_valeur;
}

Sommet::~Sommet() {
    for (auto arc : _arcs) {
        delete arc;
    }
}

char Sommet::getName() const
{
    return _nom;
}

char Sommet::getType() const { return _valeur; }

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
        case 'r':
            o << "rien";
            break;
        case 'l':
            o << "electrique";
            break;
        case 'e':
            o << "essence";
            break;
        case 'h':
            o << "hybrid";
    }
    return o;
}