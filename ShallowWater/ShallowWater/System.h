#pragma once
#include <vector>
#include <fstream>
#include "geometry.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class System{
public:
	double dt = 0.001;
	double dx = 1;
	double g = 1;
	double retardCoeff = 0;
	double niggerCoeff = 10;

	double energy = 0;
	std::vector<Cell> field;

	System();
	~System();

	void step();
	
};