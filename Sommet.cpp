#include "Sommet.h"

using namespace std;

Sommet::Sommet(char nom, TypeCarburant valeur)
    : _nom(nom), _valeur(valeur) {}

Sommet::~Sommet() {}

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