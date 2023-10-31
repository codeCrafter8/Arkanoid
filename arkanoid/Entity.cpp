#include "Entity.h"

Entity::Entity(sf::Vector2f position, std::string filePath)
{
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Could not load " + filePath + " texture" << std::endl;
        exit(1);
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Entity::paddleBallmove(sf::RenderWindow& window, int leftBorder, int rightBorder){
	float posX = sprite.getPosition().x;
	float posY = sprite.getPosition().y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && posX > leftBorder) {
		posX -= speed;
		sprite.setPosition(posX, posY);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && posX < window.getSize().x - rightBorder) {
		posX += speed;
		sprite.setPosition(posX, posY);
	}
}
