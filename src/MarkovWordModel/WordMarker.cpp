/*******************************************************************************
module:   WordMarker
author:   digimokan
date:     08 MAR 2019
purpose:  prefix/append word with markers for Markov Transitions
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

#include "WordMarker.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

WordMarker::WordMarker (std::size_t order)
  : order{order},
    marker{'_'} {
  assert(this->order > 0);
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

bool WordMarker::is_marker (char ch) const {
  return (ch == this->marker);
}

std::string WordMarker::get_prefix () const {
  return this->make_prefix();
}

std::string WordMarker::apply_markers (const std::string& word) const {
  return (this->make_prefix() + word + this->marker);
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

std::string WordMarker::make_prefix () const {
  return std::string(this->order, this->marker);
}

