#include "canvans.h"

gui::Canvans::Canvans(sf::RenderWindow *rw) {
  // Место отрисовки получаем от окна
  render = rw;
  // Создаем систему физики
  physics = new Physics();
}

void gui::Canvans::Draw() {
  // Перебор всех объектов и вызов отрисовки для них
  for (auto object : objects) object->Draw(render, offset);
}

void gui::Canvans::Tick() {
  // Обновление физики
  physics->Tick();
}

void gui::Canvans::DrawGrid() {
  sf::View view = render->getView();
  int size_x = view.getSize().x * scale;
  int size_y = view.getSize().y * scale;
  int size_grid = 20 * scale;
  sf::Color grid_color = sf::Color::Color(255 / 8, 255 / 8, 255 / 8);

  // Отрисовка по X
  for (int off = (size_x / 2) + offset.x; off > 0; off -= size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(off, 0);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(off, view.getSize().y);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  for (int off = (size_x / 2) + offset.x; off <= view.getSize().x;
       off += size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(off, 0);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(off, view.getSize().y);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  // Отрисовка по Y
  for (int off = (size_y / 2) + offset.y; off > 0; off -= size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, off);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(view.getSize().x, off);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  for (int off = (size_y / 2) + offset.y; off <= view.getSize().y;
       off += size_grid) {
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, off);
    line[0].color = grid_color;
    line[1].position = sf::Vector2f(view.getSize().x, off);
    line[1].color = grid_color;
    render->draw(line, 2, sf::Lines);
  }

  // test circle
  sf::CircleShape c(5 * scale);
  c.setFillColor(sf::Color::White);
  c.setPosition(offset.x, offset.y);
  render->draw(c);
}

void gui::Canvans::MouseEvent(sf::Event mouse_event) {
  // Перемещение по ЛКМ
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    offset.x += sf::Mouse::getPosition().x - last_mouse_pos.x;
    offset.y += sf::Mouse::getPosition().y - last_mouse_pos.y;
  }
  // Зумирование колесом мыши
  if (mouse_event.type == sf::Event::MouseWheelMoved) {
    double new_scale = scale + mouse_event.mouseWheel.delta * 0.1;
    if (new_scale > 3 || new_scale < 0.5) return;
    scale = new_scale;
  }

  // Записываем позицию мышки
  last_mouse_pos.x = sf::Mouse::getPosition().x;
  last_mouse_pos.y = sf::Mouse::getPosition().y;
}
