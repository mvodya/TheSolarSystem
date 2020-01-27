#include "moon.h"

void Moon::Draw(sf::RenderWindow* render, vec2<double> offset, double scale) {
  // Отрисовка линий центров
  if (settings->center_lines) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(
        offset.x + position.x + parent->position.x - draw_radius * scale,
        offset.y + position.y + parent->position.y - draw_radius * scale);
    line[0].color = sf::Color(0xffffff11);
    line[1].position = sf::Vector2f(offset.x + parent->position.x,
                                    offset.y + parent->position.y);
    line[1].color = sf::Color(0xffffff33);
    render->draw(line, 2, sf::Lines);
  }

  // Отрисовка луны
  sf::CircleShape c(draw_radius * scale);
  c.setFillColor(draw_fill_color);
  c.setOutlineThickness(scale);
  c.setOutlineColor(draw_out_color);
  offset = offset + position + parent->position;
  c.setPosition(offset.x - draw_radius * scale, offset.y - draw_radius * scale);
  render->draw(c);
}
