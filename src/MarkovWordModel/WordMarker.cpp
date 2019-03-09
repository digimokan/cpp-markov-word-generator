/*******************************************************************************
module:   WordMarker
author:   digimokan
date:     08 MAR 2019
purpose:  prefix/append word with markers for Markov Transitions
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordMarker.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

WordMarker::WordMarker (std::size_t order)
  : order{order},
    marker{'_'}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

bool WordMarker::is_marker (char ch) const {
  return (ch == this->marker);
}

std::string WordMarker::apply_markers (std::string word) const {
  word.insert(word.begin(), this->order, this->marker);
  word.append(1u, this->marker);
  return word;
}

