#pragma once

#include "Sommet.h"
class Sommet;
class Arc {

public:
    Arc();
    Arc(Sommet* fin, int distance);
    ~Arc();

    Sommet* getFin() const;
    int getDistance() const;

    friend std::ostream& operator<<(std::ostream& o, const Arc& arc);

private:
    Sommet* _fin;
    int _distance;
};
