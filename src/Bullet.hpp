#pragma once

#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Player;

class Bullet {
  private:
    float x, y, width, height, dx, dy, speed = 0.3;
    int dir = 0;
    sf::Image bullet_img;
    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
    Map *map;
    Player *player;
    bool alive = true;
  public:
    Bullet(Map *map, Player *p, std::string filename, float x_pos, float y_pos, float bullet_width, float bullet_height, int dir) : dir(dir), map(map), player(p){
      bullet_img.loadFromFile("../img/" + filename);
      bullet_img.createMaskFromColor(sf::Color(255, 255, 255));
      bullet_texture.loadFromImage(bullet_img);
      bullet_sprite.setTexture(bullet_texture);
      x = x_pos;
      y = y_pos;
      width = bullet_width;
      height = bullet_height;
      bullet_sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    }
    void update(float time);
    void interactWithMap();

    float get_x();
    float get_y();
    int get_dir();
    sf::Sprite& get_bullet_sprite();
    void destroy();
};