#pragma once
#include <SFML/Graphics.hpp>

#include "distance.h"
#include "vec2.h"
#include "../gui/settings.h"

class Physics;

class Object {
 public:
  // Расположение объекта
  vec2d position;
  // Настройки отображения
  gui::Settings* settings;

  // Апогей
  Distance apogee;
  // Перигей
  Distance perigee;
  // Орбитальная скорость
  Distance speed;

 private:
  // Система физики, в которой зарегистрирован объект
  Physics* physics;
  // id объекта в системе физики
  int pid = 0;

 public:
  // Деструктор
  ~Object();

  // Инициализация объекта
  void Init(Physics* p, gui::Settings* s);

  // Отрисовка объекта
  virtual void Draw(sf::RenderWindow* render, vec2d offset, double scale) = 0;

  // Получение physical id
  int GetPID() { return pid; }
};