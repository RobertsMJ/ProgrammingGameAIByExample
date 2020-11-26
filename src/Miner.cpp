#include "include/Miner.h"

void Miner::Update() {
  thirst++;
  if (currentState) {
    currentState.Execute(this);
  }
}