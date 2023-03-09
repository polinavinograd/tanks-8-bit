#include "src/Player.hpp"
#include "src/Map.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "8-bit tanks");
    sf::Clock clock;
    Map map("map.txt");
    Player p(map, "tank.png",200, 200, 26.0, 30.0, 400);
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
            p.set_dir(0); 
            p.set_speed(0.1);
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
            p.set_dir(1); 
            p.set_speed(0.1);
        }
 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { 
            p.set_dir(2); 
            p.set_speed(0.1);
        } 

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
            p.set_dir(3); 
            p.set_speed(0.1);
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
            p.fire();
        }
 
        p.update(time);

        window.clear();

        for (int i = 0; i < map.get_map_height(); i++) {
            for (int j = 0; j < map.get_map_width(); j++) {
                if (map.getMap()[i][j] == '0') {
                    map.get_map_sprite().setTextureRect(sf::IntRect(30,0,30,30));
                }
                if (map.getMap()[i][j] == '1') {
                    map.get_map_sprite().setTextureRect(sf::IntRect(60,0,30,30));
                }
                if (map.getMap()[i][j] == ' ') {
                    map.get_map_sprite().setTextureRect(sf::IntRect(0,0,30,30));
                }

                map.get_map_sprite().setPosition (j * 30, i * 30);
                window.draw(map.get_map_sprite());
            }
        }
        p.draw(window);
        window.display();
    }

    return 0;
}