/*******************************************************************************
module:   MarkovTrainer
author:   digimokan
date:     10 MAR 2019
purpose:  create and train a MarkovWordModel
*******************************************************************************/

#ifndef MARKOV_TRAINER_HPP
#define MARKOV_TRAINER_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class MarkovWordModel;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class MarkovTrainer {

public:

  // constructors
  MarkovTrainer () = delete;
  explicit MarkovTrainer (std::size_t order);

  // destructor
  ~MarkovTrainer () = default;

  // operators
  MarkovTrainer (const MarkovTrainer& in) = default;
  MarkovTrainer& operator= (const MarkovTrainer& rh) = default;
  MarkovTrainer (MarkovTrainer&& in) = default;
  MarkovTrainer& operator= (MarkovTrainer&& rh) = default;

  // specialized methods
  std::shared_ptr<MarkovWordModel> create_model () const;
  void train_model (const std::shared_ptr<MarkovWordModel>& model, const std::vector<std::string>& words) const;
  std::shared_ptr<MarkovWordModel> create_and_train_model (const std::vector<std::string>& words) const;

private:

  // fields
  std::size_t order;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // MARKOV_TRAINER_HPP

