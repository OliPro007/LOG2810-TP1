////////////////////////////////////////////////////////////////////////////////
/// @file		Arc.h
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Sommet.h"

class Sommet;

/**
@class Arc
Représente un arc (liaison) valué et orienté entre deux sommets.
*/
class Arc {
public:
    /**
    Constructeur par défaut.
    */
    Arc();

    /**
    Constructeur.
    @param fin Le sommet vers lequel l'arc pointe.
    @param distance La valeur de l'arc correspondant à la distance entre 2 points.
    */
    Arc(Sommet* fin, int distance);

    /**
    Destructeur.
    */
    ~Arc();

    /**
    Getter.
    @return Le sommet de destination.
    */
    Sommet* getFin() const;

    /**
    Getter
    @return La valeur de l'arc.
    */
    int getDistance() const;

    /**
    Opérateur d'affichage
    @param o Le flux de sortie vers lequel écrire l'objet.
    @param arc L'arc à afficher.
    @return Le flux de sortie o.
    */
    friend std::ostream& operator<<(std::ostream& o, const Arc& arc);

private:
    Sommet* _fin;
    int _distance;

};
