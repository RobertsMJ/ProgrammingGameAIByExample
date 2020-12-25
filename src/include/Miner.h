#ifndef __MINER_H
#define __MINER_H

#include <memory>
using std::enable_shared_from_this;
using std::shared_ptr;

#include "BaseGameEntity.h"
#include "Locations.h"
#include "State.h"
#include "StateMachine.h"

class Miner;
typedef State<Miner>* StatePtr;

const int ComfortLevel = 5;
const int MaxGold = 3;
const int ThirstLevel = 5;
const int TiredThreshold = 5;

class Miner : public BaseGameEntity {
 private:
  location_type location;
  int goldCarried;
  int goldInBank;
  int thirst;
  int fatigue;
  StateMachine<Miner> stateMachine;

 public:
  Miner(int id);
  void Update();
  void ChangeState(StatePtr newState);

  location_type Location() const { return location; }
  void ChangeLocation(const location_type loc) { location = loc; }

  int GoldCarried() const { return goldCarried; }
  void SetGoldCarried(const int gold) { goldCarried = gold; }
  void AddToGoldCarried(const int gold);
  bool PocketsFull() const { return goldCarried >= MaxGold; }

  bool Fatigued() const { return fatigue > TiredThreshold; };
  void DecreaseFatigue() { fatigue--; }
  void IncreateFatigue() { fatigue++; }

  int Wealth() const { return goldInBank; }
  void SetWealth(const int wealth) { goldInBank = wealth; }
  void AddToWealth(const int wealth);

  bool Thirsty() const { return thirst > ThirstLevel; };
  void BuyAndDrinkWhiskey();
};

#endif