#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	//tworzenie planszy
	board.initialize();

	//tworzenie okna
	sf::ContextSettings settings;
	settings.antialiasingLevel = 1;

	int y = board.getSizeY(), x = board.getSizeX();
	int h = (y + 3) * (fieldSize+1) - 1, w = (x + 3) * (fieldSize+1) - 1;
	int sH = sf::VideoMode::getDesktopMode().height, sW = sf::VideoMode::getDesktopMode().width;
	if (w > (sW - 100) || h > (sH - 100)) {
		w = 1280;
		h = 720;
	}

	window.create(sf::VideoMode(w, h), "Gra w zycie", sf::Style::Default, settings);
	window.setFramerateLimit(5);
	window.clear();

	//tworzenie widoku
	view.reset(sf::FloatRect(0, 0, w, h));

	//wyœwietlenie planszy
	window.setView(view);
	window.requestFocus();
	board.draw(window);
	window.display();
}

void Game::play()
{
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			this->event(event);
		}

		if (state) { //nastêpny krok
			board.nextStep();
			//std::cout << i++ << std::endl;
			board.draw(window);
			window.display();
		}

	}
}

void Game::event(sf::Event& event)
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
				board.fillOut(window, view);
			}
			else {
				state = !state;
				board.fillOut(window, view);
			}
		}
		else if (event.key.code == sf::Keyboard::Right) { //krok po kroku do przodu
			if (state)
				state = !state;
			board.nextStep();
			//std::cout << i++ << std::endl;
			board.draw(window);
			window.display();
		}
		else if (event.key.code == sf::Keyboard::A) { //przesuwa widok w prawo
			view.move(-109.f, 0.f);
		}
		else if (event.key.code == sf::Keyboard::W) { //przesuwa widok w górê
			view.move(0.f, -109.f);
		}
		else if (event.key.code == sf::Keyboard::D) { //przesuwa widok w lewo
			view.move(109.f, 0.f);
		}
		else if (event.key.code == sf::Keyboard::S) { //przesuwa widok w dó³
			view.move(0.f, 109.f);
		}
		else if (event.key.code == sf::Keyboard::E) { //powiêksza widok 2x
			view.zoom(8 / 4.f);
		}
		else if (event.key.code == sf::Keyboard::Q) { //zmniejsza widok 2x
			view.zoom(2 / 4.f);
		}
		window.setView(view);
		window.clear();
		break;
	case sf::Event::Resized: //obs³uguje zmiane rozmiaru okna
		view.setSize(event.size.width, event.size.height);
		window.setView(view);
		window.clear();
	}
}
