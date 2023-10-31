#pragma once
#include <SFML/Graphics.hpp>
#include<fstream>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Collision.h"
#include "Entity.h"
#include "EndScreen.h"
#include "StartScreen.h"
#include "ExtraPoints.h"
#include "Bonus.h"
#include "Instruction.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z programem
* Klasa ta obsluguje cala gre
**/
class Game{
	sf::Texture background;
	sf::Sprite spriteBackground;
	/**@brief zmienna okreslajaca czy aplikacja jest uruchomiona **/
	bool running = true;
	/**@brief zmienna okreslajaca czy ekran startowy jest uruchomiony **/
	bool startDisplaying = true;
	/**@brief zmienna okreslajaca czy okno z wlasciwa gra jest uruchomione **/
	bool gameDisplaying = false;
	/**@brief zmienna okreslajaca czy uzytkownik jest w trakcie gry **/
	bool playing = false;
	/**@brief zmienna okreslajaca czy ekran koncowy z przegrana jest uruchomiony **/
	bool gameOverDisplaying = false;
	/**@brief zmienna okreslajaca czy ekran koncowy z wygrana jest uruchomiony **/
	bool winDisplaying = false;
	/**@brief zmienna okreslajaca czy zapisywanie do pliku jest uruchomione **/
	bool printingToFile = true;
	/**@brief zmienna okreslajaca czy odczytywanie z pliku jest uruchomione **/
	bool readingFromFile = true;
	/**@brief zmienna okreslajaca punkty w grze **/
	int points = 0;
	/**@brief zmienna okreslajaca ilosc klockow pozostalych na planszy **/
	int bricksLeft = 50;
	int frameRate = 60;
	Paddle paddle;
	Ball ball;
	sf::Font font;
	std::stringstream ss;
	Ball ball2;
	std::vector<std::unique_ptr<Bonus>> bonusesIncreasingPaddle;
	std::vector<std::unique_ptr<Bonus>> bonusesSlowingBall;
	std::vector<std::unique_ptr<Bonus>> bonusesDoublingBall;
	Bonus bonusTemp;
	sf::Clock clockPaddleIncreased;
	sf::Clock clockBallSlowed;
	std::vector<Brick> bricks;
	float brickPosXTemp = 0;
	float brickPosYTemp = 0;
	Collision collision;
	ExtraPoints extrapoint;
	sf::Text text;
	std::string pointsString;
public:
	/**@brief Konstruktor klasy Game
	* @param window - referencja na glowne okno programu
	**/
	Game(sf::RenderWindow& window);
	/**@brief Metoda odpowiadajaca za dzialanie calego programu, stanowi silnik gry
	* @param window - referencja na glowne okno programu
	**/
	void run(sf::RenderWindow& window);
	/**@brief Metoda zapisujaca do pliku statystki graczy**/
	void print_to_file(int points);
	void initializeGameComponents();
};