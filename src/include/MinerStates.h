#ifndef __MINER_STATES_H
#define __MINER_STATES_H
#include <memory>
using std::shared_ptr;

#include "State.h"
class Miner;

typedef Miner* MinerPtr;

// Miner walks to gold mine + picks up a nugget of gold
// If he has a nugget, transition to VisitBankAndDepositGold
// If thirsty, transition to QuenchThirst
class EnterMineAndDigForNugget : public State {
 private:
  EnterMineAndDigForNugget() {}
  EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
  EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

 public:
  static shared_ptr<EnterMineAndDigForNugget> Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// Miner goes to bank and deposits his gold
// If wealthy enough, go home
// Otherwise, get more gold
class VisitBankAndDepositGold : public State {
 private:
  VisitBankAndDepositGold() {}
  VisitBankAndDepositGold(const VisitBankAndDepositGold&);
  VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

 public:
  static shared_ptr<VisitBankAndDepositGold> Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// Miner goes home and sleeps until fatigue is sufficiently low
class GoHomeAndSleepTilRested : public State {
 private:
  GoHomeAndSleepTilRested() {}
  GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
  GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

 public:
  static shared_ptr<GoHomeAndSleepTilRested> Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// hit the bar
class QuenchThirst : public State {
 private:
  QuenchThirst() {}
  QuenchThirst(const QuenchThirst&);
  QuenchThirst& operator=(const QuenchThirst&);

 public:
  static shared_ptr<QuenchThirst> Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

#endif