#include "physics.h"

void Physics::Tick() {
  for (auto object_a : objects) {
    for (auto object_b : objects) {
      // TODO: Делаем некую физическую магию между двумя объектами
    }
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
