#pragma once
#include<SFML/Graphics.hpp>
#include "Text.h"
#include<iostream>

class Instruction {
	sf::RectangleShape rectInstruct;
	/**@brief wektor okreslajacy rozmiar prostokata z instrukcja gry **/
	sf::Vector2f rectInstructSize = { 600, 500 };
	/**@brief wektor okreslajacy pozycje prostokata z instrukcja gry **/
	sf::Vector2f rectInstructPos;
	sf::Font font2;
	sf::Text instructionHowToPlayText;
	/**@brief tablica przechowujaca teksty instrukcji gry **/
	sf::Text instructionsArray[10];
	/**@brief zmienna okreslajaca ilosc tekstow instrukcji gry **/
	int numberOfInstructions = 10;
	sf::Font font;
	sf::Text cancelText;
	sf::FloatRect cancelRect;
	sf::RectangleShape rectHowToPlay;
	/**@brief wektor okreslajacy pozycje przycisku "how to play" **/
	sf::Vector2f rectHowToPlayPos;
	/**@brief wektor okreslajacy rozmiar przycisku "how to play" **/
	sf::Vector2f rectHowToPlaySize = { 170, 50 };
public:
	//Instruction(sf::RenderWindow& window);
	void set(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	bool shown;
};
