#pragma once

#include <iostream>
#include <vector>

#include "Sommet.h"

class Graphe {
public:
	Graphe(const std::vector<Sommet*>& sommets);
	~Graphe();

	void afficher();
	std::vector<Sommet*> getSommet();

private:
	std::vector<Sommet*> _sommets;

};