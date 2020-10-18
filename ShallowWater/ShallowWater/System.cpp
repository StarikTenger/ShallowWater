#include "System.h"
#include "geometry.h"
#include "random.h"

#include <iostream>
#include <fstream>
#include <algorithm>


System::System() {
	field = std::vector<Cell>(600);

	for (int i = 0; i < 600; i++) {
		double x = (i - 300) * 0.04;
		//field[i].height += pow(20, -x * x) * 50 - 250;
		//field[i].height +=  - 250;
		field[i].vel += pow(2, -x * x) * 10;
		//field[i].vel = 10;
		//field[i].height += sin(x) * 50;
	}

}

System::~System() {
}

