#pragma once
#include <SFML/Graphics.hpp>

namespace gui {

struct Settings {
  // Стандартный шрифт
  sf::Font default_font;

  // Включена ли сетка для полотна?
  static bool draw_grid;

  // Включены ли названия планет?
  static bool draw_names;

  // Включены ли линии центров?
  static bool center_lines;
};

}  // namespace gui