#pragma once
#include <SFML/Graphics.hpp>

class Field
{
public:
	Field(int x,int y,int size);
	~Field();
	void draw(sf::RenderWindow& window); //rysuje pole
	void changeState(bool newState); //zmienia stan pola
	bool getState(); //zwraca stan pola
private:
	sf::RectangleShape block;  //objekt prostokata 
	bool state; //stan pola
	bool wasAlive = false; //czy pole ¿y³o wczeœniej
	int X, Y; //koordynaty pola na planszy
	sf::Color colorDead{ 100, 100, 100 }; //kolor pola gdy jest martwe
	sf::Color colorAlive{ 255, 255, 255 }; //kolor pola gdy jest ¿ywe
	sf::Color colorWasAlive{ 130, 33, 168 }; //kolor pola gdy jest martwe, ale ¿y³o wczeœniej
};

