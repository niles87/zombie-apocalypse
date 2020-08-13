#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

int main()
{
    enum class State
    {
        PAUSED, LEVELING_UP, GAME_OVER, PLAYING
    };

    State state = State::GAME_OVER;

    // Get screen resolution then create SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Apocalypse", Style::Fullscreen);

    // Create SFML View for main 
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    Clock clock;

    Time gameTimeTotal;

    // Get mouse coords in relation to world
    Vector2f mouseWorldPosition;
    // Mouse coords in relation to screen
    Vector2i mouseScreenPosition;

    Player player;

    // Boundaries of map
    IntRect arena;
    
    // Main game loop
    while (window.isOpen()) {
        /*
         Handle Input
        */
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Return && state == State::PLAYING) {
                    state = State::PAUSED;
                }
                else if (event.key.code == Keyboard::Return && state == State::PAUSED) {
                    state = State::PLAYING;
                    clock.restart();
                }
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER) {
                    state = State::LEVELING_UP;
                }
                if (state == State::PLAYING) {

                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (state == State::PLAYING) {
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player.moveUp();
            }
            else {
                player.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::S)) {
                player.moveDown();
            }
            else {
                player.stopDown();
            }

            if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.moveLeft();
            }
            else {
                player.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::D)) {
                player.moveRight();
            }
            else {
                player.stopRight();
            }
        }
        
        if (state == State::LEVELING_UP) {
            if (event.key.code == Keyboard::Num1) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num2) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num3) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num4) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num5) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num6) {
                state = State::PLAYING;
            }

            if (state == State::PLAYING) {
                // Prepare Level
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;

                int tileSize = 50;

                player.spawn(arena, resolution, tileSize);

                clock.restart();
            }
        }

        /*
        Update the scene
        */
        if (state == State::PLAYING) {
            Time dt = clock.restart();

            gameTimeTotal += dt;

            float dtAsSeconds = dt.asSeconds();

            // Find mouse pointer
            mouseScreenPosition = Mouse::getPosition();
            // Convert mouse position to mainView
            mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

            // Update player position
            player.update(dtAsSeconds, Mouse::getPosition());

            Vector2f playerPosition(player.getCenter());

            mainView.setCenter(player.getCenter());
        }

        /*
        Draw scene
        */
        if (state == State::PLAYING) {
            window.clear();

            window.setView(mainView);

            window.draw(player.getSprite());
        }

        if (state == State::LEVELING_UP) {

        }

        if (state == State::PAUSED) {

        }

        if (state == State::GAME_OVER) {

        }

        window.display();
    }
    return 0;
}


