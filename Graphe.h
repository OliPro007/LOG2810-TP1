////////////////////////////////////////////////////////////////////////////////
/// @file		Graphe.h
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <vector>

#include "Sommet.h"

/**
@class Graphe
Représente un graphe valué symbolisant un réseau routier.
*/
class Graphe {
public:
    /**
    Constructeur.
    @param sommets Une liste (vector) des sommets présents dans le graphe.
    */
    Graphe(const std::vector<Sommet*>& sommets);

    /**
    Destructeur.
    */
    ~Graphe();

    /**
    Afficher l'ensemble des sommets du graphe.
    */
    void afficher() const;

    /**
    Getter.
    @return L'ensemble des sommets du graphe.
    */
    const std::vector<Sommet*>& getSommet() const;

private:
    std::vector<Sommet*> _sommets;

};
