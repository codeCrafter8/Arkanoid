#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/**@brief Klasa zawierajaca pola i metody zwiazane z tekstami**/
class Text {
public:
	/**@brief Konstruktor klasy Text
	* @param window - referencja na glowne okno programu
	* @param caption - napis do wyswietlenia
	* @param fontPatch - sciezka dostepu do czcionki
	* @param fontSize - rozmiar czcionki
	* @param xOfsset - przesuniecie wspolrzednej x
	* @param yOfsset - przesuniecie wspolrzednej y
	* @param color - kolor napisu
	**/
	Text(sf::RenderWindow& window, std::string caption, std::string fontPath, int fontSize, int xOfsset, int yOffset, sf::Color color);
	sf::Font font;
	sf::Text text;
	sf::FloatRect textRect;
};
