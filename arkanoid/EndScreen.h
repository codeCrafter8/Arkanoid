#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include <iostream>
/**@brief Klasa zawierajaca pola i metody zwiazane z ekranem koncowym**/
class EndScreen{
	sf::Font font;
	sf::Font font2;
public:
	/**@brief Konstruktor klasy Endscreen
	* @param window - referencja na glowne okno programu
	* @param text - tekst ktory ma zostac wyswietlony
	**/
	EndScreen(sf::RenderWindow& window, std::string text);
	/**@brief zmienna okreslajaca glowny tekst ekranu koncowego **/
	sf::Text endText;
	/**@brief zmienna okreslajaca tekst z pytaniem do uzytkownika na ekranie koncowym **/
	sf::Text ask;
	/**@brief zmienna okreslajaca tekst z odpowiedzia twierdzaca na ekranie koncowym **/
	sf::Text yes;
	/**@brief zmienna okreslajaca tekst z odpowiedzia przeczaca na ekranie koncowym **/
	sf::Text no;
	sf::FloatRect yesRect;
	sf::FloatRect noRect;
	/**@brief zmienna okreslajaca czy uzytkownik kliknal twierdzaca odpowiedz na ekranie koncowym **/
	bool yesClicked = false;
	/**@brief zmienna okreslajaca czy uzytkownik kliknal przeczaca odpowiedz na ekranie koncowym **/
	bool noClicked = false;
	/**@brief Metoda obslugujaca operacje przeprowadzone przez uzytkownika
	* @param window - referencja na glowne okno programu
	**/
	void update(sf::RenderWindow& window);
};