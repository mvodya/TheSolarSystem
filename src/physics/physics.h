#pragma once
#include <map>

#include "object.h"

class Physics {
  std::map<int, Object*> objects;
  // Максимально выданный physics id
  // нужен для регистрации новых объектов
  int max_pid = 0;

 public:
  // Основной тик для физики, обновление всех обхектов
  void Tick();

  // Регистрация объекта в системе физики
  int RegisterObject(Object *object);

  // Удаление объекта из системы физики
  void UnregisterObject(int pid);
};