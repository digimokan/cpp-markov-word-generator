/*******************************************************************************
module:   WordMarker
author:   digimokan
date:     08 MAR 2019
purpose:  prefix/append word with markers for Markov Transitions
*******************************************************************************/

#ifndef WORD_MARKER_HPP
#define WORD_MARKER_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class WordMarker {

public:

  // constructors
  WordMarker () = delete;
  explicit WordMarker (std::size_t order);

  // destructor
  ~WordMarker () = default;

  // operators
  WordMarker (const WordMarker& in) = default;
  WordMarker& operator= (const WordMarker& rh) = default;
  WordMarker (WordMarker&& in) = default;
  WordMarker& operator= (WordMarker&& rh) = default;

  // specialized methods
  bool is_marker (char ch) const;
  std::string apply_markers (std::string word) const;

private:

  // fields
  std::size_t order;
  char marker;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // WORD_MARKER_HPP

