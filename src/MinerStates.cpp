#include "include/MinerStates.h"

#include <iostream>
using std::cout;
using std::endl;
using std::make_shared;

#include "include/Locations.h"
#include "include/Miner.h"
#include "include/State.h"

// EnterMineAndDigForNugget
shared_ptr<EnterMineAndDigForNugget> EnterMineAndDigForNugget::Instance() {
  static shared_ptr<EnterMineAndDigForNugget> instance(
      new EnterMineAndDigForNugget);
  return instance;
}

void EnterMineAndDigForNugget::Enter(MinerPtr miner) {
  if (miner->Location() != goldmine) {
    cout << "Miner: Going to goldmine" << endl;
    miner->ChangeLocation(goldmine);
  }
}

void EnterMineAndDigForNugget::Execute(MinerPtr miner) {
  miner->AddToGoldCarried(1);
  miner->IncreateFatigue();

  cout << "Miner: Mining gold" << endl;

  if (miner->PocketsFull()) {
    miner->ChangeState(VisitBankAndDepositGold::Instance());
  }

  if (miner->Thirsty()) {
    miner->ChangeState(QuenchThirst::Instance());
  }
}

void EnterMineAndDigForNugget::Exit(MinerPtr miner) {
  cout << "Miner: Leaving goldmine" << endl;
}

// VisitBankAndDepositGold
shared_ptr<VisitBankAndDepositGold> VisitBankAndDepositGold::Instance() {
  static shared_ptr<VisitBankAndDepositGold> instance(
      new VisitBankAndDepositGold());
  return instance;
}

void VisitBankAndDepositGold::Enter(MinerPtr miner) {
  if (miner->Location() != bank) {
    cout << "Miner: Going to bank" << endl;
    miner->ChangeLocation(bank);
  }
}

void VisitBankAndDepositGold::Execute(MinerPtr miner) {
  miner->AddToWealth(miner->GoldCarried());
  miner->SetGoldCarried(0);
  cout << "Miner: Depositing gold. Total wealth: " << miner->Wealth() << endl;
  if (miner->Wealth() >= ComfortLevel) {
    cout << "Miner: Has enough money" << endl;
    miner->ChangeState(GoHomeAndSleepTilRested::Instance());
  } else {
    miner->ChangeState(EnterMineAndDigForNugget::Instance());
  }
}

void VisitBankAndDepositGold::Exit(MinerPtr miner) {
  cout << "Miner: Leaving bank" << endl;
}

// GoHomeAndSleepTilRested
shared_ptr<GoHomeAndSleepTilRested> GoHomeAndSleepTilRested::Instance() {
  static shared_ptr<GoHomeAndSleepTilRested> instance(
      new GoHomeAndSleepTilRested());
  return instance;
}

void GoHomeAndSleepTilRested::Enter(MinerPtr miner) {
  if (miner->Location() != shack) {
    cout << "Miner: Going home" << endl;
    miner->ChangeLocation(shack);
  }
}

void GoHomeAndSleepTilRested::Execute(MinerPtr miner) {
  if (!miner->Fatigued()) {
    cout << "Miner: No longer fatigued" << endl;
    miner->ChangeState(EnterMineAndDigForNugget::Instance());
  } else {
    cout << "Miner: zzz" << endl;
    miner->DecreaseFatigue();
  }
}

void GoHomeAndSleepTilRested::Exit(MinerPtr miner) {
  cout << "Miner: Leaving home" << endl;
}

// QuenchThirst
shared_ptr<QuenchThirst> QuenchThirst::Instance() {
  static shared_ptr<QuenchThirst> instance(new QuenchThirst());
  return instance;
}

void QuenchThirst::Enter(MinerPtr miner) {
  if (miner->Location() != saloon) {
    cout << "Miner: Going to saloon" << endl;
    miner->ChangeLocation(saloon);
  }
}

void QuenchThirst::Execute(MinerPtr miner) {
  if (miner->Thirsty()) {
    cout << "Miner: Getting drunk" << endl;
    miner->BuyAndDrinkWhiskey();
    miner->ChangeState(EnterMineAndDigForNugget::Instance());
  } else {
    cout << "Something went wrong - should be thirsty" << endl;
  }
}

void QuenchThirst::Exit(MinerPtr miner) {
  cout << "Miner: Having trouble walking straight" << endl;
}