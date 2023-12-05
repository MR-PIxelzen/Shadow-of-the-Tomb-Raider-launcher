// LaunchMenu.cpp
#include "LaunchMenu.h"

LaunchMenu::LaunchMenu() : window(sf::VideoMode(800, 600), "Game Launch Menu") {
    // Initialize other variables and settings
}

void LaunchMenu::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle other events (e.g., button clicks)
        }

        window.clear();
        // Draw menu items
        // window.draw(...);
        window.display();
    }
}
