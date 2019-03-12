/*******************************************************************************
module:   WordFileReader
author:   digimokan
date:     11 MAR 2019
purpose:  read multiple words from a text file
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordFileReader.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::vector<std::string> WordFileReader::read_all_words (const std::filesystem::path& file_path) const {
  std::ifstream ifile{ file_path};
  std::vector<std::string> words;
  while (ifile) {
    std::string word;
    ifile >> word;
    if (this->is_valid_word(word))
      words.emplace_back(word);
  }
  ifile.close();
  return words;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

bool WordFileReader::is_valid_word (const std::string& word) const {
  auto has_wsp = [] (char ch) { return ((ch == '\n') || (ch == ' ') || (ch == '\t')); };
  return (!word.empty() && std::none_of(word.cbegin(), word.cend(), has_wsp));
}

