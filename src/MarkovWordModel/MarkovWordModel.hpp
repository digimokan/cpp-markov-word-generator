/*******************************************************************************
module:   MarkovWordModel
author:   digimokan
date:     08 MAR 2019
purpose:  nth-order Markov Model of words
*******************************************************************************/

#ifndef MARKOV_WORD_MODEL_HPP
#define MARKOV_WORD_MODEL_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovModel.hpp"
#include "WordMarker.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MarkovWordModel {

public:

  // constructors
  MarkovWordModel () = delete;
  explicit MarkovWordModel (std::size_t order);

  // destructor
  ~MarkovWordModel () = default;

  // operators
  MarkovWordModel (const MarkovWordModel& in) = default;
  MarkovWordModel& operator= (const MarkovWordModel& rh) = default;
  MarkovWordModel (MarkovWordModel&& in) = default;
  MarkovWordModel& operator= (MarkovWordModel&& rh) = default;

  // specialized methods
  void add_word_transitions (const std::string& word);
  std::string make_random_word () const;

private:

  // fields
  std::size_t order;
  MarkovModel model;
  WordMarker word_marker;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MARKOV_WORD_MODEL_HPP

