#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "canvans.h"
#include "settings.h"

namespace gui {

class Window {
  sf::RenderWindow *window;
  // Полотно, хранящие объекты
  gui::Canvans *canvans;
  // Место отрисовки для полотна
  sf::RenderTexture *canvans_render;
  // Настройки
  gui::Settings *settings;

 public:
  // Инициализация всей программы
  void Init();

  // Цикл программы, запускает отрисовку и просчет физики
  void Loop();

  // Обработка событий
  void EventProcessor(sf::Event event);

  // Загрузка шрифтов
  bool LoadFonts();
};

}  // namespace gui