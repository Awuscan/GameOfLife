#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 1;

	sf::Vector2f posOnBoard;
	sf::Vector2i posMouse;
	
	Game gra;

	gra.plansza.initialize();

	int y = gra.plansza.getSizeY(), x = gra.plansza.getSizeX();
	int h = y * 6 + y - 1, w = x * 6 + x - 1;
	int sH = sf::VideoMode::getDesktopMode().height, sW = sf::VideoMode::getDesktopMode().width;
	if (w > (sW - 100) || h > (sH - 100)) {
		w = 1280;
		h = 720;
	}
	
	sf::RenderWindow window(sf::VideoMode(w,h), "Gra w zycie", sf::Style::Default, settings);
	sf::View widok;
	widok.reset(sf::FloatRect(0, 0, w, h));
	window.setFramerateLimit(5);
	window.clear();

	bool state = false;
	int i = 0;
	window.setView(widok);
	window.requestFocus();
	gra.plansza.draw(window);
	window.display();

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			gra.event(event, state, window, widok);
		}

		if (state) { //następny krok
			gra.plansza.nextStep(); 
			//std::cout << i++ << std::endl;
			gra.plansza.draw(window);
			window.display();
		}

	}

	return 0;
}