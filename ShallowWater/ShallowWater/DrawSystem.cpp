#include "DrawSystem.h"
#include <math.h>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>



DrawSystem::DrawSystem(){
	window = new sf::RenderWindow(sf::VideoMode(600, 600), "GGKP");
	loadTextures();
	
}

DrawSystem::~DrawSystem(){}

void DrawSystem::drawScene() {
	System& sys = *system;
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));

	cam.pos = Vec2(w, h) / 2;

	// Relative view
	sf::View view(sf::FloatRect(
		sf::Vector2f(cam.pos.x - w * 1 / cam.scale / 2, cam.pos.y - h * 1 / cam.scale / 2),
		sf::Vector2f(w * 1 / cam.scale, h * 1 / cam.scale)
	));
	view.setRotation((cam.dir * 180 / M_PI));
	window->setView(view);


	fillRect(0, 0, 10000, 10000, Color(30, 30, 30));

	for (int i = 0; i < sys.field.size(); i++) {
		double bottom = 300 + (sys.field[i].bottom - 300);
		double height = 300 + (sys.field[i].height - 300);
		
		// Water
		double k = 1 / (1 + pow(2, -sys.field[i].vel));
		fillRect(i, h - height / 2, 1, height, Color(255* k , 255 * k, 255));

		// Bottom
		fillRect(i, h - bottom / 2, 1, bottom, Color(100, 255, 50));
	}

}

void DrawSystem::drawInterface() {
	
}

void DrawSystem::draw() {
	System& sys = *system;
	window->clear();

	drawScene();
	
	drawInterface();
}
