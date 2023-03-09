#pragma once

#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <memory>

class Bullet;

class Player {
  private:
    float x, y, width, height, dx, dy, speed = 0;
    int dir = 0;
    sf::Image player_img;
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    Map &map;
    std::vector<std::shared_ptr<Bullet>> bullets;
    float cooldown;
    float default_cooldown;
  public:
    Player(Map &new_map, std::string filename, float x_pos, float y_pos, float player_width, float player_height, float default_cooldown) : map(new_map), default_cooldown(default_cooldown) {
      player_img.loadFromFile("img/" + filename);
      player_img.createMaskFromColor(sf::Color(255, 255, 255));
      player_texture.loadFromImage(player_img);
      player_sprite.setTexture(player_texture);
      x = x_pos;
      y = y_pos;
      width = player_width;
      height = player_height;
      player_sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    };
    void update(float time);
    void interactWithMap();

    float get_x();
    float get_y();
    int get_dir();
    sf::Sprite get_player_sprite();

    void set_x(float x_new);
    void set_y(float y_new);
    void set_dir(int dir_new);
    void set_speed(float speed_new);
    void set_dx(float dx_new);
    void set_dy(float dy_new);

    void fire();

    void destroy_bullet(Bullet* bullet);
    void draw(sf::RenderWindow& window);
};
