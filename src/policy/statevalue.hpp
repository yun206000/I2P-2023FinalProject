#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for statevalue policy, 
 * your policy class should have get_move method
 */
class State_value{
public:
  static Move get_move(State *state, int depth);
};