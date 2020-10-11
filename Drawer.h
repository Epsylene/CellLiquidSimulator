
#pragma once

#include "SFML/Graphics.hpp"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;

        sf::Image backgroundImg;
        sf::Texture backgroundTex;
        sf::Sprite background;

        void drawGrid(int anchor, sf::Color&& color);

    public:

        explicit Drawer();

        void update();
        void render();
        void run();
};


