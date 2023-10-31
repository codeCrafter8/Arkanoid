#include "StartScreen.h"

StartScreen::StartScreen(sf::RenderWindow& window) {
    if (!background.loadFromFile("../img/startBackground.jpg")) {
        std::cerr << "Could not load startBackground texture" << std::endl;
        exit(1);
    }
    spriteBackground.setTexture(background);
    spriteBackground.setScale(0.15f, 0.2f);

    Text arkanoidT(window, "Arkanoid", "../fonts/Audiowide.ttf", 65, 0, -150, sf::Color(11, 63, 122));
    if (!font.loadFromFile("../fonts/Audiowide.ttf")) {
        std::cerr << "Could not load Audiowide font" << std::endl;
        exit(1);
    }
    arkanoidT.text.setOutlineColor(sf::Color::White);
    arkanoidT.text.setOutlineThickness(2);
    arkanoidText = arkanoidT.text;
    arkanoidText.setFont(font);

    //rectangle play
    rectPlay.setSize(rectPlaySize);
    rectPlay.setFillColor(sf::Color(11, 63, 122));
    rectPlay.setOutlineColor(sf::Color::White);
    rectPlay.setOutlineThickness(1);
    rectPlayPos.x = window.getSize().x / 2.0 - rectPlaySize.x / 2;
    rectPlayPos.y = window.getSize().y / 2.0 - 100;
    rectPlay.setPosition(rectPlayPos);

    //play
    Text playT(window, "PLAY", "../fonts/Oswald.ttf", 35, -1, -72, sf::Color::White);
    if (!font2.loadFromFile("../fonts/Oswald.ttf")) {
        std::cerr << "Could not load Oswald font" << std::endl;
        exit(1);
    }
    playT.text.setLetterSpacing(1.5);
    playText = playT.text;
    playText.setFont(font2);

    //rect how to play
    rectHowToPlay.setSize(rectHowToPlaySize);
    rectHowToPlay.setFillColor(sf::Color(11, 63, 122));
    rectHowToPlayPos.x = window.getSize().x / 2.0 - rectHowToPlaySize.x / 2.0;
    rectHowToPlayPos.y = window.getSize().y / 2.0 + 20;
    rectHowToPlay.setPosition(rectHowToPlayPos);

    //how to play
    Text howToPlayT(window, "How to play", "../fonts/Oswald.ttf", 25, -1, 45, sf::Color::White);
    howToPlayText = howToPlayT.text;
    howToPlayText.setFont(font2);

    //rect high scores
    rectHighScores.setSize(rectHowToPlaySize);
    rectHighScores.setFillColor(sf::Color(11, 63, 122));
    rectHighScores.setPosition({ rectHowToPlayPos.x, rectHowToPlayPos.y + 60 });

    //how to play
    Text highScoresT(window, "High scores", "../fonts/Oswald.ttf", 25, -1, 105, sf::Color::White);
    highScoresText = highScoresT.text;
    highScoresText.setFont(font2);
}

void StartScreen::showInstruction(sf::RenderWindow& window) {
    instruction.set(window);
    instruction.shown = true;
    instruction.draw(window);
    instruction.update(window);
}

