#pragma once
#include "Board.h"
class Game
{
public:
	Game();
	~Game();
	void event(sf::Event& event, bool& state, sf::RenderWindow& window, sf::View& widok);
	Board plansza;
};

