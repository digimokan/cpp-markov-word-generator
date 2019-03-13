/*******************************************************************************
module:   main
author:   digimokan
date:     02 FEB 2018 (created)
purpose:  run Markov Word Generator Program
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "ProgramOpts.hpp"
#include "WordBatchGenerator.hpp"

/*******************************************************************************
* MAIN
*******************************************************************************/

int main (int argc, char* argv[]) {
  ProgramOpts progopts{ argc, argv };
  auto word_generator{ progopts.create_word_generator() };
  std::vector<std::string> rwords{ word_generator->gen_batch() };
  std::for_each(rwords.cbegin(), rwords.cend(), [] (auto word) { std::cout << word << '\n'; });
  return (0);
}

