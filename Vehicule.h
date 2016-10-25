#pragma once

class Vehicule {
public:
    Vehicule();
    Vehicule(char type, int autonomieMax, int autonomieActuelle);
    Vehicule(Vehicule* vehicule);
    ~Vehicule();

    char  getTypeCarburant() const;
    int getAutonomieMax() const;

    int getAutonomieActuelle() const;
    void setAutonomieActuelle(int autonomie);

private:
    char  _type;
    int _autonomieMax, _autonomieActuelle;

};

