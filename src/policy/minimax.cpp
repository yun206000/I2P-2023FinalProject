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
  /*for(long unsigned int i = 0; i < actions.size(); i++){
    
  }*/
  return actions[(rand()+depth)%actions.size()];
}

int Minimax::minimax(State *state, int depth, int maximizingPlayer){
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