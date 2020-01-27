#include "physics.h"

void Physics::Tick() {
  // Промежуточные расчеты изменения сил инерции
  std::map<int, vec2d> miracle;
  for (auto object_a : objects) {
    vec2d f = object_a.force;
    for (auto object_b : objects) {
      // TODO: Делаем некую физическую магию между двумя объектами
      // double distance = vec2::distance(object_a.position,  object_b.position); 
      // vec2d direction = object_a.position - object_b.position;
      // direction = direction.normalization();
      // direction = direction * (1/distance);
      // f = f + direction;
    }
    miracle[object_a.GetPID()] = f;
  }
  // Запись расчетов
  for (auto object : objects) {
    object.force = miracle[object.GetPID()];
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
