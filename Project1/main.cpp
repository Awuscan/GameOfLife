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
			case sf::Event::Closed: //obsługuje zamknięcie okna
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) { //pauza
					state = !state;
				}else if (event.key.code == sf::Keyboard::Escape) { //zamyka okno
					window.close();
				}else if (event.key.code == sf::Keyboard::Enter) { //pauza i zmaiana ręczna stanu pól
					if (state) {
						state = !state;
						plansza.fillOut();
					}
					else {
						state = !state;
					}
				}else if (event.key.code == sf::Keyboard::Right) { //krok po kroku do przodu
					if (state)
						state = !state;
					plansza.nextStep();
					//std::cout << i++ << std::endl;
					plansza.draw(window);
					window.display();
				}else if (event.key.code == sf::Keyboard::Numpad4) { //przesuwa widok w prawo
					widok.move(-109.f, 0.f);
				}else if (event.key.code == sf::Keyboard::Numpad8) { //przesuwa widok w górę
					widok.move(0.f, -109.f);
				}else if (event.key.code == sf::Keyboard::Numpad6) { //przesuwa widok w lewo
					widok.move(109.f, 0.f);
				}else if (event.key.code == sf::Keyboard::Numpad2) { //przesuwa widok w dół
					widok.move(0.f, 109.f);
				}else if (event.key.code == sf::Keyboard::Numpad7) { //powiększa widok 2x
					widok.zoom(8 / 4.f);
				}else if (event.key.code == sf::Keyboard::Numpad9) { //zmniejsza widok 2x
					widok.zoom(2 / 4.f);
				}
				window.setView(widok);
				window.clear();
				break;	
			case sf::Event::MouseButtonPressed: //sprawdza klikniete pole
				pozycjaMyszy = sf::Mouse::getPosition(window);
				pozycjaNaPlanszy = window.mapPixelToCoords(pozycjaMyszy);
				std::cout << "plansza " << pozycjaNaPlanszy.x << " " << pozycjaNaPlanszy.y << std::endl;
				std::cout << "mysz " << pozycjaMyszy.x << " " << pozycjaMyszy.y << std::endl;
				std::cout << "kliksz na objekt o poz: " << (int)(pozycjaNaPlanszy.x) / 7 << " " << (int)(pozycjaNaPlanszy.y) / 7 << std::endl;
				break;
			case sf::Event::Resized: //obsługuje zmiane rozmiaru okna
				widok.setSize(event.size.width, event.size.height);
				window.setView(widok);
				window.clear();
			}	
		}

		//window.setView(widok);

		if (state) { //następny krok
			plansza.nextStep(); 
			//std::cout << i++ << std::endl;
			plansza.draw(window);
			window.display();
		}

	}

	return 0;
}