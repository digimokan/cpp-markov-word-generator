/*******************************************************************************
module:   MarkovModel
author:   digimokan
date:     08 MAR 2019
purpose:  an nth-order Markov Model for transitions between chars
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <cstddef>
#include <iterator>
#include <string>
#include <unordered_map>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovModel.hpp"
#include "MarkovTransition.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/


MarkovModel::MarkovModel (std::size_t order)
  : order{order}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void MarkovModel::add_transition (const std::string& curr_state_chain, char next_state) {
  assert(this->order == curr_state_chain.size());
  auto [it, success] = this->model.try_emplace(curr_state_chain, MarkovTransition{});
  it->second.add_transition(next_state);
}

char MarkovModel::get_weighted_random_next_state (const std::string& curr_state_chain) const {
  assert(this->order == curr_state_chain.size());
  return this->model.at(curr_state_chain).get_weighted_random_next_state();
}

std::size_t MarkovModel::get_total_num_states () const {
  return this->model.size();
}

