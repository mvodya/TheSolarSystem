#include "planet.h"

void Planet::Draw(sf::RenderWindow* render, vec2<double> offset, double scale) {
  sf::CircleShape c(draw_radius * scale);
  c.setFillColor(draw_fill_color);
  c.setOutlineThickness(scale);
  c.setOutlineColor(draw_out_color);
  offset = offset + position;
  c.setPosition(offset.x - draw_radius * scale, offset.y - draw_radius * scale);
  render->draw(c);

  if (settings->draw_names) {
    sf::Text text;
    text.setFont(this->settings->default_font);
    text.setString(draw_name);
    text.setFillColor(sf::Color::White);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(offset.x - draw_radius * scale,
                     offset.y + (draw_radius * scale) + 3);
    text.setCharacterSize(draw_radius * 2 * scale);
    render->draw(text);
  }
}
