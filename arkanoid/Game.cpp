#include "Game.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 600

Game::Game(sf::RenderWindow &window){
	window.create(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Arkanoid");
    
    if (!background.loadFromFile("../img/background.png")) {
        std::cerr << "Could not load background texture" << std::endl;
        exit(1);
    }
    spriteBackground.setTexture(background);
    spriteBackground.setScale(0.65f, 0.5f);
}

void Game::run(sf::RenderWindow &window) {
    initializeGameComponents();
    sf::Clock clock;

    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        if (startDisplaying) {
            StartScreen startScreen(window);
            startScreen.update(window);
            window.draw(startScreen.spriteBackground);
            startScreen.draw(window);
            if (readingFromFile) {
                startScreen.read_from_file();
                readingFromFile = false;
            }
            if (startScreen.playClicked) {
                startDisplaying = false;
                gameDisplaying = true;
            }
            if(startScreen.howToPlayClicked == true) {
                startScreen.showInstruction(window);
                window.draw(startScreen.rectInstruct);
                window.draw(startScreen.InstructHowToPlay);
                for (int i = 0; i < startScreen.numberOfInstructions; i++)
                    window.draw(startScreen.instrArray[i]);
                window.draw(startScreen.Cancel);
                startScreen.update(window);
            }
            if (startScreen.highScoresClicked == true) {
                startScreen.showHighScores(window);
                window.draw(startScreen.rectHighScoresShow);
                window.draw(startScreen.HighScoresShow);
                for (sf::RectangleShape rect : startScreen.rects) {
                    window.draw(rect);
                }
                for (sf::Text text : startScreen.scoresTexts) {
                    window.draw(text);
                }
                window.draw(startScreen.Cancel);
                startScreen.update(window);
            }
        }

        if (gameDisplaying){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                playing = true;
            }
            if (playing) {
                ball.move(window);
                if (ball.doubled)
                    ball2.move(window);
                if (!ball2.alive && ball.isOver)
                    gameOverDisplaying = true;
                if (ball2.alive && ball.isOver && ball2.isOver)
                    gameOverDisplaying = true;
                if (ball2.isOver)
                    ball.doubled = false;
                if (bricksLeft == 0)
                    winDisplaying = true;
                collision.paddleBallCollision(paddle, ball);
                collision.paddleBallCollision(paddle, ball2);
                if (!bonusesIncreasingPaddle.empty()) {
                    for(auto& it : bonusesIncreasingPaddle){
                        if (collision.paddleBonusCollision(paddle, *it)) {
                            if (!paddle.increased) {
                                it->increasePaddleWidth(paddle);
                                paddle.increased = true;
                            }
                            clockPaddleIncreased.restart();
                        }
                    }
                }
                if (!bonusesSlowingBall.empty()) {
                    for (auto& it : bonusesSlowingBall) {
                        if (collision.paddleBonusCollision(paddle, *it)) {
                            if (!ball.slowed) {
                                it->slowBall(ball);
                                if(ball.doubled)
                                    it->slowBall(ball2);
                                ball.slowed = true;
                            }
                            clockBallSlowed.restart();
                        }
                    }
                }
                if (!bonusesDoublingBall.empty()) {
                    for (auto& it : bonusesDoublingBall) {
                        if (collision.paddleBonusCollision(paddle, *it)) {
                            if (!ball.doubled) {
                                it->doubleBall(ball2);
                                ball.doubled = true;
                            }
                        }
                    }
                }
                if (paddle.increased && clockPaddleIncreased.getElapsedTime().asSeconds() >= 6.0) {
                    paddle.increased = false;
                    bonusesIncreasingPaddle[0]->reducePaddleWidth(paddle);
                    clockPaddleIncreased.restart();
                }
                if (ball.slowed && clockBallSlowed.getElapsedTime().asSeconds() >= 6.0) {
                    ball.slowed = false;
                    bonusesSlowingBall[0]->speedBall(ball);
                    if(ball.doubled)
                        bonusesSlowingBall[0]->speedBall(ball2);
                    clockBallSlowed.restart();
                }
                for (int i = 0; i < bricks.size(); i++) {
                    brickPosXTemp = bricks[i].posX;
                    brickPosYTemp = bricks[i].posY;
                    if (collision.brickBallCollision(bricks[i], ball) == true || collision.brickBallCollision(bricks[i], ball2) == true) {
                        bricksLeft--;
                        extrapoint.set(window, bricks[i].level * 10, { brickPosXTemp + 35, brickPosYTemp + 15 });
                        points += bricks[i].level * 10;
                        if(i== 43 || i == 23)
                            bonusesSlowingBall.push_back(std::unique_ptr<Bonus>(new Bonus({ brickPosXTemp + bricks[i].sizeX / 2 - bonusTemp.width / 2,
                            brickPosYTemp + bricks[i].sizeY }, "../img/bonusSLOW.png")));
                        if(i == 48 || i == 38 || i == 5)
                           bonusesIncreasingPaddle.push_back(std::unique_ptr<Bonus>(new Bonus({brickPosXTemp + bricks[i].sizeX / 2 - bonusTemp.width / 2,
                           brickPosYTemp + bricks[i].sizeY }, "../img/bonusEXPAND.png")));
                        if(i == 47)
                            bonusesDoublingBall.push_back(std::unique_ptr<Bonus>(new Bonus({ brickPosXTemp + bricks[i].sizeX / 2 - bonusTemp.width / 2,
                            brickPosYTemp + bricks[i].sizeY }, "../img/bonusDOUBLE.png")));
                    }
                }
                
            }
            else
                ball.moveWithPaddle(window);
            ss.str("");
            ss << "Points: " << points;
            pointsString = ss.str();
            text.setString(pointsString);
            window.draw(spriteBackground);
            window.draw(paddle.sprite);
            window.draw(ball.sprite);
            if (ball.doubled)
                window.draw(ball2.sprite);
            for (Brick brick_ : bricks) {
                window.draw(brick_.brick);
            }
            window.draw(text);
            window.draw(extrapoint.Points);
            for (auto& it : bonusesIncreasingPaddle) {
                window.draw(it->sprite);
                it->move();
            }
            for (auto& it : bonusesSlowingBall) {
                window.draw(it->sprite);
                it->move();
            }
            for (auto& it : bonusesDoublingBall) {
                window.draw(it->sprite);
                it->move();
            }
            paddle.move(window);
        }

        if (gameOverDisplaying || winDisplaying) {
            if (printingToFile) {
                print_to_file(points);
                printingToFile = false;
            }
            gameDisplaying = false;
            playing = false;
            std::string endText;
            if (gameOverDisplaying)
                endText = "Game Over";
            else
                endText = "Winner";
            EndScreen endScreen(window, endText);
            window.draw(endScreen.endText);
            window.draw(endScreen.ask);
            window.draw(endScreen.yes);
            window.draw(endScreen.no);
            endScreen.update(window);
            if (endScreen.yesClicked) {
                gameDisplaying = true;
                if (gameOverDisplaying)
                    gameOverDisplaying = false;
                else
                    winDisplaying = false;
                printingToFile = true;
            }
            if (endScreen.noClicked) {
                if (gameOverDisplaying)
                    gameOverDisplaying = false;
                else
                    winDisplaying = false;
                startDisplaying = true;
                printingToFile = true;
                readingFromFile = true;
            }
            ball.isOver = false;
            ball2.isOver = false;
            paddle.sprite.setPosition({ paddle.posX, paddle.posY });
            paddle.width = paddle.constWidth;
            paddle.sprite.setScale(1, 1);
            ball.sprite.setPosition({ ball.posX, ball.posY });
            for (int i = 0; i < bricks.size(); i++) {
                bricks[i].brick.setPosition(bricks[i].posConsX, bricks[i].posConsY);
                bricks[i].posX = bricks[i].posConsX;
                bricks[i].posY = bricks[i].posConsY;
            }
            ball.ballMove = ball.ballMoveCons;
            points = 0;
            extrapoint.set(window, 0, sf::Vector2f(-1000, -1000));
            for (auto& it : bonusesIncreasingPaddle) {
                it->sprite.setPosition(-1000, -1000);
                it->posX = -1000;
                it->posY = -1000;
            }
            for (auto& it : bonusesSlowingBall) {
                it->sprite.setPosition(-1000, -1000);
                it->posX = -1000;
                it->posY = -1000;
            }
            for (auto& it : bonusesDoublingBall) {
                it->sprite.setPosition(-1000, -1000);
                it->posX = -1000;
                it->posY = -1000;
            }
        }
        window.display();

        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() < 1000 / frameRate) {
            sf::sleep(sf::milliseconds(1000 / frameRate) - elapsed);
        }
    }

    window.close();
}

void Game::initializeGameComponents() {
    if (!font.loadFromFile("../fonts/Oswald.ttf")) {
        std::cerr << "Could not load Oswald font" << std::endl;
        exit(1);
    }
  
    ss << "Points: " << points;
    pointsString = ss.str();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setString(pointsString);
    text.setPosition(7, 5);

    int brickTop = 50;
    Brick brickTemp;
    int k = brickTemp.outline / 2;
    int level = 5;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 10; j++) {
            bricks.push_back(Brick(k, brickTop, sf::Color(i * 20, i * 20, i * 240), level));
            k += brickTemp.sizeX + brickTemp.outline;
        }
        level--;
        k = brickTemp.outline / 2;
        brickTop += brickTemp.sizeY + brickTemp.outline;
    }
}

void Game::print_to_file(int points){
    std::fstream file;
    file.open("../scores.txt", std::ios::app);
    if (file.good()) {
        file << points << std::endl;
        file.close();
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku scores do zapisu.";
}

