/*******************************************************************************
module:   WordBatchGenerator
author:   digimokan
date:     12 MAR 2019
purpose:  generate batch of random words using WordGenerator
*******************************************************************************/

#ifndef WORD_BATCH_GENERATOR_HPP
#define WORD_BATCH_GENERATOR_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordGenerator.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class WordBatchGenerator {

public:

  // constructors
  WordBatchGenerator () = delete;
  WordBatchGenerator (std::size_t order, const std::string& text_file_name, std::size_t min_word_length, std::size_t max_word_length, std::size_t num_words_to_gen);

  // destructor
  ~WordBatchGenerator () = default;

  // operators
  WordBatchGenerator (const WordBatchGenerator& in) = delete;
  WordBatchGenerator& operator= (const WordBatchGenerator& rh) = delete;
  WordBatchGenerator (WordBatchGenerator&& in) = default;
  WordBatchGenerator& operator= (WordBatchGenerator&& rh) = default;

  // specialized methods
  std::vector<std::string> gen_batch ();

private:

  // helper methods
  bool is_valid (const std::string& word) const;

  // fields
  WordGenerator word_gen;
  std::size_t min_word_length;
  std::size_t max_word_length;
  std::size_t num_words_to_gen;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // WORD_BATCH_GENERATOR_HPP

