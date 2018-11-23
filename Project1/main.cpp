#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;

	sf::Vector2f pozycjaNaPlanszy;
	sf::Vector2i pozycjaMyszy;

	Board plansza;

	plansza.initialize();
	plansza.randomize();

	int y = plansza.getSizeY(), x = plansza.getSizeX();
	int h = y * 6 + y - 1, w = x * 6 + x - 1;
	int sH = sf::VideoMode::getDesktopMode().height, sW = sf::VideoMode::getDesktopMode().width;
	if (w > (sW - 100) || h > (sH - 100)) {
		w = 80*7+79;
		h = 70*7+69;
	}
	
	sf::RenderWindow window(sf::VideoMode(w,h), "Gra w zycie", sf::Style::Default, settings);
	sf::View widok;
	widok.reset(sf::FloatRect(0, 0, w, h));
	window.setFramerateLimit(50);
	window.clear();

	bool state = true;
	int i = 0;
	window.setView(widok);
	window.requestFocus();

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) { //pauza
					state = !state;
				}else if (event.key.code == sf::Keyboard::Escape) { //zamknięcie
					window.close();
				}else if (event.key.code == sf::Keyboard::Enter) { //pauza i zmaiana ręczna stanu pól
					if (state) {
						state = !state;
						plansza.fillOut();
					}
					else {
						state = !state;
					}
				}else if (event.key.code == sf::Keyboard::Right) {
					if (state)
						state = !state;
					plansza.nextStep();
					//std::cout << i++ << std::endl;
					plansza.draw(window);
					window.display();
				}else if (event.key.code == sf::Keyboard::Numpad4) {
					widok.move(-109.f, 0.f);
				}else if (event.key.code == sf::Keyboard::Numpad8) {
					widok.move(0.f, -109.f);
				}else if (event.key.code == sf::Keyboard::Numpad6) {
					widok.move(109.f, 0.f);
				}else if (event.key.code == sf::Keyboard::Numpad2) {
					widok.move(0.f, 109.f);
				}else if (event.key.code == sf::Keyboard::Numpad7) {
					widok.zoom(8 / 4.f);
				}else if (event.key.code == sf::Keyboard::Numpad9) {
					widok.zoom(2 / 4.f);
				}
				window.setView(widok);
				plansza.draw(window);
				break;	
			case sf::Event::MouseButtonPressed:
				pozycjaMyszy = sf::Mouse::getPosition(window);
				pozycjaNaPlanszy = window.mapPixelToCoords(pozycjaMyszy);
				std::cout << "plansza " << pozycjaNaPlanszy.x << " " << pozycjaNaPlanszy.y << std::endl;
				std::cout << "mysz " << pozycjaMyszy.x << " " << pozycjaMyszy.y << std::endl;
				std::cout << "kliksz na objekt o poz: " << (int)(pozycjaNaPlanszy.x) / 7 << " " << (int)(pozycjaNaPlanszy.y) / 7 << std::endl;
				break;
			case sf::Event::Resized:
				widok.setSize(event.size.width, event.size.height);
				window.setView(widok);
			}	
		}

		//window.setView(widok);

		if (state) {
			window.clear();
			plansza.nextStep();
			//std::cout << i++ << std::endl;
			plansza.draw(window);
			window.display();
		}

	}

	return 0;
}