#include "Paddle.h"

#define POS_X 322
#define POS_Y 530

Paddle::Paddle() : Entity({POS_X, POS_Y}, "../img/paddle.png") {
}

void Paddle::move(sf::RenderWindow& window){
	paddleBallmove(window, 0, width);
}


