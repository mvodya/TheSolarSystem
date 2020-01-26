#include "canvans.h"

gui::Canvans::Canvans(sf::RenderWindow *rw) {
  // Место отрисовки получаем от окна
  render = rw;
}

void gui::Canvans::Draw() {
  // TODO: перебор всех объектов и вызов отрисовки для них
  sf::CircleShape c(100);
  render->draw(c);
}

void gui::Canvans::Tick() {
  // TODO: перебор всех объектов и вызов тика
}