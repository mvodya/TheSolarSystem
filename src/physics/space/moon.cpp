#include "moon.h"

void Moon::Draw(sf::RenderWindow* render, vec2<double> offset, double scale) {
  sf::CircleShape c(draw_radius * scale);
  c.setFillColor(draw_fill_color);
  c.setOutlineThickness(scale);
  c.setOutlineColor(draw_out_color);
  offset = offset + position + parent->position;
  c.setPosition(offset.x - draw_radius * scale, offset.y - draw_radius * scale);
  render->draw(c);
}
