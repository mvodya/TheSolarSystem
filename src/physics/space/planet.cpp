#include "planet.h"

void Planet::Draw(sf::RenderWindow* render, vec2<double> offset, double scale) {
  // Отрисовка линий центров
  if (settings->center_lines) {
    sf::Vertex line[2];
    line[0].position =
        sf::Vector2f(offset.x + position.x - draw_radius * scale,
                     offset.y + position.y - draw_radius * scale);
    line[0].color = sf::Color(0xffffff11);
    line[1].position = sf::Vector2f(offset.x, offset.y);
    line[1].color = sf::Color(0xffffff33);
    render->draw(line, 2, sf::Lines);
  }

  // Отрисовка кольца
  // (при условии что оно установлено)
  if (ring_radius != 0) {
    sf::CircleShape r(ring_radius * scale);
    r.setFillColor(sf::Color(0x00000000));
    r.setOutlineThickness(ring_tickness * scale);
    r.setOutlineColor(ring_color);
    // offset = offset + position;
    r.setPosition(offset.x + position.x - ring_radius * scale,
                  offset.y + position.y - ring_radius * scale);
    render->draw(r);
  }

  // Отрисовка планеты
  sf::CircleShape c(draw_radius * scale);
  c.setFillColor(draw_fill_color);
  c.setOutlineThickness(scale);
  c.setOutlineColor(draw_out_color);
  offset = offset + position;
  c.setPosition(offset.x - draw_radius * scale, offset.y - draw_radius * scale);
  render->draw(c);

  // Отрисовка имени
  if (settings->draw_names) {
    sf::Text text;
    text.setFont(this->settings->default_font);
    text.setString(draw_name);
    text.setFillColor(sf::Color::White);
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(offset.x - draw_radius * scale,
                     offset.y + (draw_radius * scale) + 3);
    text.setCharacterSize(draw_radius * 2 * scale);
    render->draw(text);
  }
}