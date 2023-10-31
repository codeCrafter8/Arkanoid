#include "Collision.h"

void Collision::paddleBallCollision(Paddle& paddle, Ball& ball){
	sf::Vector2f paddlePos = paddle.sprite.getPosition();
	sf::Vector2f ballPos = ball.sprite.getPosition();

	if (ballPos.x + ball.diamater >= paddlePos.x && ballPos.x <= paddlePos.x + paddle.width && ballPos.y + ball.diamater - 1 >= paddlePos.y && ballPos.y <= paddlePos.y + 3) {
		ball.ballMove.y = -ball.ballMove.y;
		ballPos = ballPos + ball.ballMove;
		ball.sprite.setPosition(ballPos);
	}
}

float Collision::clamp(float value, float min, float max) {
	return std::max(min, std::min(max, value));
}

bool Collision::brickBallCollision(Brick& brick, Ball& ball){
	sf::Vector2f ballCenter(ball.sprite.getPosition().x + ball.diamater/2, ball.sprite.getPosition().y + ball.diamater/2);
	sf::Vector2f closestPoint(clamp(ballCenter.x, brick.posX, brick.posX + brick.sizeX), clamp(ballCenter.y, brick.posY, brick.posY + brick.sizeY));
	sf::Vector2f distance(ballCenter.x - closestPoint.x, ballCenter.y - closestPoint.y);
	float distanceSquared = pow(distance.x, 2) + pow(distance.y, 2);
	if (distanceSquared <= 2 * pow(ball.diamater/2, 2)){
		brick.brick.setPosition(-1000, -1000);
		brick.posX = -1000;
		brick.posY = -1000;
		if (distance.x < distance.y)
			ball.ballMove.y = -ball.ballMove.y;
		else
			ball.ballMove.x = -ball.ballMove.x;
		ball.sprite.setPosition(ball.sprite.getPosition() + ball.ballMove);
		return true;
	}
	return false;
}

bool Collision::paddleBonusCollision(Paddle& paddle, Bonus& bonus){
	sf::Vector2f paddlePos = paddle.sprite.getPosition();
	sf::Vector2f bonusPos = bonus.sprite.getPosition();
	if (bonusPos.y + bonus.height >= paddlePos.y && bonusPos.y <= paddlePos.y + paddle.height && bonusPos.x + bonus.width >= paddlePos.x && bonusPos.x <= paddlePos.x + paddle.width) {
		bonus.sprite.setPosition(-1000, -1000);
		bonus.posX = -1000;
		bonus.posY = -1000;
		return true;
	}
	return false;
}


