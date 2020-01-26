#include <SFML/Graphics.hpp>
#include <stack>

namespace gui {

class Canvans {
  // TODO: массив объектов
  // stack<Obejct> objects;

  // Окно для рендера
  sf::RenderWindow *render;

 public:
  Canvans(sf::RenderWindow *rw);

  // Отрисовка объектов
  void Draw();

  // Обновление физики у объектов
  void Tick();
};

}  // namespace gui