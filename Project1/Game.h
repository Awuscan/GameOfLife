#pragma once
#include "Board.h"
#include <TGUI/TGUI.hpp>

class Game
{
public:
	Game();
	~Game();
	void start(); //inicjalizacja gry
	void play(); //rozpocz�cie
private:
	bool state = false; //status gry(w toku/pauza)
	int framerate = 30;
	const int fieldSize = 7; //rozmiar pola
	sf::RenderWindow window; //objekt okna
	sf::View view; //objekt widoku w oknie
	Board board{ fieldSize }; //objekt planszy
	void menu(); //wy�wietla menu startowe
	void loadMenu(tgui::Gui &gui);
	void randomize(tgui::EditBox::Ptr number);
};

