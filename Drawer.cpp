
#include "Drawer.h"

Drawer::Drawer()
{
    window.create({1024, 576}, "Lignes de champ", sf::Style::Titlebar | sf::Style::Close);

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

    drawGrid(10, sf::Color(200, 200, 200));
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
    for (int x = anchor; x < window.getSize().x; x += anchor)
    {
        for (int y = anchor; y < window.getSize().y; y += anchor)
        {
            for (int i = anchor; i > 0; --i)
            {
                backgroundImg.setPixel(x - i, y, color);
                backgroundImg.setPixel(x, y - i, color);
            }
        }
    }

    //@TODO: conditional for to fill the background
    // entirely with the grid

    backgroundTex.update(backgroundImg);
}
