/*******************************************************************************
module:   WordGenerator
author:   digimokan
date:     11 MAR 2019
purpose:  create model, train it, gen words not in training set
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <filesystem>
#include <functional>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovTrainer.hpp"
#include "MarkovWordModel.hpp"
#include "WordFileReader.hpp"
#include "WordGenerator.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

WordGenerator::WordGenerator (std::size_t order, const std::filesystem::path& words_file_path)
    : trainer{order} {
  assert(std::filesystem::exists(words_file_path));
  std::vector<std::string> words{ this->word_file_reader.read_all_words(words_file_path) };
  this->model = this->trainer.create_and_train_model(words);
  std::copy(words.cbegin(), words.cend(), std::inserter(this->training_words, this->training_words.end()));
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::string WordGenerator::gen_random_word () const {
  std::string rword{ this->model->make_random_word() };
  while (this->is_training_word(rword))
    rword = this->model->make_random_word();
  return rword;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

bool WordGenerator::is_training_word (const std::string& word) const {
  auto weq = [&word] (auto tword) { return tword == word; };
  return std::any_of(this->training_words.cbegin(), this->training_words.cend(), weq);
}

