#include "Graphe.h"

using namespace std;

Graphe::Graphe(const vector<Sommet*>& sommets):
_sommets(sommets) {}

Graphe::~Graphe() {
	for(auto sommet : _sommets) {
		delete sommet;
	}
}

void Graphe::afficher() {
	for(auto sommet : _sommets) {
		cout << sommet << endl;
	}
}

std::vector<Sommet*> Graphe::getSommet() { return _sommets; }