#include "canvans.h"

gui::Canvans::Canvans(sf::RenderWindow *rw) {
  // Место отрисовки получаем от окна
  render = rw;
  // Создаем систему физики
  physics = new Physics();
}

void gui::Canvans::Draw() {
  // Перебор всех объектов и вызов отрисовки для них
  for (auto object : objects) object->Draw();
}

void gui::Canvans::Tick() {
  // Обновление физики
  physics->Tick();
}

void gui::Canvans::DrawGrid() {
  sf::View view = render->getView();
  int size_x = view.getSize().x;
  int size_y = view.getSize().y;
  int size_grid = 20 * scale;
  sf::Color grid_color = sf::Color::Color(255 / 8, 255 / 8, 255 / 8);

  // Отрисовка по X
  for (int off = (size_x / 2) + offset.x; off > 0; off -= size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(off, 0);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(off, size_y);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  for (int off = (size_x / 2) + offset.x; off <= size_x; off += size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(off, 0);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(off, size_y);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  // Отрисовка по Y
  for (int off = (size_y / 2) + offset.y; off > 0; off -= size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, off);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(size_x, off);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  for (int off = (size_y / 2) + offset.y; off <= size_y; off += size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, off);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(size_x, off);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }
}