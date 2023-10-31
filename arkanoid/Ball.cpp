#include "Ball.h"

Ball::Ball() : Entity({POS_X, POS_Y}, "../img/ball.png"){
}

Ball::Ball(float x, float y) : Entity({ x, y}, "../img/ball.png") {
}

void Ball::moveWithPaddle(sf::RenderWindow& window){
	paddleBallmove(window, paddleWidth / 2 - diamater / 2, paddleWidth / 2 + diamater / 2);
}

void Ball::move(sf::RenderWindow& window){
	if (sprite.getPosition().x < 0 || sprite.getPosition().x > window.getSize().x - diamater)
		ballMove.x = -ballMove.x;
	if (sprite.getPosition().y < 0)
		ballMove.y = -ballMove.y;
	if (sprite.getPosition().y > window.getSize().y) {
		isOver = true;
		alive = false;
	}
	sf::Vector2f pos = sprite.getPosition() + ballMove;
	sprite.setPosition(pos);
}



