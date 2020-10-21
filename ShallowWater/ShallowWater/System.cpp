#include "System.h"
#include "geometry.h"
#include "random.h"

#include <iostream>
#include <fstream>
#include <algorithm>

double interpolateCubic(double left, double right, double val) {
	val = (-2 * val * val * val + 3 * val * val);
	//val = val > 0.5 ? 1 : 0;
	return  left + (right - left) * val;
}

System::System() {
	field = std::vector<Cell>(600);

	for (int i = 0; i < 600; i++) {
		double x = (i - 300) * 0.004;
		//field[i].height += pow(1.7, -x * x) * 100 - 200;
		//field[i].height +=  - 250;
		//field[i].vel += pow(2, -x * x) * 10;
		field[i].height = 300;
		field[i].bottom = interpolateCubic(10, 350, i / 600.0);
		//field[i].height += sin(x * 4) * 50 - 250;
		//field[i].height = interpolateCubic(250, 350, i / 600.0);
	}

}

System::~System() {
}

double System::getLevel(std::vector<Cell>& f, int i) {
	return f[i].height - f[i].bottom;
}
