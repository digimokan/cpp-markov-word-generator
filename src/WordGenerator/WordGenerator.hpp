/*******************************************************************************
module:   WordGenerator
author:   digimokan
date:     11 MAR 2019
purpose:  create model, train it, gen words not in training set
*******************************************************************************/

#ifndef WORD_GENERATOR_HPP
#define WORD_GENERATOR_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <string>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovTrainer.hpp"
#include "WordFileReader.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class MarkovWordModel;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class WordGenerator {

public:

  // constructors
  WordGenerator () = delete;
  explicit WordGenerator (std::size_t order, const std::filesystem::path& words_file_path);

  // destructor
  ~WordGenerator () = default;

  // operators
  WordGenerator (const WordGenerator& in) = delete;
  WordGenerator& operator= (const WordGenerator& rh) = delete;
  WordGenerator (WordGenerator&& in) = default;
  WordGenerator& operator= (WordGenerator&& rh) = default;

  // specialized methods
  std::string gen_random_word () const;

private:

  // helper methods
  bool is_training_word (const std::string& word) const;

  // fields
  MarkovTrainer trainer;
  WordFileReader word_file_reader;
  std::unordered_set<std::string> training_words;
  std::shared_ptr<MarkovWordModel> model;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // WORD_GENERATOR_HPP

