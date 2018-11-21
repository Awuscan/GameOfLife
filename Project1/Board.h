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
	void draw(sf::RenderWindow& window); // rysuje plansze
	void nextStep(); //oblicza nastepny krok
	bool initialize(int Y, int X);
	void fillOut();
	void randomize();
protected:
	int sizeX, sizeY; //rozmiar planszy
	std::vector<std::vector<Field>> grid;
	std::vector<std::vector<Field>> gridCopy;
	void copyGrid();
};

