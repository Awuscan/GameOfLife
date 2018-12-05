#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	void start(); //inicjalizacja gry
	void play(); //rozpoczêcie
private:
	sf::RenderWindow window; //objekt okna
	sf::View view; //objekt widoku w oknie
	bool state; //status gry(w toku/pauza)
	int fieldSize = 6;
	Board board{ fieldSize }; //objekt planszy
	void event(sf::Event& event); //obs³uga zdarzeñ u¿ytkownika
};

