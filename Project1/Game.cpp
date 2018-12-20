#include "Game.h"

Game::Game()
{
	//tworzenie okna
	sf::ContextSettings settings;
	settings.antialiasingLevel = 1;
	window.create(sf::VideoMode(300, 480), "Gra w zycie", sf::Style::Close, settings);
	window.setFramerateLimit(30);
	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(64, 64, icon.getPixelsPtr());
}


Game::~Game()
{
}

void Game::start()
{
	window.clear();

	//wyœwietlenie menu
	menu();

	//zmiana rozmiaru okna 
	int y = board.getSizeY(), x = board.getSizeX();
	int h = (y + 2) * (fieldSize+1) - 1, w = (x + 2) * (fieldSize+1) - 1;
	int windowHeight = sf::VideoMode::getDesktopMode().height, windowWidth = sf::VideoMode::getDesktopMode().width;
	if (w > (windowWidth - 100) || h > (windowHeight - 100)) {
		windowWidth -= 100;
		windowHeight -= 100;
	}
	else if (w < 100 || h < 100 ) {
		windowWidth = 200;
		windowHeight = 200;
	}
	else {
		windowWidth = w;
		windowHeight = h;
	}

	window.setSize(sf::Vector2u(windowWidth, windowHeight));
	framerate = 6;
	window.setFramerateLimit(framerate);
	window.clear();

	//tworzenie widoku
	w = (w / 2) - (windowWidth / 2);
	h = (h / 2) - (windowHeight / 2);
	view.reset(sf::FloatRect(w, h, windowWidth, windowHeight));

	//wyœwietlenie planszy
	window.setView(view);
	window.requestFocus();
	board.draw(window);
	window.display();
}

void Game::play()
{
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
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
						state = false;
						board.fillOut(window, view);
						state = true;
					}
					else {
						board.fillOut(window, view);
						state = true;
					}
				}
				else if (event.key.code == sf::Keyboard::Up) { //krok po kroku do przodu
					if (state) state = !state;
					board.nextStep();
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
				else if (event.key.code == sf::Keyboard::Left) {
					framerate -= 1;
					if (framerate <=0) { framerate = 1; }
					window.setFramerateLimit(framerate);
					std::cout << framerate << std::endl;
					
				}
				else if (event.key.code == sf::Keyboard::Right) {
					framerate += 2;
					window.setFramerateLimit(framerate);
					std::cout << framerate << std::endl;
				}
				window.setView(view);

				break;
			case sf::Event::Resized: //obs³uguje zmiane rozmiaru okna
				view.setSize(event.size.width, event.size.height);
				window.setView(view);
				window.clear();
				board.draw(window);
				window.display();
			}
		}

		if (state) { //nastêpny krok
			board.nextStep();
			//std::cout << i++ << std::endl;

		}
			window.clear();
			board.draw(window);
			window.display();
		

	}
}


void Game::menu()
{
	//tworzenie gui
	tgui::Gui gui(window);

	auto sliderHeight = tgui::Slider::create();
	sliderHeight->setPosition({ "15%", "16%" });
	sliderHeight->setMinimum(1);
	sliderHeight->setMaximum(1000);
	sliderHeight->setSize({ "70%", "3%" });//setSize(200, 18);
	sliderHeight->setValue(100);
	gui.add(sliderHeight);

	auto sliderWidth = tgui::Slider::copy(sliderHeight);
	sliderWidth->setPosition({ "16%", "41%" });
	gui.add(sliderWidth);

	auto labelHeight = tgui::Label::create();
	labelHeight->setText("Board Height: " + std::to_string((int)sliderHeight->getValue()));
	labelHeight->setPosition({ "16%", "10%" });
	labelHeight->setTextSize(18);
	gui.add(labelHeight);

	auto labelWidth = tgui::Label::copy(labelHeight);
	labelWidth->setText("Board Width: " + std::to_string((int)sliderWidth->getValue()));
	labelWidth->setPosition({ "16%", "35%" });
	gui.add(labelWidth);

	auto button = tgui::Button::create("START");
	button->setSize({ "50%", "16.67%" });
	button->setPosition({ "25%", "70%" });
	gui.add(button);

	while (window.isOpen())
	{
		int y = (int)sliderHeight->getValue();
		int x = (int)sliderWidth->getValue();
		labelHeight->setText("Board Height: " + std::to_string(y));
		labelWidth->setText("Board Width: " + std::to_string(x));

		sf::Event event;
		while (window.pollEvent(event))
		{
			gui.handleEvent(event);
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonReleased) {
				sf::Vector2i posMouse = sf::Mouse::getPosition(window);
				sf::Vector2f pos = sf::Vector2f(posMouse);
				std::cout << "COO" << std::endl;
				if (button->mouseOnWidget(pos)) {
					board.initialize(y,x);
					return;
				}
			}
		}

		window.clear();
		gui.draw();
		window.display();
	}

}

