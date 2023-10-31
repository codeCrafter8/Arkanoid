#include "ExtraPoints.h"

void ExtraPoints::set(sf::RenderWindow& window, int value, sf::Vector2f brickPos){
	std::string caption = "+";
	caption += std::to_string(value);
	Text pointsT(window, caption, "../fonts/Audiowide.ttf", 25, 0, 150, sf::Color(25, 173, 227));
	if (!font.loadFromFile("../fonts/Audiowide.ttf")) {
		std::cerr << "Could not load Audiowide font" << std::endl;
		exit(1);
	}
	pointsT.text.setOutlineColor(sf::Color::White);
	pointsT.text.setPosition(brickPos);
	Points = pointsT.text;
	Points.setFont(font);
}
