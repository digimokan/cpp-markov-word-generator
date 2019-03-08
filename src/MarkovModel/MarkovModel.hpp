/*******************************************************************************
module:   MarkovModel
author:   digimokan
date:     08 MAR 2019
purpose:  an nth-order Markov Model for transitions between chars
*******************************************************************************/

#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>
#include <unordered_map>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovTransition.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MarkovModel {

public:

  // constructors
  MarkovModel () = delete;
  explicit MarkovModel (std::size_t order);

  // destructor
  ~MarkovModel () = default;

  // operators
  MarkovModel (const MarkovModel& in) = default;
  MarkovModel& operator= (const MarkovModel& rh) = default;
  MarkovModel (MarkovModel&& in) = default;
  MarkovModel& operator= (MarkovModel&& rh) = default;

  // specialized methods
  void add_transition (const std::string& curr_state_chain, char next_state);
  char get_weighted_random_next_state (const std::string& curr_state_chain) const;
  std::size_t get_total_num_states () const;

private:

  // fields
  std::size_t order;
  std::unordered_map<std::string, MarkovTransition> model;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MARKOV_MODEL_HPP

