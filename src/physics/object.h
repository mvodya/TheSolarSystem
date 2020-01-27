#pragma once
#include <SFML/Graphics.hpp>

#include "distance.h"
#include "vec2.h"

class Physics;

class Object {
 public:
  // Расположение объекта
  vec2d position;

  // Апогей
  Distance apogee;
  // Перигей
  Distance perigee;

 private:
  // Система физики, в которой зарегистрирован объект
  Physics* physics;
  // id объекта в системе физики
  int pid = 0;

 public:
  // Деструктор
  ~Object();

  // Инициализация объекта
  void Init(Physics* p);

  // Отрисовка объекта
  virtual void Draw(sf::RenderWindow* render, vec2d offset, double scale) = 0;

  // Получение physical id
  int GetPID() { return pid; }
};