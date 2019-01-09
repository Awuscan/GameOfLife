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
	void changeFieldState(int x, int y);
	void randomize(int n); // wype�nienie n p�l na planszy losowo
	int getSizeX() { return sizeX; };; //zwraca szeroko�� planszy 
	int getSizeY() { return sizeY; }; //zwraca wysokos� planszy
	int getGen() { return generation; };
private:
	int sizeX, sizeY; //rozmiar planszy
	int fieldSize; //rozmiar pola w px (+1px ramki )
	unsigned int generation; //numer iteracji
	std::vector<std::vector<Field>> grid; //pola planszy
	std::vector<std::vector<Field>> gridCopy; //kopia p�l planszy dla wyznaczania nast�pnej generacji
	void copyGrid() {gridCopy = grid;}; //kopiuje plansze grid do gridCopy
};