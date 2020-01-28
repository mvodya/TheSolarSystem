#pragma once
#include <SFML/Graphics.hpp>

namespace gui {

struct Settings {
  // Стандартный шрифт
  sf::Font default_font;

  // Включена ли сетка для полотна?
  bool draw_grid;

  // Включены ли названия планет?
  bool draw_names;

  // Включены ли линии центров?
  bool center_lines;

  // Включена ли пауза?
  bool pause;
};

}  // namespace gui