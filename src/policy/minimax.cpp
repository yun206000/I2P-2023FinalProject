#include <cstdlib>
#include <algorithm>
#include "../state/state.hpp"
#include "./minimax.hpp"

/**
 * @brief Get a legal action by minimax algorithm
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  int max_value = -1 * MAX_VALUE, index = -1;
  for(long unsigned int i = 0; i < actions.size(); i++){
    int value = minimax(state->next_state(actions[i]), depth, false);
    max_value = std::max(max_value, value);
    if(max_value == value) index = i;
  }
  return actions[index];
}

int minimax(State *state, int depth, int maximizingPlayer){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  if(depth == 0 || state->legal_actions.empty())
    return state->evaluate();
  int value; 
  if(maximizingPlayer){
    value = -1 * MAX_VALUE;
    for(auto actions : state->legal_actions){
      State* next_state = state->next_state(actions);
      value = std::max(value, minimax(next_state, depth-1, false));
    }
  }
  else{
    value = MAX_VALUE;
    for(auto actions : state->legal_actions){
      State* next_state = state->next_state(actions);
      value = std::min(value, minimax(next_state, depth-1, true));
    }
  }
  return value;
}