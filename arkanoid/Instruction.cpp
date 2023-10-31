#include "Instruction.h"

//Instruction::Instruction(sf::RenderWindow& window) {
    //rectInstruct.setSize(rectInstructSize);
    //rectInstruct.setFillColor(sf::Color(11, 63, 122));
    //rectInstructPos.x = window.getSize().x / 2.0 - rectInstructSize.x / 2.0;
    //rectInstructPos.y = window.getSize().y / 2.0 - 250;
    //rectInstruct.setPosition(rectInstructPos);
    ////how to play
    //if (!font2.loadFromFile("../fonts/Oswald.ttf")) {
    //    std::cerr << "Could not load Oswald font" << std::endl;
    //    exit(1);
    //}
    //Text instructHowToPlayT(window, "How to play", "../fonts/Oswald.ttf", 30, -1, -220, sf::Color::White);
    //instructHowToPlayT.text.setLetterSpacing(1.5);
    //instructionHowToPlayText = instructHowToPlayT.text;
    //instructionHowToPlayText.setFont(font2);
    ////instruction text1
    //Text instruct1T(window, "You need to destroy all the blocks to win the game.", "../fonts/Oswald.ttf", 20, -85, -170, sf::Color::White);
    //sf::Text Instruct1 = instruct1T.text;
    //Instruct1.setFont(font2);
    //instructionsArray[0] = Instruct1;
    ////instruction text2
    //Text instruct2T(window, "Use the paddle to bounce the ball.", "../fonts/Oswald.ttf", 20, -150, -130, sf::Color::White);
    //sf::Text Instruct2 = instruct2T.text;
    //Instruct2.setFont(font2);
    //instructionsArray[1] = Instruct2;
    ////instruction text3
    //Text instruct3T(window, "Move the paddle by the left arrow and the right arrow on the keybord.", "../fonts/Oswald.ttf", 20, -13, -90, sf::Color::White);
    //sf::Text Instruct3 = instruct3T.text;
    //Instruct3.setFont(font2);
    //instructionsArray[2] = Instruct3;
    ////instruction text4
    //Text instruct4T(window, "You can score points by destroying the bricks.", "../fonts/Oswald.ttf", 20, -104, -50, sf::Color::White);
    //sf::Text Instruct4 = instruct4T.text;
    //Instruct4.setFont(font2);
    //instructionsArray[3] = Instruct4;
    ////instruction text5
    //Text instruct5T(window, "Each level of the bricks has its own amount of points.", "../fonts/Oswald.ttf", 20, -78, -10, sf::Color::White);
    //sf::Text Instruct5 = instruct5T.text;
    //Instruct5.setFont(font2);
    //instructionsArray[4] = Instruct5;
    ////instruction text6
    //Text instruct6T(window, "You can also get bonuses.", "../fonts/Oswald.ttf", 20, -180, 30, sf::Color::White);
    //sf::Text Instruct6 = instruct6T.text;
    //Instruct6.setFont(font2);
    //instructionsArray[5] = Instruct6;
    ////instruction text7
    //Text instruct7T(window, "The EXTEND bonus extends the paddle.", "../fonts/Oswald.ttf", 20, -134, 70, sf::Color::White);
    //sf::Text Instruct7 = instruct7T.text;
    //Instruct7.setFont(font2);
    //instructionsArray[6] = Instruct7;
    ////instruction text8
    //Text instruct8T(window, "The SLOW bonus slows the ball.", "../fonts/Oswald.ttf", 20, -160, 110, sf::Color::White);
    //sf::Text Instruct8 = instruct8T.text;
    //Instruct8.setFont(font2);
    //instructionsArray[7] = Instruct8;
    ////instruction text9
    //Text instruct9T(window, "The DOUBLE bonus doubles the ball.", "../fonts/Oswald.ttf", 20, -145, 150, sf::Color::White);
    //sf::Text Instruct9 = instruct9T.text;
    //Instruct9.setFont(font2);
    //instructionsArray[8] = Instruct9;
    ////instruction text10
    //Text instruct10T(window, "If you lose the ball, the game is over.", "../fonts/Oswald.ttf", 20, -138, 190, sf::Color::White);
    //sf::Text Instruct10 = instruct10T.text;
    //Instruct10.setFont(font2);
    //instructionsArray[9] = Instruct10;
    ////cancel 
    //Text cancelT(window, "X", "../fonts/Audiowide.ttf", 21, 260, -225, sf::Color::White);
    //if (!font.loadFromFile("../fonts/Audiowide.ttf")) {
    //    std::cerr << "Could not load Audiowide font" << std::endl;
    //    exit(1);
    //}
    //cancelText = cancelT.text;
    //cancelText.setFont(font);
    //cancelRect = cancelT.textRect;
