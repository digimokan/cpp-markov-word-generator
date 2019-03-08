/*******************************************************************************
module:   MarkovTransition
author:   digimokan
date:     07 MAR 2019
purpose:  store a weighted transition for a given markov state
*******************************************************************************/

#ifndef MARKOV_TRANSITION_HPP
#define MARKOV_TRANSITION_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <unordered_set>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MarkovTransition {

public:

  // constructors
  MarkovTransition () = default;

  // destructor
  ~MarkovTransition () = default;

  // operators
  MarkovTransition (const MarkovTransition& in) = default;
  MarkovTransition& operator= (const MarkovTransition& rh) = default;
  MarkovTransition (MarkovTransition&& in) = default;
  MarkovTransition& operator= (MarkovTransition&& rh) = default;

  // specialized methods
  void add_transition (char next_state);
  std::size_t get_weight (char next_state) const;
  std::size_t get_total_weights () const;
  char get_weighted_random_next_state () const;

private:

  // fields
  std::unordered_multiset<char> transitions;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MARKOV_TRANSITION_HPP

