#pragma once
#include <vector>
#include <fstream>
#include "geometry.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Mouse.h"

class System {
public:
	double dt = 0.0001;
	double time = 0;
	double dx = 1;
	double g = 1;
	double retardCoeff = 100;
	double niggerCoeff = 1;

	Mouse mouse;

	double energy = 0;
	std::vector<Cell> field;

	System();
	~System();

	double getLevel(std::vector<Cell>& f, int i);
	void step();
	
};