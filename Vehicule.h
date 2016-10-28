////////////////////////////////////////////////////////////////////////////////
/// @file		Vehicule.h
/// @author		Olivier St-Jean, Massinissa Achour, Jean-François Blain
/// @version	28 octobre 2016
/// @since		18 octobre 2016
////////////////////////////////////////////////////////////////////////////////

#pragma once

/**
@class Vehicule
Représente un véhicule qui doit se déplacer dans un graphe routier.
*/
class Vehicule {
public:
    /**
    Constructeur par défaut.
    */
    Vehicule();

    /**
    Constructeur.
    @param type Le type de carburant utilisé.
    @param autonomieMax L'autonomie maximale après remplissage à une station-service.
    @param autonomieActuelle L'autonomie avec laquelle le véhicule commence son parcours.
    */
    Vehicule(char type, int autonomieMax, int autonomieActuelle);

    /**
    Constructeur de copie.
    @param vehicule Le véhicule à copier.
    */
    Vehicule(Vehicule* vehicule);

    /**
    Destructeur.
    */
    ~Vehicule();

    /**
    Getter.
    @return Le type de carburant utilisé par le véhicule.
    */
    char getTypeCarburant() const;

    /**
    Getter.
    @return L'autonomie maximale du véhicule.
    */
    int getAutonomieMax() const;

    /**
    Getter.
    @return L'autonomie actuelle du véhicule.
    */
    int getAutonomieActuelle() const;

    /**
    Setter.
    @param autonomie La nouvelle autonomie du véhicule.
    */
    void setAutonomieActuelle(int autonomie);

private:
    char  _type;
    int _autonomieMax, _autonomieActuelle;

};

