#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include "Text.h"
/**@brief Klasa zawierajaca pola i metody zwiazane z ekranem poczatkowym**/
class StartScreen {
	/**@brief wektor okreslajacy rozmiar przycisku "play" **/
	sf::Vector2f rectPlaySize = { 150, 60 };
	/**@brief wektor okreslajacy pozycje przycisku "play" **/
	sf::Vector2f rectPlayPos;
	/**@brief wektor okreslajacy rozmiar przycisku "how to play" **/
	sf::Vector2f rectHowToPlaySize = { 170, 50 };
	/**@brief wektor okreslajacy pozycje przycisku "how to play" **/
	sf::Vector2f rectHowToPlayPos;
	/**@brief wektor okreslajacy rozmiar prostokata z instrukcja gry **/
	sf::Vector2f rectInstructSize = { 600, 500 };
	/**@brief wektor okreslajacy pozycje prostokata z instrukcja gry **/
	sf::Vector2f rectInstructPos;
	/**@brief wektor okreslajacy rozmiar prostokata z najlepszymi statystykami graczy **/
	sf::Vector2f rectHighScoresShowSize = { 600, 500 };
	/**@brief wektor okreslajacy pozycje prostokata z najlepszymi statystykami graczy **/
	sf::Vector2f rectHighScoresShowPos;
	/**@brief zmienna okreslajaca ilosc liczb w pliku "scores" **/
	int len = 0;
	/**@brief tablica przechowujaca statystyki graczy **/
	int bufor[200];
	/**@brief wektor okreslajacy rozmiar prostokatow z pojedynczymi statystykami graczy **/
	sf::Vector2f rectsSize = { 200, 50 };
	/**@brief wektor okreslajacy pozycje prostokatow z pojedynczymi statystykami graczy **/
	sf::Vector2f rectsPos;
	sf::Font font;
	sf::Font font2;
public:
	/**@brief Konstruktor klasy Startscreen
	* @param window - referencja na glowne okno programu
	**/
	StartScreen(sf::RenderWindow& window);
	sf::Texture background;
	sf::Sprite spriteBackground;
	sf::Text Arkanoid;
	sf::Text Play;
	sf::Text HowToPlay;
	sf::Text InstructHowToPlay;
	/**@brief tablica przechowujaca teksty instrukcji gry **/
	sf::Text instrArray[10];
	/**@brief zmienna okreslajaca ilosc tekstow instrukcji gry **/
	int numberOfInstructions = 10;
	sf::Text Cancel;
	sf::Text HighScores;
	sf::Text HighScoresShow;
	sf::Text HighScoresPlayer;
	/**@brief tablica przechowujaca teksty statystyk **/
	sf::Text scoresTexts[6];
	sf::Text CancelHighScores;
	sf::RectangleShape rectPlay;
	sf::RectangleShape rectHowToPlay;
	sf::RectangleShape rectInstruct;
	sf::FloatRect cancelRect;
	sf::FloatRect cancelHighScoresRect;
	sf::RectangleShape rectHighScores;
	sf::RectangleShape rectHighScoresShow;
	/**@brief tablica przechowujaca prostokaty statystyk **/
	sf::RectangleShape rects[6];
	/**@brief tablica przechowujaca teksty statystyk **/
	sf::Text rectTexts[6];
	/**@brief zmienna okreslajaca czy uzytkownik kliknal przycisk "play" **/
	bool playClicked = false;
	/**@brief zmienna okreslajaca czy uzytkownik kliknal przycisk "how to play" **/
	bool howToPlayClicked;
	/**@brief zmienna okreslajaca czy uzytkownik kliknal przycisk "high scores" **/
	bool highScoresClicked;
	/**@brief Metoda obslugujaca operacje przeprowadzone przez uzytkownika
	* @param window - referencja na glowne okno programu
	**/
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	/**@brief Metoda wyswietlajaca instrukcje gry
	* @param window - referencja na glowne okno programu
	**/
	void showInstruction(sf::RenderWindow& window);
	/**@brief Metoda wyswietlajaca najlepsze statystki graczy
	* @param window - referencja na glowne okno programu
	**/
	void showHighScores(sf::RenderWindow& window);
	/**@brief Metoda sortujaca statystki graczy**/
	void sort_statistics();
	/**@brief Metoda odczytujaca z pliku statystki graczy**/
	void read_from_file();
};