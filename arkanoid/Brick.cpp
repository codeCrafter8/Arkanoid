#include "Brick.h"

#define SIZE_X 76
#define SIZE_Y 30

Brick::Brick() {}

Brick::Brick(float x, float y, sf::Color brickColor, int level){
	this->level = level;
	posX = x;
	posY = y;
	posConsX = x;
	posConsY = y;
	brick.setSize(sf::Vector2f(SIZE_X, SIZE_Y));
	color = brickColor;
	brick.setFillColor(brickColor);
	brick.setOutlineColor(sf::Color::Black);
	brick.setOutlineThickness(outline);
	brick.setPosition(x, y);
}

