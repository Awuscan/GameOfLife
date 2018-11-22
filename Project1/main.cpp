#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

	Board plansza;

	plansza.initialize();
	plansza.randomize();

	int y = plansza.getSizeY(), x = plansza.getSizeX();
	int h = y * 6 + y - 1, w = x * 6 + x - 1;
	int sH = sf::VideoMode::getDesktopMode().height, sW = sf::VideoMode::getDesktopMode().width;

	
	sf::RenderWindow window(sf::VideoMode(w,h), "Gra w życie", sf::Style::Default, settings);
	window.setFramerateLimit(5);
	window.clear();

	bool state = true;
	int i = 0;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) { //pauza
					state = !state;
				}else if (event.key.code == sf::Keyboard::Escape){ //zamknięcie
					window.close();
				}else if (event.key.code == sf::Keyboard::Enter){ //pauza i zmaiana ręczna stanu pól
					if (state) {
						state = !state;
						plansza.fillOut();
					}else {
						state = !state;
					}
				}else if (event.key.code == sf::Keyboard::Right) {
					if (state)
						state = !state;
					plansza.nextStep();
					std::cout << i++ << std::endl;
					plansza.draw(window);
					window.display();
					}
				break;		
			}	
		}

		if (state) {
			plansza.nextStep();
			std::cout << i++ << std::endl;
			plansza.draw(window);
			window.display();
		}

	}

	return 0;
}