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
    Arkanoid = arkanoidT.text;
    Arkanoid.setFont(font);

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
    Play = playT.text;
    Play.setFont(font2);

    //rect how to play
    rectHowToPlay.setSize(rectHowToPlaySize);
    rectHowToPlay.setFillColor(sf::Color(11, 63, 122));
    rectHowToPlayPos.x = window.getSize().x / 2.0 - rectHowToPlaySize.x / 2.0;
    rectHowToPlayPos.y = window.getSize().y / 2.0 + 20;
    rectHowToPlay.setPosition(rectHowToPlayPos);

    //how to play
    Text howToPlayT(window, "How to play", "../fonts/Oswald.ttf", 25, -1, 45, sf::Color::White);
    HowToPlay = howToPlayT.text;
    HowToPlay.setFont(font2);

    //rect high scores
    rectHighScores.setSize(rectHowToPlaySize);
    rectHighScores.setFillColor(sf::Color(11, 63, 122));
    rectHighScores.setPosition({ rectHowToPlayPos.x, rectHowToPlayPos.y + 60 });

    //how to play
    Text highScoresT(window, "High scores", "../fonts/Oswald.ttf", 25, -1, 105, sf::Color::White);
    HighScores = highScoresT.text;
    HighScores.setFont(font2);
}

void StartScreen::showInstruction(sf::RenderWindow& window) {
    rectInstruct.setSize(rectInstructSize);
    rectInstruct.setFillColor(sf::Color(11, 63, 122));
    rectInstructPos.x = window.getSize().x / 2.0 - rectInstructSize.x / 2.0;
    rectInstructPos.y = window.getSize().y / 2.0 - 250;
    rectInstruct.setPosition(rectInstructPos);
    //how to play
    if (!font2.loadFromFile("../fonts/Oswald.ttf")) {
        std::cerr << "Could not load Oswald font" << std::endl;
        exit(1);
    }
    Text instructHowToPlayT(window, "How to play", "../fonts/Oswald.ttf", 30, -1, -220, sf::Color::White);
    instructHowToPlayT.text.setLetterSpacing(1.5);
    InstructHowToPlay = instructHowToPlayT.text;
    InstructHowToPlay.setFont(font2);
    //instruction text1
    Text instruct1T(window, "You need to destroy all the blocks to win the game.", "../fonts/Oswald.ttf", 20, -85, -170, sf::Color::White);
    sf::Text Instruct1 = instruct1T.text;
    Instruct1.setFont(font2);
    instrArray[0] = Instruct1;
    //instruction text2
    Text instruct2T(window, "Use the paddle to bounce the ball.", "../fonts/Oswald.ttf", 20, -150, -130, sf::Color::White);
    sf::Text Instruct2 = instruct2T.text;
    Instruct2.setFont(font2);
    instrArray[1] = Instruct2;
    //instruction text3
    Text instruct3T(window, "Move the paddle by the left arrow and the right arrow on the keybord.", "../fonts/Oswald.ttf", 20, -13, -90, sf::Color::White);
    sf::Text Instruct3 = instruct3T.text;
    Instruct3.setFont(font2);
    instrArray[2] = Instruct3;
    //instruction text4
    Text instruct4T(window, "You can score points by destroying the bricks.", "../fonts/Oswald.ttf", 20, -104, -50, sf::Color::White);
    sf::Text Instruct4 = instruct4T.text;
    Instruct4.setFont(font2);
    instrArray[3] = Instruct4;
    //instruction text5
    Text instruct5T(window, "Each level of the bricks has its own amount of points.", "../fonts/Oswald.ttf", 20, -78, -10, sf::Color::White);
    sf::Text Instruct5 = instruct5T.text;
    Instruct5.setFont(font2);
    instrArray[4] = Instruct5;
    //instruction text6
    Text instruct6T(window, "You can also get bonuses.", "../fonts/Oswald.ttf", 20, -180, 30, sf::Color::White);
    sf::Text Instruct6 = instruct6T.text;
    Instruct6.setFont(font2);
    instrArray[5] = Instruct6;
    //instruction text7
    Text instruct7T(window, "The EXTEND bonus extends the paddle.", "../fonts/Oswald.ttf", 20, -134, 70, sf::Color::White);
    sf::Text Instruct7 = instruct7T.text;
    Instruct7.setFont(font2);
    instrArray[6] = Instruct7;
    //instruction text8
    Text instruct8T(window, "The SLOW bonus slows the ball.", "../fonts/Oswald.ttf", 20, -160, 110, sf::Color::White);
    sf::Text Instruct8 = instruct8T.text;
    Instruct8.setFont(font2);
    instrArray[7] = Instruct8;
    //instruction text9
    Text instruct9T(window, "The DOUBLE bonus doubles the ball.", "../fonts/Oswald.ttf", 20, -145, 150, sf::Color::White);
    sf::Text Instruct9 = instruct9T.text;
    Instruct9.setFont(font2);
    instrArray[8] = Instruct9;
    //instruction text10
    Text instruct10T(window, "If you lose the ball, the game is over.", "../fonts/Oswald.ttf", 20, -138, 190, sf::Color::White);
    sf::Text Instruct10 = instruct10T.text;
    Instruct10.setFont(font2);
    instrArray[9] = Instruct10;
    //cancel 
    Text cancelT(window, "X", "../fonts/Audiowide.ttf", 21, 260, -225, sf::Color::White);
    if (!font.loadFromFile("../fonts/Audiowide.ttf")) {
        std::cerr << "Could not load Audiowide font" << std::endl;
        exit(1);
    }
    Cancel = cancelT.text;
    Cancel.setFont(font);
    cancelRect = cancelT.textRect;
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
    HighScoresShow = highScoresT.text;
    HighScoresShow.setFont(font2);
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
    Cancel = cancelT.text;
    Cancel.setFont(font);
    cancelRect = cancelT.textRect;
}

