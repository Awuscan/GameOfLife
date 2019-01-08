#pragma once
#include <SFML/Graphics.hpp>

class Field
{
public:
	Field(int x,int y,int size);
	~Field();
	void draw(sf::RenderWindow& window); //rysuje pole
	operator bool() const { return state; } 
	bool operator!() const { return !state; }
	Field &operator=(const bool &newState);
private:
	sf::RectangleShape block;  //obiekt prostokata 
	bool state; //stan pola
	bool wasAlive = false; //czy pole �y�o wcze�niej
	int coordX, coordY; //koordynaty pola na planszy
	sf::Color colorDead{ 65, 65, 65 }; //kolor pola gdy jest martwe
	sf::Color colorAlive{ 239, 239, 239 }; //kolor pola gdy jest �ywe
	sf::Color colorWasAlive{ 178, 33,82 }; //kolor pola gdy jest martwe, ale �y�o wcze�niej
	//sf::Color colorWasAlive{ 130, 33, 168 }; //kolor pola gdy jest martwe, ale �y�o wcze�niej
};

