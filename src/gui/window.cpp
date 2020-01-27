#include "window.h"

void gui::Window::Init() {
  // Создаем главное окно
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "The Solar System");
  // Установка лимита FPS
  window->setFramerateLimit(60);
  // Вертикальная синхронизация
  window->setVerticalSyncEnabled(true);

  // Создаем настрйки отображения
  settings = new gui::Settings();
  settings->center_lines = false;
  settings->draw_grid = true;
  settings->draw_names = true;

  // Загружаем шрифты
  // Если неудачно - программа закроется
  if (!LoadFonts()) {
    window->close();
    return;
  }

  // Создание полотна
  canvans = new gui::Canvans(window, settings);
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
    if (settings->draw_grid) canvans->DrawGrid();
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

    // Обработка нажатий клавиш
    case sf::Event::KeyPressed:
      // Включение / выключение сетки
      if (event.key.code == sf::Keyboard::G)
        settings->draw_grid = !settings->draw_grid;
      // Включение / выключение отображения имен планет
      if (event.key.code == sf::Keyboard::L)
        settings->draw_names = !settings->draw_names;
      // Включение / выключение линий центров
      if (event.key.code == sf::Keyboard::T)
        settings->center_lines = !settings->center_lines;
      break;

    default:
      break;
  }
}

bool gui::Window::LoadFonts() {
  if (!settings->default_font.loadFromFile("Orkney Regular.otf")) {
    // В случае неудачной загрузки - выводим сообщение в консоль и ожидаем enter
    std::cout << "Error while loading fonts!\n";
    std::getchar();
    return false;
  }
  return true;
}