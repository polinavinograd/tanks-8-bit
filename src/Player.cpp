#include "Player.hpp"
#include "Map.hpp"
#include "Bullet.hpp"

void Player::update(float time) {
  cooldown = cooldown <= 0 ? cooldown : cooldown - time;
  switch(dir) {
    case 0:
      dx = speed;
      dy = 0;
      player_sprite.setOrigin((sf::Vector2f)player_texture.getSize() / 2.f);
      player_sprite.setRotation (270);
      break;
    case 1:
      dx = -speed;
      dy = 0;
      player_sprite.setOrigin((sf::Vector2f)player_texture.getSize() / 2.f);
      player_sprite.setRotation (90);
      break;
    case 2:
      dx = 0;
      dy = speed;
      player_sprite.setOrigin((sf::Vector2f)player_texture.getSize() / 2.f);
      player_sprite.setRotation (0);
      break;
    case 3:
      dx = 0;
      dy = -speed;
      player_sprite.setOrigin((sf::Vector2f)player_texture.getSize() / 2.f);
      player_sprite.setRotation (180);
      break;
    default:
      throw "Wrong direction!";
      break;
  }
  x += dx * time;
  y += dy * time;

  speed = 0;
  player_sprite.setPosition(x, y);

  for (auto& bullet : bullets) {
    if (!bullet) {
      continue;
    }
    bullet->update(time);
  }

  interactWithMap();
}

void Player::interactWithMap() {
  for (int i = (y - height/2)/30; i < (y + height/2)/30; i++){
    for (int j = (x - width/2)/30; j < (x + width/2) / 30; j++) {
      if (map.getMap()[i][j] == '0') {
        if (dy > 0) {
          y = i * 30 - height/2;
        }
        if (dy < 0) {
          y = i * 30 + 30 + height/2;
        }
        if (dx > 0) {
          x = j * 30 - width/2;
        }
        if (dx < 0) {
          x = j * 30 + 30 + width/2;
        }
      }
      if (map.getMap()[i][j] == '1') {
        if (dy > 0) {
          y = i * 30 - height/2;
        }
        if (dy < 0) {
          y = i * 30 + 30 + height/2;
        }
        if (dx > 0) {
          x = j * 30 - width/2;
        }
        if (dx < 0) {
          x = j * 30 + 30 + width/2;
        }
      }
    }
  }
}


void Player::set_x(float x_new) {
  x = x_new;
}
void Player::set_y(float y_new) {
  y = y_new;
}
void Player::set_dir(int dir_new) {
  dir = dir_new;
}
void Player::set_speed(float speed_new) {
  speed = speed_new;
}
void Player::set_dx(float dx_new) {
  dx = dx_new;
}
void Player::set_dy(float dy_new) {
  dy = dy_new;
}

float Player::get_x() {
  return x;
}
float Player::get_y() {
  return y;
}
int Player::get_dir() {
  return dir;
}
sf::Sprite Player::get_player_sprite() {
  return player_sprite;
}

void Player::fire() {
  if (cooldown > 0) {
    return;
  }
  cooldown = default_cooldown;
  bullets.emplace_back(std::make_shared<Bullet>(&map, this, "players_bullet.png", x, y, 3, 3, dir));
}

void Player::destroy_bullet(Bullet* bullet) {
  for(int i = 0;i < bullets.size();i++) {
    if (bullets[i].get() == bullet) {
      bullets[i]->destroy();
      bullets.erase(bullets.begin() + i);
      break;
    }
  }
}

void Player::draw(sf::RenderWindow& window) {
  window.draw(get_player_sprite());
  for (auto &bullet : bullets) {
    window.draw(bullet->get_bullet_sprite());
  }
}



