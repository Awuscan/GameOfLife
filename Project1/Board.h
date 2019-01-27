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
	void changeFieldState(int x, int y); //zmienia stan wybranego pola
	void randomize(int n); // wype³nienie n pól na planszy losowo
	int getSizeX() { return sizeX; }; //zwraca szerokoœæ planszy 
	int getSizeY() { return sizeY; }; //zwraca wysokoœæ planszy
	int getGen() { return generation; }; //zwraca numer generacji
	void patterns(int pattern, int x, int y); //wstawia wybrany wzór 
	void reset(); //resetuje plansze
private:
	const bool wrap = true; //zawijanie krawedzi
	int sizeX, sizeY; //rozmiar planszy
	int fieldSize; //rozmiar pola w px (+1px ramki )
	unsigned int generation = 0; //numer iteracji
	std::vector<std::vector<Field>> grid; //pola planszy
	std::vector<std::vector<Field>> gridCopy; //kopia pól planszy dla wyznaczania nastêpnej generacji
	void copyGrid() {gridCopy = grid;}; //kopiuje plansze grid do gridCopy
};