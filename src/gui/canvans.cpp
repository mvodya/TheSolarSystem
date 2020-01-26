#include "canvans.h"

gui::Canvans::Canvans(sf::RenderWindow *rw) {
  // Место отрисовки получаем от окна
  render = rw;
  // Создаем систему физики
  physics = new Physics();
}

void gui::Canvans::Draw() {
  // Перебор всех объектов и вызов отрисовки для них
  for (auto object : objects) object->Draw();
}

void gui::Canvans::Tick() {
  // Обновление физики
  physics->Tick();
}