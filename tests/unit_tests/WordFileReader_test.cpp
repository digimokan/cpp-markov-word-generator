/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordFileReader.hpp"
#include "WordFileWriter.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("read all three words from a text file") {

  WordFileWriter wfwriter{};
  WordFileReader wfreader{};

  SUBCASE("append_word(file_path, word)") {
    std::filesystem::path temp_file_path{ wfwriter.create_temp_word_file() };
    CHECK_FALSE(std::filesystem::exists(temp_file_path));
    wfwriter.append_word(temp_file_path, "abc\n");
    wfwriter.append_word(temp_file_path, "mno\n");
    wfwriter.append_word(temp_file_path, "rst\n");
    std::vector<std::string> words{ wfreader.read_all_words(temp_file_path) };
    CHECK_EQ(words.size(), 3);
    CHECK_UNARY(std::find(words.cbegin(), words.cend(), "abc") != words.cend());
    CHECK_UNARY(std::find(words.cbegin(), words.cend(), "mno") != words.cend());
    CHECK_UNARY(std::find(words.cbegin(), words.cend(), "rst") != words.cend());
  }

}

