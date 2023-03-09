#include "Bullet.hpp"
#include "Player.hpp"
#include <iostream>

void Bullet::update(float time) {
  if (!alive) {
    return;
  }
    switch(dir) {
    case 0:
      dx = speed;
      dy = 0;
      break;
    case 1:
      dx = -speed;
      dy = 0;
      break;
    case 2:
      dx = 0;
      dy = speed;
      break;
    case 3:
      dx = 0;
      dy = -speed;
      break;
    default:
      throw std::invalid_argument("Wrong direction!");
      break;
  }
  x += dx * time;
  y += dy * time;
  bullet_sprite.setPosition(x, y);
  interactWithMap();
}
void Bullet::interactWithMap() {
 for (int i = (y - height/2)/30; i < (y + height/2)/30; i++){
    for (int j = (x - width/2)/30; j < (x + width/2) / 30; j++) {
      if (i >= map->getMap().size() || j >= map->getMap()[i].getSize()) {
        return;
      }
      if (map->getMap()[i][j] == '0') {
        speed = 0;
        player->destroy_bullet(this);
      }
      if (map->getMap()[i][j] == '1') {
        map->getMap()[i][j] = ' ';
        speed = 0;
        player->destroy_bullet(this);
      }
    }
  }
}

void Bullet::destroy() {
  alive = false;
}

sf::Sprite& Bullet::get_bullet_sprite() {
  return bullet_sprite;
}
