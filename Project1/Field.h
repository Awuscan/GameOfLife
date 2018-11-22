#pragma once
#include <SFML/Graphics.hpp>

class Field
{
public:
	Field(int x,int y,int size);
	~Field();
	void draw(sf::RenderWindow& window);
	void changeState(bool newState);
	bool getState();
private:
	sf::RectangleShape block;
	bool state;
	bool wasAlive = false;
	int X, Y;
	sf::Color colorDead{ 100, 100, 100 };
	sf::Color colorAlive{ 255, 255, 255 };
	sf::Color colorWasAlive{ 130, 33, 168 };
};

