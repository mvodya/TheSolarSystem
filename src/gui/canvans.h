#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../physics/object.h"
#include "../physics/physics.h"

namespace gui {

class Canvans {
  // Массив объектов
  std::vector<Object *> objects;

  // Окно для рендера
  sf::RenderWindow *render;

  // Система физики
  Physics *physics;

  // TODO: Смещение, месте, где расположен (0; 0) на экране
  // vec2<double> offset;
  // Маштаб полотна, коэфициент, влияющий на отображаемые размеры
  double scale = 1;

 public:
  Canvans(sf::RenderWindow *rw);

  // Отрисовка объектов
  void Draw();

  // Обновление физики у объектов
  void Tick();
};

}  // namespace gui