#ifndef __MINER_H
#define __MINER_H

#include <memory>
using std::shared_ptr;

#include "BaseGameEntity.h"
#include "State.h"

class Miner : public BaseGameEntity {
 private:
  shared_ptr<State> currentState;
  location_type location;
  int goldCarried;
  int goldInBank;
  int thirst;
  int fatigue;

 public:
  Miner(int id);
  void Update();
  void ChangeState(shared_ptr<State> newState);
};

#endif