#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "../state/state.hpp"
#include "./alphabeta.hpp"

/**
 * @brief Get a legal action by minimax algorithm
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alpha_Beta::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  int max_value = -1 * MAX_VALUE, index = 0;
  int alpha = -1 * MAX_VALUE, beta = MAX_VALUE;
  for(long unsigned int i = 0; i < actions.size(); i++){
    int value = alphabeta(state->next_state(actions[i]), alpha, beta, depth, false);
    max_value = std::max(max_value, value);
    alpha = std::max(max_value, alpha);
    if(max_value == value) index = i;
    if(alpha > beta) break;
  }
  return actions[index];
}

int Alpha_Beta::alphabeta(State *state,int alpha, int beta, int depth, bool maximizingPlayer){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  if(depth == 0 || !state->legal_actions.size())
    return state->evaluate();
  int value; 
  if(maximizingPlayer){
    value = -1 * MAX_VALUE;
    for(auto actions : state->legal_actions){
      State* next_state = state->next_state(actions);
      value = std::max(value, alphabeta(next_state, alpha, beta, depth-1, false));
      alpha = std::max(alpha, value);
      if(alpha > beta) break;
    }
  }
  else{
    value = MAX_VALUE;
    for(auto actions : state->legal_actions){
      State* next_state = state->next_state(actions);
      value = std::min(value, alphabeta(next_state, alpha, beta, depth-1, true));
      beta = std::min(beta, value);
      if(beta < alpha) break;
    }
  }
  return value;
}