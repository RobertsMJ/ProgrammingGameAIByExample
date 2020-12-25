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
class EnterMineAndDigForNugget : public State<Miner> {
 private:
  EnterMineAndDigForNugget() {}
  EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
  EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

 public:
  static EnterMineAndDigForNugget* Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// Miner goes to bank and deposits his gold
// If wealthy enough, go home
// Otherwise, get more gold
class VisitBankAndDepositGold : public State<Miner> {
 private:
  VisitBankAndDepositGold() {}
  VisitBankAndDepositGold(const VisitBankAndDepositGold&);
  VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

 public:
  static VisitBankAndDepositGold* Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// Miner goes home and sleeps until fatigue is sufficiently low
class GoHomeAndSleepTilRested : public State<Miner> {
 private:
  GoHomeAndSleepTilRested() {}
  GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
  GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

 public:
  static GoHomeAndSleepTilRested* Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

// hit the bar
class QuenchThirst : public State<Miner> {
 private:
  QuenchThirst() {}
  QuenchThirst(const QuenchThirst&);
  QuenchThirst& operator=(const QuenchThirst&);

 public:
  static QuenchThirst* Instance();
  virtual void Enter(MinerPtr miner);
  virtual void Execute(MinerPtr miner);
  virtual void Exit(MinerPtr miner);
};

#endif