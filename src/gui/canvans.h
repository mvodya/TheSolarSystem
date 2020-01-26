#include <SFML/Graphics.hpp>
#include <stack>

namespace gui {

class Canvans {
  // TODO: массив объектов
  // stack<Obejct> objects;

 public:
  // Отрисовка объектов
  void Draw();

  // Обновление физики у объектов
  void Tick();
}

}  // namespace gui