#include "EndScreen.h"

EndScreen::EndScreen(sf::RenderWindow& window, std::string text){
	Text endTextT(window, text, "../fonts/PressStart2P.ttf", 52, 0, -50, sf::Color(125, 11, 161));
	if (!font.loadFromFile("../fonts/PressStart2P.ttf")) {
		std::cerr << "Could not load audio font" << std::endl;
		exit(1);
	}
	endText = endTextT.text;
	endText.setFont(font);

	Text askT(window, "Do you want to play again?", "../fonts/Oswald.ttf", 23, 0, 30, sf::Color::White);
	Text answerYesT(window, "Yes", "../fonts/Oswald.ttf", 23, -40, 60, sf::Color::White);
	Text answerNoT(window, "No", "../fonts/Oswald.ttf", 23, 40, 60, sf::Color::White);
	if (!font2.loadFromFile("../fonts/Oswald.ttf")) {
		std::cerr << "Could not load audio font" << std::endl;
		exit(1);
	}
	ask = askT.text;
	ask.setFont(font2);
	yes = answerYesT.text;
	yes.setFont(font2);
	no = answerNoT.text;
	no.setFont(font2);

	yesRect = answerYesT.textRect;
	noRect = answerNoT.textRect;
}

void EndScreen::update(sf::RenderWindow& window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i position = sf::Mouse::getPosition(window);
		sf::Vector2f yesPos = { yes.getPosition().x - yesRect.width / 2, yes.getPosition().y - yesRect.height / 2 };
		sf::Vector2f noPos = { no.getPosition().x - noRect.width / 2, no.getPosition().y - noRect.height / 2 };
		if (position.x >= yesPos.x && position.x <= yesPos.x + yesRect.width && position.y >= yesPos.y && position.y <= yesPos.y + yesRect.height)
			yesClicked = true;
		if (position.x >= noPos.x && position.x <= noPos.x + noRect.width && position.y >= noPos.y && position.y <= noPos.y + noRect.height)
			noClicked = true;
	}
}