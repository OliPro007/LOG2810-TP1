#pragma once

#include "Sommet.h"

class Arc {
public:
	Arc();
	Arc(Sommet* fin, int distance);
	~Arc();

	Sommet* getFin();
	int getDistance();

private:
	Sommet* _fin;
	int _distance;

};