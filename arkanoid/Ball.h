#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Paddle.h"
/**@brief makro opisujace wspolrzedna x poczatkowej pozycji pilki */
#define POS_X 388
/**@brief makro opisujace wspolrzedna y poczatkowej pozycji pilki */
#define POS_Y 509
/**@brief Klasa zawierajaca pola i metody zwiazane z pilka w grze
* Klasa ta dziedziczy po klasie Entity.
**/
class Ball : public Entity{
public:
	/**@brief Konstruktor klasy Ball**/
	Ball();
	/**@brief Konstruktor klasy Ball
	* @param x - wspolrzedna x pozycji poczatkowej pilki
	* @param y - wspolrzedna y pozycji poczatkowej pilki
	**/
	Ball(float x, float y);
	/**@brief zmienna okreslajaca srednice pilki **/
	const int diamater = 22;
	/**@brief zmienna okreslajaca wspolrzedna x pozycji poczatkowej pilki **/
	const float posX = 388;
	/**@brief zmienna okreslajaca wspolrzedna y pozycji poczatkowej pilki **/
	const float posY = 509;
	/**@brief zmienna okreslajaca czy pilka jest poza ekranem **/
	bool isOver = false;
	/**@brief zmienna okreslajaca czy pilka jest spowolniona **/
	bool slowed = false;
	/**@brief zmienna okreslajaca czy pilka jest podwojona **/
	bool doubled = false;
	/**@brief zmienna okreslajaca czy pilka jest w grze **/
	bool alive = false;
	/**@brief zmienna okreslajaca wektor poruszania sie pilki **/
	sf::Vector2f ballMove{ 0.15,-0.25 };
	sf::Vector2f ballMoveCons{ 0.15,-0.25 };
	/**@brief Metoda zapewniajaca poruszanie pilki poziomo wraz z paletka przed rozpoczeciem gry
	* @param window - referencja na glowne okno programu
	**/
	void moveWithPaddle(sf::RenderWindow &window);
	/**@brief Metoda zapewniajaca poruszanie pilki podczas gry
	* @param window - referencja na glowne okno programu
	**/
	void move(sf::RenderWindow &window);
};