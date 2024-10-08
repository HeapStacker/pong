#include "Application.h"


int main() {

    srand(time(nullptr));


    sf::Image icon;
    if (!icon.loadFromFile("res/images/ico.jpg")) {
        std::cerr << "icon path isn't correct\n";
        return 1;
    }

    Application game("Pong", icon, 800, 600);

    game.run();

    return EXIT_SUCCESS;
}