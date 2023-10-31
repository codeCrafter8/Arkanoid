#include "Bonus.h"

Bonus::Bonus(){}

Bonus::Bonus(sf::Vector2f position, std::string filePath){
    posX = position.x;
    posY = position.y;
    ballPosX = position.x;
    ballPosY = position.y;
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Could not load " + filePath + " texture" << std::endl;
        exit(1);
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Bonus::move(){
    posY += speed;
    sprite.setPosition({ posX, posY });
}

void Bonus::increasePaddleWidth(Paddle &paddle){
    paddle.sprite.setScale(1.2, 1);
    paddle.width = 1.2 * paddle.width;
}

void Bonus::reducePaddleWidth(Paddle& paddle){
    paddle.sprite.setScale(1, 1);
    paddle.width = paddle.constWidth;
}

void Bonus::slowBall(Ball& ball){
    if (ball.ballMove.x > 0 && ball.ballMove.y > 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(- slowingValue, -slowingValue);
    }
    else if (ball.ballMove.x > 0 && ball.ballMove.y < 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(- slowingValue, slowingValue);
    }
    else if (ball.ballMove.x < 0 && ball.ballMove.y < 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(slowingValue, slowingValue);
    }
    else if (ball.ballMove.x < 0 && ball.ballMove.y > 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(slowingValue, -slowingValue);
    }
}

void Bonus::speedBall(Ball& ball){
    if (ball.ballMove.x > 0 && ball.ballMove.y > 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(slowingValue, slowingValue);
    }
    else if (ball.ballMove.x > 0 && ball.ballMove.y < 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(slowingValue, -slowingValue);
    }
    else if (ball.ballMove.x < 0 && ball.ballMove.y < 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(-slowingValue, -slowingValue);
    }
    else if (ball.ballMove.x < 0 && ball.ballMove.y > 0) {
        ball.ballMove = ball.ballMove + sf::Vector2f(-slowingValue, slowingValue);
    }
}

void Bonus::doubleBall(Ball& ball2){
    ball2.sprite.setPosition(ballPosX, ballPosY);
    ball2.ballMove = sf::Vector2f{ -0.15, 0.25 };
    ball2.alive = true;
}


