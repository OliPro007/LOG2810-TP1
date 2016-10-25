#include "Graphe.h"

using namespace std;

Graphe::Graphe(const vector<Sommet*>& sommets)
    : _sommets(sommets) {}

Graphe::~Graphe() {
    for(auto sommet : _sommets) {
        delete sommet;
    }
}

void Graphe::afficher() const {
    for (Sommet* sommet : _sommets) {
        cout << *sommet << endl;
    }
}

const std::vector<Sommet*>& Graphe::getSommet() const {
    return _sommets;
}
