#pragma once
#include <SFML/Graphics.hpp>

#include "vec2.h"

class Physics;

class Object {
 public:
  // Расположение объекта
  vec2d position;

  // Вектор силы инерции объекта
  vec2d force;

  // Масса объкта
  // TODO: Mass mass;
  double mass;

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
  virtual void Draw(sf::RenderWindow *render, vec2d& offset) = 0;
};