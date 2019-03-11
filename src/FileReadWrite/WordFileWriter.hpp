/*******************************************************************************
module:   WordFileWriter
author:   digimokan
date:     11 MAR 2019
purpose:  create a text word file, append words to it
*******************************************************************************/

#ifndef WORD_FILE_WRITER_HPP
#define WORD_FILE_WRITER_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <filesystem>
#include <string>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class WordFileWriter {

public:

  // constructors
  WordFileWriter () = default;

  // destructor
  ~WordFileWriter () = default;

  // operators
  WordFileWriter (const WordFileWriter& in) = default;
  WordFileWriter& operator= (const WordFileWriter& rh) = default;
  WordFileWriter (WordFileWriter&& in) = default;
  WordFileWriter& operator= (WordFileWriter&& rh) = default;

  // specialized methods
  std::filesystem::path create_temp_word_file () const;
  void append_word (const std::filesystem::path& file_path, const std::string& word) const;

private:

  // helper methods
  std::filesystem::path make_temp_file_path () const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // WORD_FILE_WRITER_HPP

