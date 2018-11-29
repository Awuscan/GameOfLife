#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::event(sf::Event& event, bool& state, sf::RenderWindow& window, sf::View& widok)
{
	switch (event.type) {
	case sf::Event::Closed: //obs³uguje zamkniêcie okna
		window.close();
		break;
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Space) { //pauza
			state = !state;
		}
		else if (event.key.code == sf::Keyboard::Escape) { //zamyka okno
			window.close();
		}
		else if (event.key.code == sf::Keyboard::Enter) { //pauza i zmaiana rêczna stanu pól
			if (state) {
				state = !state;
				plansza.fillOut(window);
			}
			else {
				state = !state;
				plansza.fillOut(window);
			}
		}
		else if (event.key.code == sf::Keyboard::Right) { //krok po kroku do przodu
			if (state)
				state = !state;
			plansza.nextStep();
			//std::cout << i++ << std::endl;
			plansza.draw(window);
			window.display();
		}
		else if (event.key.code == sf::Keyboard::Numpad4) { //przesuwa widok w prawo
			widok.move(-109.f, 0.f);
		}
		else if (event.key.code == sf::Keyboard::Numpad8) { //przesuwa widok w górê
			widok.move(0.f, -109.f);
		}
		else if (event.key.code == sf::Keyboard::Numpad6) { //przesuwa widok w lewo
			widok.move(109.f, 0.f);
		}
		else if (event.key.code == sf::Keyboard::Numpad2) { //przesuwa widok w dó³
			widok.move(0.f, 109.f);
		}
		else if (event.key.code == sf::Keyboard::Numpad7) { //powiêksza widok 2x
			widok.zoom(8 / 4.f);
		}
		else if (event.key.code == sf::Keyboard::Numpad9) { //zmniejsza widok 2x
			widok.zoom(2 / 4.f);
		}
		window.setView(widok);
		window.clear();
		break;
	case sf::Event::Resized: //obs³uguje zmiane rozmiaru okna
		widok.setSize(event.size.width, event.size.height);
		window.setView(widok);
		window.clear();
	}
}
