
#include "Drawer.h"

Drawer::Drawer()
{
    window.create({1024, 576}, "Cell liquid simulator", sf::Style::Titlebar | sf::Style::Close);

    backgroundImg.create(window.getSize().x, window.getSize().y, sf::Color::White);
    backgroundTex.create(window.getSize().x, window.getSize().y);
    background.setTexture(backgroundTex);
}

void Drawer::update()
{
    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    drawGrid(gridAnchor, sf::Color(200, 200, 200));
}

void Drawer::render()
{
    window.clear(sf::Color::White);

    window.draw(background);

    window.display();
}

void Drawer::run()
{
    while(window.isOpen())
    {
        update();
        render();
    }
}

void Drawer::drawGrid(int anchor, sf::Color&& color)
{
    //Draw the grid
    for (int x = 0; x < window.getSize().x; x += anchor)
    {
        for (int y = 0; y < window.getSize().y; y += anchor)
        {
            if(window.getSize().x - x > anchor)
            {
                for (int i = 0; i < anchor; ++i)
                {
                    backgroundImg.setPixel(x + i, y, color);
                }
            }
            else
            {
                for (int i = 0; i < window.getSize().x - x; ++i)
                {
                    backgroundImg.setPixel(x + i, y, color);
                }
            }

            if(window.getSize().y - y > anchor)
            {
                for (int i = 0; i < anchor; ++i)
                {
                    backgroundImg.setPixel(x, y + i, color);
                }
            }
            else
            {
                for (int i = 0; i < window.getSize().y - y; ++i)
                {
                    backgroundImg.setPixel(x, y + i, color);
                }
            }
        }
    }

    //Delete the lines at the borders
    for (int x = 0; x < window.getSize().x; ++x)
    {
        for (int y = 0; y < window.getSize().y; ++y)
        {
            if(x == 0 || x == window.getSize().x - 1
                || y == 0 || y == window.getSize().y - 1)
            {
                backgroundImg.setPixel(x, y, sf::Color::White);
            }
        }
    }

    backgroundTex.update(backgroundImg);
}
