/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <fstream>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordFileWriter.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("append three words to new temp file") {

  WordFileWriter wfwriter{};

  SUBCASE("create_temp_word_file()") {
    std::filesystem::path temp_file_path{ wfwriter.create_temp_word_file() };
    CHECK_FALSE(std::filesystem::exists(temp_file_path));
  }

  SUBCASE("append_word(file_path, word)") {
    std::filesystem::path temp_file_path{ wfwriter.create_temp_word_file() };
    CHECK_FALSE(std::filesystem::exists(temp_file_path));
    wfwriter.append_word(temp_file_path, "abc\n");
    wfwriter.append_word(temp_file_path, "mno\n");
    wfwriter.append_word(temp_file_path, "rst\n");
    std::ifstream tf{ temp_file_path };
    std::string inword;
    tf >> inword;
    CHECK_EQ(inword, "abc");
    tf >> inword;
    CHECK_EQ(inword, "mno");
    tf >> inword;
    CHECK_EQ(inword, "rst");
  }

}

