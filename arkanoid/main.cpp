#include "Game.h"
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window;
    Game game(window);
    game.run(window);
    return 0;
}