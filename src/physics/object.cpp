#include "object.h"

#include "physics.h"

void Object::Init(Physics* p, gui::Settings *s) {
  physics = p;
  settings = s;
  // Записиываем physics id после регистрации в системе физики
  pid = physics->RegisterObject(this);
}

Object::~Object() {
  // Удаляем объект из системы физики
  if (!pid) physics->UnregisterObject(pid);
}