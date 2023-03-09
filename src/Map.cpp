#include "Map.hpp"

std::vector<sf::String>& Map::getMap() {
  return tileMap;
}
void Map::setMap(std::vector<sf::String> map) {
  tileMap = map;
}
int Map::get_map_height() {
  return MAP_HEIGHT;
}
int Map::get_map_width() {
  return MAP_WIDTH;
}
sf::Sprite& Map::get_map_sprite() {
  return map_sprite;
}
