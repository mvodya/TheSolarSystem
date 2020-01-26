#include "window.h"

void gui::Window::Init() {
  // Создаем главное окно
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "The Solar System");
  // Создание полотна
  canvans = new gui::Canvans();
}

void gui::Window::Loop() {
  // Цикл работает до тех пот, пока главное окно открыто
  while (window->isOpen()) {
    // Обрабатываем события
    sf::Event event;
    while (window->pollEvent(event)) EventProcessor(event);

    // Очистка окна
    window->clear();

    // Отрисовка объектов
    canvans->Draw();

    // Обновление физики
    canvans->Tick();

    // Обновления окна (кадра)
    window->display();
  }
}

void gui::Window::EventProcessor(sf::Event event) {
  switch (event.type) {
    // Закрытие окна
    case sf::Event::Closed:
      window->close();
      break;
    default:
      break;
  }
}