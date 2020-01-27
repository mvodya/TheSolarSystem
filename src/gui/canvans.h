#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../physics/vec2.h"
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

  // Смещение, место, где расположен (0; 0) на экране
  vec2d offset;
  // Маштаб полотна, коэфициент, влияющий на отображаемые размеры
  double scale = 1;

  // Последняя позиция мышки
  vec2i last_mouse_pos;

 public:
  Canvans(sf::RenderWindow *rw);

  // Отрисовка объектов
  void Draw();

  // Обновление физики у объектов
  void Tick();

  // Рисуем сетку
  void DrawGrid();

  // Обработка мыши
  void MouseEvent(sf::Event mouse_event);
};

}  // namespace gui