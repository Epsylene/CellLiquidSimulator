
#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class Liquid
{
    private:

        struct Cell
        {
            int x, y;
            short flowDir;
        };

        std::vector<Cell> cells;

    public:

        void draw(sf::RenderWindow& window, sf::Image& img, sf::Texture& tex, sf::Sprite& sprite,  int gridAnchor);

        Liquid() = default;
};
