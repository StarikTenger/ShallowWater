#include "geometry.h"
#include "System.h"
#include "random.h"
#include <iostream>
#include <math.h>

void System::step() {
	auto fieldOld = field;
	for (int i = 0; i < field.size(); i++) {
		if (i != field.size() - 1) {
			if (i != 0) {
				// Vel
				field[i].vel += (-fieldOld[i].vel * (fieldOld[i + 1].vel - fieldOld[i].vel) / dx -
					g * (fieldOld[i + 1].height - fieldOld[i].height) / dx) * dt;
				
			}
			field[i].vel += (fieldOld[i + 1].vel - fieldOld[i].vel) / dx / dx * dt * niggerCoeff;

			// Height
			field[i].height -= (fieldOld[i + 1].height * fieldOld[i + 1].vel - fieldOld[i].height * fieldOld[i].vel) / dx * dt;
			field[i].height += (fieldOld[i + 1].height - fieldOld[i].height) / dx / dx * dt * retardCoeff;
		}
		if (i != 0) {
			if (i != field.size() - 1) {
				// Vel
				field[i].vel += (-fieldOld[i].vel * (fieldOld[i].vel - fieldOld[i - 1].vel) / dx -
					g * (fieldOld[i].height - fieldOld[i - 1].height) / dx) * dt;
				
			}
			field[i].vel += (fieldOld[i - 1].vel - fieldOld[i].vel) / dx / dx * dt * niggerCoeff;

			// Height
			field[i].height -= (fieldOld[i].height * fieldOld[i].vel - fieldOld[i - 1].height * fieldOld[i - 1].vel) / dx * dt;
			field[i].height += (fieldOld[i - 1].height - fieldOld[i].height) / dx / dx * dt * retardCoeff;
		}
	}

	for (int i = 0; i < field.size(); i++) {

	}

	energy = 0;
	for (int i = 0; i < field.size(); i++) {
		energy += field[i].vel * field[i].vel * field[i].height;
		energy += field[i].height * field[i].height * g / 2;
	}

}