#pragma once
class Physics;

class Object {
  // Расположение объекта
  // vec2<double> position;

  // Вектор силы инерции объекта
  // vec2<double> force;

  // Масса объкта
  // Mass mass;

  // Система физики, в которой зарегистрирован объект
  Physics* physics;
  // id объекта в системе физики
  int pid;

 public:
  Object(Physics* p);

  ~Object();

  // Отрисовка объекта
  virtual void Draw() = 0;
};