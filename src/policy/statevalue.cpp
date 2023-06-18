#include <cstdlib>
#include <algorithm>
#include "../state/state.hpp"
#include "./statevalue.hpp"


/**
 * @brief Get a legal action by state value function
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move State_value::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  int max_value = -1 * MAX_VALUE, index = -1;
  for(long unsigned int i = 0; i < actions.size(); i++){
    max_value = std::max(max_value, state->evaluate());
    if(state->evaluate() == max_value) index = i;
  }
  return actions[index];
}