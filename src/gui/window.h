#include <SFML/Graphics.hpp>

#include "canvans.h"

namespace gui {

class Window {
  // Главное окно
  sf::RenderWindow *window;
  // Полотно, хранящие объекты
  gui::Canvans *canvans;

 public:
  // Инициализация всей программы
  void Init();

  // Цикл программы, запускает отрисовку и просчет физики
  void Loop();

  // Обработка событий
  void EventProcessor(sf::Event event);
};

}  // namespace gui