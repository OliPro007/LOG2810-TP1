#pragma once

#include "Sommet.h"

class Arc {
public:
    Arc();
    Arc(Sommet* fin, int distance);
    ~Arc();

    Sommet* getFin() const;
    int getDistance() const;

private:
    Sommet* _fin;
    int _distance;
};
