#include "window.h"

void gui::Window::Init() {
  // Создаем главное окно
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "The Solar System");
  // Установка лимита FPS
  window->setFramerateLimit(60);
  // Вертикальная синхронизация
  window->setVerticalSyncEnabled(true);

  // Создание полотна
  canvans = new gui::Canvans(window);
}

void gui::Window::Loop() {
  // Цикл работает до тех пот, пока главное окно открыто
  while (window->isOpen()) {
    // Обрабатываем события
    sf::Event event;
    while (window->pollEvent(event)) EventProcessor(event);

    // Очистка окна
    window->clear();

    // Отрисовка сетки
    canvans->DrawGrid();
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
    // Изменение размеров окна
    case sf::Event::Resized:
      window->setView(
          sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
      break;

    // Обработка событий мыши
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseMoved:
    case sf::Event::MouseWheelMoved:
      canvans->MouseEvent(event);
      break;

    default:
      break;
  }
}