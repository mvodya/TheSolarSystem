#include "object.h"

#include "physics.h"

Object::Object(Physics* p) {
  physics = p;
  // Записиываем physics id после регистрации в системе физики
  pid = physics->RegisterObject(this);
}

Object::~Object() {
  // Удаляем объект из системы физики
  physics->UnregisterObject(pid);
}
