#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../physics/object.h"
#include "../physics/physics.h"

namespace gui {

class Canvans {
  // Массив объектов
  std::vector<Object*> objects;

  // Окно для рендера
  sf::RenderWindow *render;

  // Система физики
  Physics *physics;

 public:
  Canvans(sf::RenderWindow *rw);

  // Отрисовка объектов
  void Draw();

  // Обновление физики у объектов
  void Tick();
};

}  // namespace gui