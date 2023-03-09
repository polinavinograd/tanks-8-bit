#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
class Map {
  private:
    static const int MAP_HEIGHT = 20;
    static const int MAP_WIDTH = 30;
    std::vector<sf::String> tileMap;
    sf::Image map_img;
    sf::Texture map_texture;
    sf::Sprite map_sprite;
  public:
    Map(std::string filename) {
      std::ifstream in("../" + filename);
      if (in.is_open()) {
        for (int i = 0;i < MAP_HEIGHT;i++) {
          std::string buf;
          std::getline(in, buf);
          tileMap.emplace_back(buf);
        }
      } else throw std::invalid_argument("Can't open map file!");

      map_img.loadFromFile("../img/texture.png");
      map_texture.loadFromImage(map_img);
      map_sprite.setTexture(map_texture);
    }
    std::vector<sf::String>& getMap();
    void setMap(std::vector<sf::String> map);

    int get_map_height();
    int get_map_width();
    sf::Sprite& get_map_sprite();
};