#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../object.h"

class Planet : public Object {
  double draw_radius;
  sf::Color draw_fill_color;
  sf::Color draw_out_color;
  std::string draw_name;

 public:
  Planet(std::string name, double radius, sf::Color color_fill,
         sf::Color color_out)
      : draw_name(name),
        draw_radius(radius),
        draw_fill_color(color_fill),
        draw_out_color(color_out){};

  virtual void Draw(sf::RenderWindow* render, vec2<double> offset,
                    double scale);
};