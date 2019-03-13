/*******************************************************************************
module:   WordBatchGenerator
author:   digimokan
date:     12 MAR 2019
purpose:  generate batch of random words using WordGenerator
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordBatchGenerator.hpp"
#include "WordGenerator.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

WordBatchGenerator::WordBatchGenerator (std::size_t order,
      const std::string& text_file_name, std::size_t min_word_length,
      std::size_t max_word_length, std::size_t num_words_to_gen)
  : word_gen{order, text_file_name},
    min_word_length{min_word_length},
    max_word_length{max_word_length},
    num_words_to_gen{num_words_to_gen}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::vector<std::string> WordBatchGenerator::gen_batch () {
  std::vector<std::string> rwords;
  while (rwords.size() < this->num_words_to_gen) {
    std::string rword{ this->word_gen.gen_random_word() };
    if (this->is_valid(rword) && (std::find(rwords.cbegin(), rwords.cend(), rword) == rwords.cend()))
      rwords.emplace_back(rword);
  }
  return rwords;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

bool WordBatchGenerator::is_valid (const std::string& word) const {
  return (
    (word.size() >= this->min_word_length) &&
    (word.size() <= this->max_word_length)
  );
}

