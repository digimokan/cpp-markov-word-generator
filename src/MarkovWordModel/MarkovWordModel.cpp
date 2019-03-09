/*******************************************************************************
module:   MarkovWordModel
author:   digimokan
date:     08 MAR 2019
purpose:  nth-order Markov Model of words
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <cstddef>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovModel.hpp"
#include "MarkovWordModel.hpp"
#include "WordMarker.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

MarkovWordModel::MarkovWordModel (std::size_t order)
  : order{order},
    model{order},
    word_marker{order} {
  assert(this->order > 0);
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void MarkovWordModel::add_word_transitions (const std::string& word) {
  assert(! word.empty());
  const std::string mw{ this->word_marker.apply_markers(word) };
  for (auto it{mw.begin()}; it != (mw.end() - this->order); ++it) {
    const std::string state_chain{ std::string{it, it + this->order} };
    const char next_state{ *(it + this->order) };
    this->model.add_transition(state_chain, next_state);
  }
}

std::string MarkovWordModel::make_random_word () const {
  assert(this->model.get_total_num_states() > 0);
  const std::string prefix{ this->word_marker.get_prefix() };
  std::string rword{ prefix };
  char next_state{ this->model.get_weighted_random_next_state(rword) };
  while (! this->word_marker.is_marker(next_state)) {
    rword += next_state;
    const std::string curr_state_chain{ std::string{rword.cend() - this->order, rword.cend()} };
    next_state = this->model.get_weighted_random_next_state(curr_state_chain);
  }
  return std::string{ rword.cbegin() + prefix.size(), rword.cend() };
}

