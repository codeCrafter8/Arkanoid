#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Paddle.h"
#include "Ball.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z bonusami w grze**/
class Bonus{
	sf::Texture texture;
	/**@brief zmienna okreslajaca predkosc bonusa **/
	const float speed = 0.1;
	/**@brief zmienna okreslajaca wartosc o jaka zostanie spowolniona pilka **/
	const float slowingValue = 0.05;
public:
	/**@brief Konstruktor klasy Bonus**/
	Bonus();
	/**@brief Konstruktor klasy Bonus
	* @param position - wektor pozycji poczatkowej bonusa
	* @param filePath - sciezka dostepu do obrazu bonusa
	**/
	Bonus(sf::Vector2f position, std::string filePath);
	/**@brief Metoda zapewniajaca poruszanie sie bonusa podczas gry**/
	void move();
	sf::Sprite sprite;
	/**@brief zmienna okreslajaca szerokosc bonusa **/
	float const width = 40;
	/**@brief zmienna okreslajaca wysokosc bonusa **/
	float const height = 40;
	/**@brief zmienna okreslajaca wspolrzedna x pozycji bonusa **/
	float posX;
	/**@brief zmienna okreslajaca wspolrzedna y pozycji bonusa **/
	float posY;
	/**@brief zmienna okreslajaca wspolrzedna x pozycji poczatkowej dodatkowej pilki **/
	float ballPosX;
	/**@brief zmienna okreslajaca wspolrzedna y pozycji poczatkowej dodatkowej pilki **/
	float ballPosY;
	/**@brief Metoda zapewniajaca powiekszenie sie paletki 
	* @param paddle - referencja na paletke
	**/
	void increasePaddleWidth(Paddle &paddle);
	/**@brief Metoda zapewniajaca zmiejszenie sie paletki
	* @param paddle - referencja na paletke
	**/
	void reducePaddleWidth(Paddle &paddle);
	/**@brief Metoda zapewniajaca spowolnienie pilki
	* @param ball - referencja na pilke
	**/
	void slowBall(Ball &ball);
	/**@brief Metoda zapewniajaca przyspieszenie pilki
	* @param ball - referencja na pilke
	**/
	void speedBall(Ball &ball);
	/**@brief Metoda zapewniajaca podwojenie sie pilki
	* @param ball - referencja na pilke
	**/
	void doubleBall(Ball& ball2);
};
