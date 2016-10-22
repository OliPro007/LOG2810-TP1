#pragma once

#include <iostream>
#include <vector>

#include "Sommet.h"

class Graphe {
public:
    Graphe(const std::vector<Sommet*>& sommets);
    ~Graphe();

    void afficher() const;
    const std::vector<Sommet*>& getSommet() const;

private:
    std::vector<Sommet*> _sommets;

};