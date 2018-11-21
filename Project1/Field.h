#pragma once
#include <SFML/Graphics.hpp>

class Field
{
public:
	Field(int x,int y);
	~Field();
	void draw(sf::RenderWindow& window);
	void changeState(bool newState);
	bool readState();
private:
	sf::RectangleShape block;
	bool state;
	bool wasAlive =false;
	int X, Y;
	int size = 10;
	sf::Color colorDead{ 100, 100, 100 };
	sf::Color colorAlive{ 255, 255, 255 };
	sf::Color colorWasAlive{ 130, 33, 168 };
};