void StartScreen::showHighScores(sf::RenderWindow& window) {
    //rect high scores
    rectHighScoresShow.setSize(rectHighScoresShowSize);
    rectHighScoresShow.setFillColor(sf::Color(11, 63, 122));
    rectHighScoresShowPos.x = window.getSize().x / 2.0 - rectHighScoresShowSize.x / 2.0;
    rectHighScoresShowPos.y = window.getSize().y / 2.0 - 250;
    rectHighScoresShow.setPosition(rectHighScoresShowPos);
    //high scores text
    if (!font2.loadFromFile("../fonts/Oswald.ttf")) {
        std::cerr << "Could not load Oswald font" << std::endl;
        exit(1);
    }
    Text highScoresT(window, "High scores", "../fonts/Oswald.ttf", 35, -1, -220, sf::Color::White);
    highScoresT.text.setLetterSpacing(1.5);
    highScoresShownText = highScoresT.text;
    highScoresShownText.setFont(font2);
    //rects
    for (int i = 0; i < 6; i++) {
        rects[i].setSize(rectsSize);
        rects[i].setFillColor(sf::Color(24, 85, 163));
        rectsPos.x = window.getSize().x / 2.0 - rectsSize.x / 2.0;
        rectsPos.y = window.getSize().y / 2.0 - 180 + i * 70;
        rects[i].setPosition(rectsPos);
    }
    //rect texts
    std::stringstream ss;
    std::string scoresString;
    for (int i = 0; i < 6; i++) {
        ss.str("");
        ss << "Player " << i + 1 << ":    " << bufor[i];
        scoresString = ss.str();
        Text highScoresPlayerT(window, scoresString, "../fonts/Oswald.ttf", 26, -10, -155 + i * 70, sf::Color::White);
        highScoresPlayerT.text.setLetterSpacing(1.5);
        scoresTexts[i] = highScoresPlayerT.text;
        scoresTexts[i].setFont(font2);
    }
    //cancel 
    Text cancelT(window, "X", "../fonts/Audiowide.ttf", 21, 260, -225, sf::Color::White);
    if (!font.loadFromFile("../fonts/Audiowide.ttf")) {
        std::cerr << "Could not load Audiowide font" << std::endl;
        exit(1);
    }
    cancelText = cancelT.text;
    cancelText.setFont(font);
    cancelRect = cancelT.textRect;
}

void StartScreen::sortStatistics() {
    for (int i = 0;i < len;i++)
        for (int j = 1;j < len - i;j++)
            if (bufor[j - 1] < bufor[j])
                std::swap(bufor[j - 1], bufor[j]);
}

void StartScreen::readFromFile() {
    std::string point;
    std::fstream file;
    int i = 0;
    file.open("../scores.txt", std::ios::in);
    if (file.good()) {
        while (getline(file, point)) {
            bufor[i] = atoi(point.c_str());
            i++;
        }
        len = i;
        file.close();
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku scores do odczytu.";
    sortStatistics();
}

void StartScreen::update(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Vector2f cancelPos = { cancelText.getPosition().x - cancelRect.width / 2, cancelText.getPosition().y - cancelRect.height / 2 };
        if (position.x >= rectPlayPos.x && position.x <= rectPlayPos.x + rectPlaySize.x && position.y >= rectPlayPos.y && position.y <= rectPlayPos.y + rectPlaySize.y)
            playClicked = true;
        if (position.x >= rectHowToPlayPos.x && position.x <= rectHowToPlayPos.x + rectHowToPlaySize.x && position.y >= rectHowToPlayPos.y && position.y <= rectHowToPlayPos.y + rectHowToPlaySize.y) {
            //howToPlayClicked = true;
            instruction.shown = true;
        }
        if (position.x >= rectHowToPlayPos.x && position.x <= rectHowToPlayPos.x + rectHowToPlaySize.x && position.y >= rectHowToPlayPos.y + 60 && position.y <= rectHowToPlayPos.y + 60 + rectHowToPlaySize.y) {
            highScoresClicked = true;
        }
        if (position.x >= cancelPos.x && position.x <= cancelPos.x + cancelRect.width && position.y >= cancelPos.y && position.y <= cancelPos.y + cancelRect.height) {
            if (instruction.shown == true)
                instruction.shown = false;
            if (highScoresClicked)
                highScoresClicked = false;
        }
    }
}

void StartScreen::draw(sf::RenderWindow& window) {
    window.draw(spriteBackground);
    window.draw(arkanoidText);
    window.draw(rectPlay);
    window.draw(playText);
    window.draw(rectHowToPlay);
    window.draw(howToPlayText);
    window.draw(rectHighScores);
    window.draw(highScoresText);
}


