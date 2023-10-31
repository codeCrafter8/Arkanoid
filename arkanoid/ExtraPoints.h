#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z dodatkowymi punktami w grze**/
class ExtraPoints {
	sf::Font font;
public:
	/**@brief Metoda wyswietlajaca dodatkowe punkty
	* @param window - referencja na glowne okno programu
	* @param value - wartosc punktow
	* @param brickPos - pozycja klocka
	**/
	void set(sf::RenderWindow& window, int value, sf::Vector2f brickPos);
	/**@brief zmienna tekst z wartoscia dodatkowych punktow **/
	sf::Text Points;
};
