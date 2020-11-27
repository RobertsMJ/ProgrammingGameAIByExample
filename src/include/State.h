#ifndef __STATE_H
#define __STATE_H

class Miner;

class State {
 public:
  virtual ~State() {}
  virtual void Enter(Miner*) = 0;
  virtual void Execute(Miner*) = 0;
  virtual void Exit(Miner*) = 0;
};

#endif