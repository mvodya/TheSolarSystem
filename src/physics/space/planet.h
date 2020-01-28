#pragma once
#include <SFML/Graphics.hpp>

#include "../object.h"

class Planet : public Object {
  // Отображаемый радиус
  double draw_radius;
  // Отображаемый цвет заливки
  sf::Color draw_fill_color;
  // Отображаемый цвет контура
  sf::Color draw_out_color;
  // Отображаемое имя
  std::string draw_name;

  // Цвет кольца
  sf::Color ring_color;
  // Радиус кольца (0 - отключено)
  double ring_radius = 0;
  // Толщина кольца
  double ring_tickness = 1;

 public:
  Planet(std::string name, double radius, sf::Color color_fill,
         sf::Color color_out)
      : draw_name(name),
        draw_radius(radius),
        draw_fill_color(color_fill),
        draw_out_color(color_out) {
    // Цвет кольца по умолчанию
    ring_color = sf::Color(0xffffff22);
  };

  virtual void Draw(sf::RenderWindow* render, vec2<double> offset,
                    double scale);

  // Установка кольца
  void SetRing(sf::Color c, double radius = 3, double tickness = 1) {
    ring_color = c;
    ring_radius = radius;
    ring_tickness = tickness;
  };
};