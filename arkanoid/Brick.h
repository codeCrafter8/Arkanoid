#pragma once
#include<SFML/Graphics.hpp>
#include "Entity.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z klockami w grze**/
class Brick{
public:
	/**@brief Konstruktor klasy Brick**/
	Brick();
	/**@brief Konstruktor klasy Brick
	* @param x - wspolrzedna x pozycji poczatkowej klocka
	* @param y - wspolrzedna y pozycji poczatkowej klocka
	* @param brickColor - kolor klocka
	* @param level - poziom klocka
	**/
	Brick(float x, float y, sf::Color brickColor, int level);
	/**@brief zmienna okreslajaca szerokosc klocka **/
	const int sizeX = 76;
	/**@brief zmienna okreslajaca wysokosc klocka **/
	const int sizeY = 30;
	/**@brief zmienna okreslajaca szerokosc obramowania klocka **/
	const int outline = 4;
	/**@brief zmienna okreslajaca wspolrzedna x pozycji klocka **/
	float posX;
	/**@brief zmienna okreslajaca wspolrzedna y pozycji klocka **/
	float posY;
	float posConsX;
	float posConsY;
	/**@brief zmienna okreslajaca poziom klocka **/
	int level = 0;
	sf::Color color;
	sf::RectangleShape brick;
};