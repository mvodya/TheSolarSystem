#include "canvans.h"
#include "../physics/space/planet.h"

gui::Canvans::Canvans(sf::RenderWindow *rw) {
  // Место отрисовки получаем от окна
  render = rw;
  // Создаем систему физики
  physics = new Physics();

  Planet *p = new Planet("test", 10, sf::Color::Blue, sf::Color::Green);
  objects.push_back(p);
  p->apogee.ae(0.98329134);
  p->perigee.ae(1.00000261);
  p->speed.km(107218);
  p->Init(physics);

  Planet *p2 = new Planet("test2", 8, sf::Color::Red, sf::Color::Yellow);
  objects.push_back(p2);
  p2->apogee.ae(1.381);
  p2->perigee.ae(1.666);
  p2->speed.km(86400);
  p2->Init(physics);
}

void gui::Canvans::Draw() {
  // Перебор всех объектов и вызов отрисовки для них
  for (auto object : objects) object->Draw(render, offset, scale);
}

void gui::Canvans::Tick() {
  // Обновление физики
  physics->Tick(scale);
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
