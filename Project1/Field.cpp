#include "Field.h"



Field::Field(int x, int y)
{
	X = x;
	Y = y;
	state = false;
	block.setSize(sf::Vector2f(size, size));
	block.setOutlineColor(sf::Color::Black);
	block.setOutlineThickness(2);
	block.setFillColor(colorDead);
	block.setPosition(size*X, size*Y);

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

bool Field::readState()
{
	return state;
}
