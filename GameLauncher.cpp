// GameLauncher.h
#pragma once
#include <SFML/Graphics.hpp>

class GameLauncher {
public:
    GameLauncher();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;
    sf::RectangleShape playButton;

    void drawLauncher();
    void handleEvents();
    void launchGame();  // Implement this function to launch your game
};

// GameLauncher.cpp
#include "GameLauncher.h"
#include <Font.Dlg>


IFE


GameLauncher::GameLauncher() : window(sf::VideoMode(800, 600), "Game Launcher") {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle font loading error
    }

    title.setString("Game Launcher");
    title.setFont(font);
    title.setCharacterSize(30);
    title.setPosition(200, 50);

    playButton.setSize(sf::Vector2f(200, 50));
    playButton.setPosition(300, 200);
    playButton.setFillColor(sf::Color::Green);
}

void GameLauncher::run() {
    while (window.isOpen()) {
        handleEvents();
        window.clear();
        drawLauncher();
        window.display();
    }
}

void GameLauncher::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

            if (playButton.getGlobalBounds().contains(mousePos)) {
                launchGame();
            }
        }
    }
}

void GameLauncher::drawLauncher() {
    window.draw(title);
    window.draw(playButton);
}

void GameLauncher::launchGame() {
    // Implement the logic to launch your game here
    // This function will be called when the "Play" button is clicked
}

// main.cpp
int main() {
    GameLauncher launcher;
    launcher.run();

    return 0;
}
