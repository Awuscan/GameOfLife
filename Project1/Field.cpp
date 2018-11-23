#include "Field.h"



Field::Field(int x, int y, int size)
{
	X = x;
	Y = y;
	state = false;
	block.setSize(sf::Vector2f(size, size));
	//block.setOutlineColor(sf::Color::Black);
	//block.setOutlineThickness(0);
	block.setFillColor(colorDead);
	block.setPosition(size*X+X, size*Y+Y);
}


Field::~Field()
{
}

void Field::draw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Field::changeState(bool newState)
{
	state = newState;
	if (state) {
		block.setFillColor(colorAlive);
		wasAlive = true;
	}
	else {
		if (wasAlive) {
			block.setFillColor(colorWasAlive);
		}
		else {
			block.setFillColor(colorDead);
		}
	}

}

bool Field::getState()
{
	return state;
}
