#include "include/BaseGameEntity.h"

int BaseGameEntity::nextValidId = 0;

void BaseGameEntity::SetId(int val) {
  id = val;
  nextValidId++;
}