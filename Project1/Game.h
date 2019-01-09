#pragma once
#include "Board.h"
#include <TGUI/TGUI.hpp>

class Game
{
public:
	Game();
	~Game();
	void start(); //inicjalizacja gry
	void play(); //rozpoczêcie
private:
	bool state = false; //status gry(w toku/pauza)
	int framerate = 10;
	const int fieldSize = 7; //rozmiar pola
	sf::RenderWindow window; //objekt okna
	sf::View view; //objekt widoku w oknie
	Board board{ fieldSize }; //objekt planszy

	void menu(); //wyœwietla menu startowe
	void loadMenu(tgui::Gui &gui);
	void randomize(tgui::EditBox::Ptr number);
	void playpause(tgui::BitmapButton::Ptr button);
	void playspeed(tgui::Slider::Ptr slider);
	void playnext(tgui::BitmapButton::Ptr button);
};