//}

void Instruction::set(sf::RenderWindow& window) {
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
    instructionHowToPlayText = instructHowToPlayT.text;
    instructionHowToPlayText.setFont(font2);
    //instruction text1
    Text instruct1T(window, "You need to destroy all the blocks to win the game.", "../fonts/Oswald.ttf", 20, -85, -170, sf::Color::White);
    sf::Text Instruct1 = instruct1T.text;
    Instruct1.setFont(font2);
    instructionsArray[0] = Instruct1;
    //instruction text2
    Text instruct2T(window, "Use the paddle to bounce the ball.", "../fonts/Oswald.ttf", 20, -150, -130, sf::Color::White);
    sf::Text Instruct2 = instruct2T.text;
    Instruct2.setFont(font2);
    instructionsArray[1] = Instruct2;
    //instruction text3
    Text instruct3T(window, "Move the paddle by the left arrow and the right arrow on the keybord.", "../fonts/Oswald.ttf", 20, -13, -90, sf::Color::White);
    sf::Text Instruct3 = instruct3T.text;
    Instruct3.setFont(font2);
    instructionsArray[2] = Instruct3;
    //instruction text4
    Text instruct4T(window, "You can score points by destroying the bricks.", "../fonts/Oswald.ttf", 20, -104, -50, sf::Color::White);
    sf::Text Instruct4 = instruct4T.text;
    Instruct4.setFont(font2);
    instructionsArray[3] = Instruct4;
    //instruction text5
    Text instruct5T(window, "Each level of the bricks has its own amount of points.", "../fonts/Oswald.ttf", 20, -78, -10, sf::Color::White);
    sf::Text Instruct5 = instruct5T.text;
    Instruct5.setFont(font2);
    instructionsArray[4] = Instruct5;
    //instruction text6
    Text instruct6T(window, "You can also get bonuses.", "../fonts/Oswald.ttf", 20, -180, 30, sf::Color::White);
    sf::Text Instruct6 = instruct6T.text;
    Instruct6.setFont(font2);
    instructionsArray[5] = Instruct6;
    //instruction text7
    Text instruct7T(window, "The EXTEND bonus extends the paddle.", "../fonts/Oswald.ttf", 20, -134, 70, sf::Color::White);
    sf::Text Instruct7 = instruct7T.text;
    Instruct7.setFont(font2);
    instructionsArray[6] = Instruct7;
    //instruction text8
    Text instruct8T(window, "The SLOW bonus slows the ball.", "../fonts/Oswald.ttf", 20, -160, 110, sf::Color::White);
    sf::Text Instruct8 = instruct8T.text;
    Instruct8.setFont(font2);
    instructionsArray[7] = Instruct8;
    //instruction text9
    Text instruct9T(window, "The DOUBLE bonus doubles the ball.", "../fonts/Oswald.ttf", 20, -145, 150, sf::Color::White);
    sf::Text Instruct9 = instruct9T.text;
    Instruct9.setFont(font2);
    instructionsArray[8] = Instruct9;
    //instruction text10
    Text instruct10T(window, "If you lose the ball, the game is over.", "../fonts/Oswald.ttf", 20, -138, 190, sf::Color::White);
    sf::Text Instruct10 = instruct10T.text;
    Instruct10.setFont(font2);
    instructionsArray[9] = Instruct10;
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

void Instruction::draw(sf::RenderWindow& window) {
    window.draw(rectInstruct);
    window.draw(instructionHowToPlayText);
    for (int i = 0; i < numberOfInstructions; i++)
        window.draw(instructionsArray[i]);
    window.draw(cancelText);
}

void Instruction::update(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Vector2f cancelPos = { cancelText.getPosition().x - cancelRect.width / 2, cancelText.getPosition().y - cancelRect.height / 2 };
        
        if (position.x >= rectHowToPlayPos.x && position.x <= rectHowToPlayPos.x + rectHowToPlaySize.x && position.y >= rectHowToPlayPos.y && position.y <= rectHowToPlayPos.y + rectHowToPlaySize.y) {
            //howToPlayClicked = true;
            shown = true;
        }
        
        if (position.x >= cancelPos.x && position.x <= cancelPos.x + cancelRect.width && position.y >= cancelPos.y && position.y <= cancelPos.y + cancelRect.height) {
            if (shown == true)
                shown = false;
        }
    }
}
