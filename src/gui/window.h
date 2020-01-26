#pragma once
#include <SFML/Graphics.hpp>

#include "canvans.h"

namespace gui {

class Window {
  sf::RenderWindow *window;
  // Полотно, хранящие объекты
  gui::Canvans *canvans;
  // Место отрисовки для полотна
  sf::RenderTexture *canvans_render;

 public:
  // Инициализация всей программы
  void Init();

  // Цикл программы, запускает отрисовку и просчет физики
  void Loop();

  // Обработка событий
  void EventProcessor(sf::Event event);
};

}  // namespace gui