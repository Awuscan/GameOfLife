#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Field.h"

class Board
{
public:
	Board();
	~Board();
	void initialize(); //ustawia rozmiar planszy
	bool initialize(int Y, int X);
	void draw(sf::RenderWindow& window); // rysuje plansze
	void nextStep(); //oblicza nastepny krok
	void fillOut(); //wype³nienie planszy przez u¿ytkopwnika
	void randomize(); // wype³nienie n pól na planszy losowo
	int getSizeX(); //zwraca szerokoœæ planszy 
	int getSizeY(); //zwraca wysokosæ planszy
protected:
	int sizeX, sizeY; //rozmiar planszy
	int sizeField = 6;
	std::vector<std::vector<Field>> grid; //pola planszy
	std::vector<std::vector<Field>> gridCopy; //kopia pól planszy dla wyznaczania nastêpnej generacji
	void copyGrid(); //kopiuje plansze grid do gridCopy
};

