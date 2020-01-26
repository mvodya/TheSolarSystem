#include <SFML/Graphics.hpp>

namespace gui {

class Window {
  sf::RenderWindow *window;

 public:
  // Инициализация всей программы
  void Init();

  // Цикл программы, запускает отрисовку и просчет физики
  void Loop();

  // Обработка событий
  void EventProcessor(sf::Event event);
};

}  // namespace gui