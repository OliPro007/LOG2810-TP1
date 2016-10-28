#include "Arc.h"
#include "Sommet.h"

Arc::Arc()
    : _fin(nullptr), _distance(0) {}

Arc::Arc(Sommet* fin, int distance)
    : _fin(fin), _distance(distance) {}

Arc::~Arc() {
    _fin = nullptr;
}

Sommet* Arc::getFin() const {
    return _fin;
}

int Arc::getDistance() const {
    return _distance;
}

std::ostream& operator<<(std::ostream& o, const Arc& arc) {
    o << arc._fin->getName();
    return o;
}
