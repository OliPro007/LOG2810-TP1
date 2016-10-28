////////////////////////////////////////////////////////////////////////////////
/// @file		Chemin.h
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

#include "Sommet.h"
#include "Vehicule.h"

/**
@class Chemin
Représente un chemin entre différents sommets d'un graphe.
*/
class Chemin {
public:
    /**
    Constructeur.
    @param vehicule Le véhicule qui est utilisé pour parcourir le chemin.
    */
    Chemin(Vehicule* vehicule);

    /**
    Constructeur de copie.
    @param chemin Le chemin à copier.
    */
    Chemin(Chemin& chemin);

    /**
    Destructeur.
    */
    ~Chemin();

    /**
    Détermine si le sommet se trouve dans le chemin.
    @param sommet Le sommet qu'on desire vérifier.
    @return @c true si le sommet est dans le chemin, @c false sinon.
    */
    bool contains(Sommet* sommet) const;

    /**
    Getter.
    @return La distance totale du chemin.
    */
    int getDistance() const;

    /**
    Getter.
    @return Le véhicule utilisé pour ce chemin.
    */
    Vehicule* getVehicule() const;

    /**
    Getter.
    @return Les sommets constituant le chemin.
    */
    std::vector<Sommet*> getSommets() const;

    /**
    Ajoute un sommet au chemin.
    La distance et l'autonomie du véhicule seront ajustées en conséquence.
    @param sommet Le sommet à ajouter.
    @param distance La distance parcourue pour se rendre au sommet.
    */
    void addSommet(Sommet* sommet, int distance);

    /**
    Opérateur d'affichage.
    @param o Le flux de sortie vers lequel écrire l'objet.
    @param chemin Le chemin à afficher.
    @return Le flux de sortie o.
    */
    friend std::ostream& operator<<(std::ostream& o, const Chemin& chemin);

private:
    std::vector<Sommet*> _sommets;
    int _distance;
    Vehicule* _vehicule;

};
