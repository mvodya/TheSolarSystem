#include "physics.h"

#include <cmath>

void Physics::Tick(double scale) {
  delta_time += 0.0001;
  for (auto [key, object] : objects) {
    object->position.x = sin(delta_time) * object->apogee.pix() * scale;
    object->position.y = cos(delta_time) * object->perigee.pix() * scale;
    continue;
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
