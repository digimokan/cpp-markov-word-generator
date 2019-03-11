/*******************************************************************************
module:   MarkovTrainer
author:   digimokan
date:     10 MAR 2019
purpose:  create and train a MarkovWordModel
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovTrainer.hpp"
#include "MarkovWordModel.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

MarkovTrainer::MarkovTrainer (std::size_t order)
  : order{order}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::shared_ptr<MarkovWordModel> MarkovTrainer::create_model () const {
  return std::make_shared<MarkovWordModel>(this->order);
}

void MarkovTrainer::train_model (const std::shared_ptr<MarkovWordModel>& model, const std::vector<std::string>& words) const {
  for (const auto& word : words)
    model->add_word_transitions(word);
}

std::shared_ptr<MarkovWordModel> MarkovTrainer::create_and_train_model (const std::vector<std::string>& words) const {
  auto model{ this->create_model() };
  this->train_model(model, words);
  return model;
}

