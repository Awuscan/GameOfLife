#pragma once
#include <vector>
#include <iostream>
#include "Field.h"

class Board
{
public:
	Board(int size);
	~Board();
	bool initialize(int Y, int X); //tworzy plansze o podanych rozmiarze
	void draw(sf::RenderWindow& window); // rysuje plansze
	void nextStep(); //oblicza nastepny krok
	void fillOut(sf::RenderWindow& window, sf::View& view); //wype�nienie planszy przez u�ytkownika
	int getSizeX(); //zwraca szeroko�� planszy 
	int getSizeY(); //zwraca wysokos� planszy
protected:
	int sizeX, sizeY; //rozmiar planszy
	int sizeField; //rozmiar pola w px (+1px ramki )
	void randomize(); // wype�nienie n p�l na planszy losowo
	std::vector<std::vector<Field>> grid; //pola planszy
	std::vector<std::vector<Field>> gridCopy; //kopia p�l planszy dla wyznaczania nast�pnej generacji
	void copyGrid(); //kopiuje plansze grid do gridCopy
};

