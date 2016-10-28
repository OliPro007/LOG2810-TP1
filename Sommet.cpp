////////////////////////////////////////////////////////////////////////////////
/// @file		Sommet.cpp
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#include "Sommet.h"
#include <iterator>

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

char Sommet::getName() const {
    return _nom;
}

char Sommet::getType() const { return _valeur; }

std::vector<Arc*> Sommet::getArcs() const {
    return _arcs;
}

void Sommet::addArc(Arc* arc) {
    _arcs.push_back(arc);
}

std::ostream& operator<<(std::ostream& o, const Sommet& sommet) {
    o << "(" << sommet._nom << ",";
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

    if (sommet._arcs.size() > 0) {
        o << ", (";

        for (auto it = sommet._arcs.begin(); it != sommet._arcs.end(); it++) {
            o << **it;
            if (it != sommet._arcs.end() - 1) o << ",";
        }

        o << ")";
    }

    o << ")";

    return o;
}