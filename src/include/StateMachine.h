#ifndef __STATE_MACHINE_H
#define __STATE_MACHINE_H

#include "State.h"

template <class entity_type>
class StateMachine {
 private:
  entity_type* owner;
  State<entity_type>* currentState;
  State<entity_type>* previousState;
  State<entity_type>* globalState;

 public:
  StateMachine(entity_type* owner)
      : owner(owner),
        currentState(nullptr),
        previousState(nullptr),
        globalState(nullptr) {}
  void SetCurrentState(State<entity_type>* state) { currentState = state; }
  void SetPreviousState(State<entity_type>* state) { previousState = state; }
  void SetGlobalState(State<entity_type>* state) { globalState = state; }

  void Update() const {
    if (globalState) globalState->Execute(owner);
    if (currentState) currentState->Execute(owner);
  }
  void ChangeState(State<entity_type>* newState) {
    previousState = currentState;
    currentState->Exit(owner);
    currentState = newState;
    currentState->Enter(owner);
  }
  void RevertToPreviousState() { ChangeState(previousState); }

  State<entity_type>* CurrentState() const { return currentState; }
  State<entity_type>* PreviousState() const { return previousState; }
  State<entity_type>* GlobalState() const { return globalState; }

  bool IsInState(const State<entity_type>* state) const {
    return typeid(*currentState) == typeid(state);
  }
};

#endif