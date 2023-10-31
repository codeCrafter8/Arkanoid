#include "Text.h"

Text::Text(sf::RenderWindow& window, std::string caption, std::string fontPath, int fontSize, int xOfsset, int yOffset, sf::Color color){
	if (!font.loadFromFile(fontPath)) {
		std::cerr << "Could not load" << fontPath << "font" << std::endl;
		exit(1);
	}
	text.setString(caption);
	text.setFont(font);
	text.setCharacterSize(fontSize);
	textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(window.getSize().x / 2.0f + xOfsset, window.getSize().y / 2.0f + yOffset));
	text.setFillColor(color);
}
