#include <iostream>

#include "include/Miner.h"

using namespace std;

int main() {
  Miner miner(0);
  for (int i = 0; i < 20; i++) {
    miner.Update();
  }
  return 0;
}