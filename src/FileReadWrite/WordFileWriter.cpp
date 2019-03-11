/*******************************************************************************
module:   WordFileWriter
author:   digimokan
date:     11 MAR 2019
purpose:  create a text word file, append words to it
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordFileWriter.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::filesystem::path WordFileWriter::create_temp_word_file () const {
  std::filesystem::path temp_file{ this->make_temp_file_path() };
  while (std::filesystem::exists(temp_file))
    temp_file = this->make_temp_file_path();
  return temp_file;
}

void WordFileWriter::append_word (const std::filesystem::path& file_path,
    const std::string& word) const {
  std::ofstream ofile{ file_path, std::ios::app | std::ios::ate };
  ofile << word;
  ofile.close();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

std::filesystem::path WordFileWriter::make_temp_file_path () const {
  const std::filesystem::path temp_dir{ std::filesystem::temp_directory_path() };
  static boost::uuids::random_generator uuid_gen;
  return ( temp_dir / std::filesystem::path{boost::uuids::to_string(uuid_gen())} );
}

