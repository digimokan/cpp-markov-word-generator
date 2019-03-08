/*******************************************************************************
module:   MarkovTransition
author:   digimokan
date:     07 MAR 2019
purpose:  store a weighted transition for a given markov state
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <random>
#include <unordered_set>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovTransition.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void MarkovTransition::add_transition (char next_state) {
  this->transitions.emplace(next_state);
}

std::size_t MarkovTransition::get_weight (char next_state) const {
  return this->transitions.count(next_state);
}

std::size_t MarkovTransition::get_total_weights () const {
  return this->transitions.size();
}

char MarkovTransition::get_weighted_random_next_state () const {
  std::vector<char> ns{};
  std::sample(
    this->transitions.cbegin(), this->transitions.cend(),
    std::back_inserter(ns), 1,
    std::mt19937{std::random_device{}()}
  );
  return ns.front();
}

