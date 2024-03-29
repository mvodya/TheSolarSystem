#include "physics.h"

#include <cmath>

void Physics::Tick(double delta, double scale) {
  // Пауза
  if (settings->pause) delta = 0;
  delta_time += delta * 4;
  // Перебор всех объектов
  for (auto [key, object] : objects) {
    // Изменение параметров объекта
    object->position.x =
        sin(delta_time * object->speed.pix()) * object->apogee.pix() * scale;
    object->position.y =
        cos(delta_time * object->speed.pix()) * object->perigee.pix() * scale;
  }
}

int Physics::RegisterObject(Object* object) {
  max_pid++;
  // Добавление объекта
  objects[max_pid] = object;
  return max_pid;
}

void Physics::UnregisterObject(int pid) {
  // Удаление объекта
  objects.erase(pid);
}
