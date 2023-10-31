#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <SFML/Graphics.hpp>
/**@brief Klasa zawierajaca pola i metody zwiazane z paletka w grze
* Klasa ta dziedziczy po klasie Entity.
**/
class Paddle : public Entity{
public:
	/**@brief Konstruktor klasy Paddle**/
	Paddle();
	/**@brief zmienna okreslajaca wspolrzedna x poczatkowej pozycji paletki **/
	const float posX = 322;
	/**@brief zmienna okreslajaca wspolrzedna y poczatkowej pozycji paletki **/
	const float posY = 530;
	/**@brief zmienna okreslajaca szerokosc paletki **/
	int width = 155;
	const int constWidth = 155;
	/**@brief zmienna okreslajaca wysokosc paletki **/
	const int height = 31;
	/**@brief zmienna okreslajaca czy paletka zostala powiekszona **/
	bool increased = false;
	/**@brief Metoda zapewniajaca poruszanie paletki podczas gry
	* @param window - referencja na glowne okno programu
	**/
	void move(sf::RenderWindow& window);
};