#include "include/Miner.h"

#include "include/MinerStates.h"

Miner::Miner(int id)
    : BaseGameEntity(id),
      location(shack),
      goldCarried(0),
      goldInBank(0),
      thirst(0),
      fatigue(0),
      stateMachine(StateMachine<Miner>(this)) {
  stateMachine.SetCurrentState(GoHomeAndSleepTilRested::Instance());
}

void Miner::ChangeState(StatePtr newState) {
  stateMachine.ChangeState(newState);
}

void Miner::AddToGoldCarried(const int gold) {
  goldCarried += gold;
  if (goldCarried < 0) goldCarried = 0;
}

void Miner::AddToWealth(const int wealth) {
  goldInBank += wealth;
  if (goldInBank < 0) goldInBank = 0;
}

void Miner::BuyAndDrinkWhiskey() {
  thirst = 0;
  goldInBank -= 2;
}

void Miner::Update() {
  thirst++;
  stateMachine.Update();
}
