/*******************************************************************************
module:   WordFileReader
author:   digimokan
date:     11 MAR 2019
purpose:  read multiple words from a text file
*******************************************************************************/

#ifndef WORD_FILE_READER_HPP
#define WORD_FILE_READER_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <filesystem>
#include <string>
#include <vector>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class WordFileReader {

public:

  // constructors
  WordFileReader () = default;

  // destructor
  ~WordFileReader () = default;

  // operators
  WordFileReader (const WordFileReader& in) = default;
  WordFileReader& operator= (const WordFileReader& rh) = default;
  WordFileReader (WordFileReader&& in) = default;
  WordFileReader& operator= (WordFileReader&& rh) = default;

  // specialized methods
  std::vector<std::string> read_all_words (const std::filesystem::path& file_path) const;

private:

  // helper methods
  bool is_valid_word (const std::string& word) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // WORD_FILE_READER_HPP

