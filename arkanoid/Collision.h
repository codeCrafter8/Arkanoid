#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bonus.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z kolizjami w grze**/
class Collision {
	/**@brief Metoda wspomagajaca wykrywanie kolizji paletki z pilka
	* @param value - wspolrzedna srodka pilki
	* @param min - wspolrzedna poczatku paletki
	* @param max - wspolrzedna konca paletki
	* @return zwraca wspolrzedna punktu na paletce polozonego najblizej pilki
	**/
	float clamp(float value, float min, float max);
public:
	/**@brief Metoda obslugujaca kolizje paletki z pilka
	* @param paddle - referencja na paletke
	* @param ball - referencja na pilke
	**/
	void paddleBallCollision(Paddle &paddle, Ball &ball);
	/**@brief Metoda obslugujaca kolizje klocka z pilka
	* @param brick - referencja na klocka
	* @param ball - referencja na pilke
	* @return zwraca true jesli doszlo do kolizji, w przeciwnym wypadku zwraca false
	**/
	bool brickBallCollision(Brick& brick, Ball& ball);
	/**@brief Metoda obslugujaca kolizje paletki z bonusem
	* @param paddle - referencja na paletke
	* @param bonus - referencja na bonus
	* @return zwraca true jesli doszlo do kolizji, w przeciwnym wypadku zwraca false
	**/
	bool paddleBonusCollision(Paddle& paddle, Bonus& bonus);
};