void StartScreen::sort_statistics() {
    for (int i = 0;i < len;i++)
        for (int j = 1;j < len - i;j++)
            if (bufor[j - 1] < bufor[j])
                std::swap(bufor[j - 1], bufor[j]);
}

void StartScreen::read_from_file() {
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
    sort_statistics();
}

void StartScreen::update(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Vector2f cancelPos = { Cancel.getPosition().x - cancelRect.width / 2, Cancel.getPosition().y - cancelRect.height / 2 };
        if (position.x >= rectPlayPos.x && position.x <= rectPlayPos.x + rectPlaySize.x && position.y >= rectPlayPos.y && position.y <= rectPlayPos.y + rectPlaySize.y) 
            playClicked = true;
        if (position.x >= rectHowToPlayPos.x && position.x <= rectHowToPlayPos.x + rectHowToPlaySize.x && position.y >= rectHowToPlayPos.y && position.y <= rectHowToPlayPos.y + rectHowToPlaySize.y) {
            howToPlayClicked = true;
        }
        if (position.x >= rectHowToPlayPos.x && position.x <= rectHowToPlayPos.x + rectHowToPlaySize.x && position.y >= rectHowToPlayPos.y + 60 && position.y <= rectHowToPlayPos.y + 60 + rectHowToPlaySize.y) {
            highScoresClicked = true;
        }
        if (position.x >= cancelPos.x && position.x <= cancelPos.x + cancelRect.width && position.y >= cancelPos.y && position.y <= cancelPos.y + cancelRect.height) {
            if(howToPlayClicked == true)
                howToPlayClicked = false;
            if (highScoresClicked)
                highScoresClicked = false;
        }
    }
}

void StartScreen::draw(sf::RenderWindow& window) {
    window.draw(Arkanoid);
    window.draw(rectPlay);
    window.draw(Play);
    window.draw(rectHowToPlay);
    window.draw(HowToPlay);
    window.draw(rectHighScores);
    window.draw(HighScores);
}


