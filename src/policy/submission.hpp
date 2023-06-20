#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for alpha beta policy, 
 * your policy class should have get_move method
 */
class Alpha_{
public:
  static Move get_move(State *state, int depth);
  static int alphabeta(State *state, int alpha, int beta, int depth, bool maximizingPlayer);
};