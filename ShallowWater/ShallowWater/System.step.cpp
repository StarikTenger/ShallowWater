#include "geometry.h"
#include "System.h"
#include "random.h"
#include <iostream>
#include <math.h>

void System::step() {
	auto fieldOld = field;

	// Counting height
	for (int i = 0; i < field.size(); i++) {
		field[i].height = field[i].level + field[i].bottom;
	}

	// Pidor equations
	for (int i = 0; i < field.size(); i++) {
		if (i != field.size() - 1) {
			if (i != 0) {
				// Vel
				field[i].vel += (-fieldOld[i].vel * (fieldOld[i + 1].vel - fieldOld[i].vel) / dx -
					g * (fieldOld[i + 1].height - fieldOld[i].height) / dx) * dt;
				field[i].level -= (fieldOld[i + 1].level * fieldOld[i + 1].vel
					- fieldOld[i].level * fieldOld[i].vel) / dx * dt;
			} else
				field[i].level -= (fieldOld[i + 1].level * fieldOld[i + 1].vel) / dx * dt;
			field[i].vel += (fieldOld[i + 1].vel - fieldOld[i].vel) / dx / dx * dt * niggerCoeff;

			// Level
			
			field[i].level += (fieldOld[i + 1].height - fieldOld[i].height) / dx / dx * dt * retardCoeff;
		}
		if (i != 0) {
			if (i != field.size() - 1) {
				// Vel
				field[i].vel += (-fieldOld[i].vel * (fieldOld[i].vel - fieldOld[i - 1].vel) / dx -
					g * (fieldOld[i].height - fieldOld[i - 1].height) / dx) * dt;
				field[i].level -= (fieldOld[i].level * fieldOld[i].vel
					- getLevel(fieldOld, i - 1) * fieldOld[i - 1].vel) / dx * dt;
			} else
				field[i].level -= ( -getLevel(fieldOld, i - 1) * fieldOld[i - 1].vel) / dx * dt;
			field[i].vel += (fieldOld[i - 1].vel - fieldOld[i].vel) / dx / dx * dt * niggerCoeff;

			// Level
			
			field[i].level += (fieldOld[i - 1].height - fieldOld[i].height) / dx / dx * dt * retardCoeff;
		}
	}

	// Height correction
	for (int i = 0; i < field.size(); i++) {
		if (field[i].height - field[i].bottom < 0.1) {
			field[i].vel = 0;
			if (field[i].height - field[i].bottom < 0)
				field[i].height = field[i].bottom;
		}
	}

	// Peak detection
	for (int i = 0; i < field.size(); i++) {
		double h0 = i == 0 ? 0 : field[i - 1].height;
		double h1 = field[i].height;
		double h2 = i == field.size() - 1 ? 0 : field[i + 1].height;
		double threshold = 10;
		if (abs(h0 - h1) > threshold &&
			abs(h2 - h1) > threshold) {
			field[i].height = (h0 + h2) / 2;
			//std::cout << "PEAK DETECTED\n";
		}
	}


	// Mouse pushing
	if (mouse.state)
		for (int i = 0; i < field.size(); i++) {
			double dist = mouse.pos.x - i;
			if (abs(dist) < 2)
				continue;
			
			double acc = 0.01 / dist * dt * 15 * ((600 - mouse.pos.y) - field[i].height) * 0.002;
			field[i].vel += acc * 400;
		}

	// Bottom
	for (int i = 0; i < field.size(); i++) {
		field[i].bottom = 50 + sin(i * 0.03 + time * 3) * 20;
	}

	energy = 0;
	for (int i = 0; i < field.size(); i++) {
		//energy += field[i].vel * field[i].vel * field[i].height;
		//energy += field[i].height * field[i].height * g / 2;
		energy += field[i].height * (i % 2 ? 1 : -1);
	}

	time += dt;
}