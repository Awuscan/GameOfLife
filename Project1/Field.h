#pragma once
#include <SFML/Graphics.hpp>

class Field
{
public:
	Field(int x,int y,int size);
	~Field();
	void draw(sf::RenderWindow& window) { window.draw(block); }; //rysuje pole
	void reset();
	operator bool() const { return state; };
	bool operator!() const { return !state; };
	Field &operator=(const bool& newState);
	Field &operator=(const Field& p);
private:
	sf::RectangleShape block;  //obiekt prostokata 
	bool state; //stan pola
	bool wasAlive = false; //czy pole ¿y³o wczeœniej
	int coordX, coordY; //koordynaty pola na planszy
	sf::Color colorDead{ 65, 65, 65 }; //kolor pola gdy jest martwe
	sf::Color colorAlive{ 239, 239, 239 }; //kolor pola gdy jest ¿ywe
	sf::Color colorWasAlive{ 178, 33,82 }; //kolor pola gdy jest martwe, ale ¿y³o wczeœniej
};