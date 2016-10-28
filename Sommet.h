////////////////////////////////////////////////////////////////////////////////
/// @file		Sommet.h
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <vector>

#include "Arc.h"
#include <vector>

class Arc;

/**
@class Sommet
Représente un sommet dans un graphe valué.
Dans cette situation, il s'agit d'une intersection pouvant posséder (ou non) une station-service.
*/
class Sommet {
public:
    /**
    Constructeur.
    @param nom L'identificateur du point dans le graphe.
    @param valeur Le type de station-service qui se trouve à cette position.
    */
    Sommet(char nom, char valeur);

    /**
    Constructeur de copie.
    @param sommet Le sommet à copier.
    */
    Sommet(Sommet* sommet);

    /**
    Destructeur.
    */
    ~Sommet();

    /**
    Getter.
    @return L'identificateur du sommet.
    */
    char getName() const;

    /**
    Getter.
    @return Le type de station-service.
    */
    char getType() const;

    /**
    Getter.
    @return L'ensemble des arcs qui partent du sommet.
    */
    std::vector<Arc*> getArcs() const;

    /**
    Ajoute un arc partant du sommet.
    @param arc L'arc à ajouter au sommet.
    */
    void addArc(Arc* arc);

    /**
    Opérateur d'affichage.
    @param o Le flux de sortie vers lequel écrire l'objet.
    @param sommet Le sommet à afficher.
    @return Le flux de sortie o.
    */
    friend std::ostream& operator<<(std::ostream& o, const Sommet& sommet);

private:
    char _nom, _valeur;
    std::vector<Arc*> _arcs;
};
