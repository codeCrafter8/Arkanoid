#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/**@brief Klasa zawierajaca pola i metody zwiazane z najwazniejszymi obiektami w grze**/
class Entity{
protected:
	sf::Texture texture;
	/**@brief zmienna okreslajaca predkosc poruszania obiektu **/
	const float speed = 0.9;
	const int paddleWidth = 156;
public:
	/**@brief Konstruktor klasy Entity
	* @param position - wektor pozycji poczatkowej obiektu
	* @param filePath - sciezka dostepu do obrazu obiektu
	**/
	Entity(sf::Vector2f position, std::string filePath);
	sf::Sprite sprite;
	/**@brief Metoda obslugujaca poruszanie paletki oraz paletki wraz z pilka
	* @param window - referencja na glowne okno programu
	* @param leftBorder - lewa granica do ktorej obiekt moze sie poruszac
	* @param righBorder - prawa granica do ktorej obiekt moze sie poruszac
	**/
	void paddleBallmove(sf::RenderWindow& window, int leftBorder, int rightBorder);
};