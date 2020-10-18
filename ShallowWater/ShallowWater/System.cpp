#include "System.h"
#include "geometry.h"
#include "random.h"

#include <iostream>
#include <fstream>
#include <algorithm>


System::System() {
	field = std::vector<Cell>(6000);

	for (int i = 0; i < 6000; i++) {
		double x = (i - 3000) * 0.004;
		field[i].height -= pow(2, -x * x) * 50;
		//field[i].vel += pow(2, -x * x) * 10;
		//field[i].vel = 10;
	}

}

System::~System() {
}

