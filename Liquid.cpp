
#include "Liquid.h"


void Liquid::draw(sf::RenderWindow& window, sf::Image& img, sf::Texture& tex, sf::Sprite& sprite, int gridAnchor)
{
    for (auto& c: cells) 
    {
        for (int i = 0; i < gridAnchor; ++i)
        {
            img.setPixel(c.x, c.y, sf::Color::Blue);
        }
    }
}
