#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 1;

	Board plansza;

	plansza.initialize();
	plansza.randomize();
	
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Title", sf::Style::Default, settings);
	window.setFramerateLimit(5);
	window.clear();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

	
	/*(shape.getGlobalBounds().contains(Mouse))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (shape.getFillColor() == color1) {
					shape.setFillColor(color2);
				}
				else {
					shape.setFillColor(color1);
				}
			}
		}
	*/
		

		plansza.nextStep();
		std::cout << "nastêpna" << std::endl;
		plansza.draw(window);

		window.display();
	}

	return 0;
}