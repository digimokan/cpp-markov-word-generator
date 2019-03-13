/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordBatchGenerator.hpp"
#include "WordFileWriter.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("gen_batch(): order 1 model") {

  WordFileWriter wfwriter{};
  std::filesystem::path temp_file_path{ wfwriter.create_temp_word_file() };
  wfwriter.append_word(temp_file_path, "abc\n");
  wfwriter.append_word(temp_file_path, "abd\n");
  wfwriter.append_word(temp_file_path, "ade\n");
  wfwriter.append_word(temp_file_path, "adf\n");
  wfwriter.append_word(temp_file_path, "mno\n");
  wfwriter.append_word(temp_file_path, "rst\n");

  SUBCASE("min_word_length 1, max_word_length 1") {
    WordBatchGenerator word_batch_gen{ 1, temp_file_path, 1, 2, 1 };
    constexpr std::size_t expected_rwords{ 1 };
    auto rwords{ word_batch_gen.gen_batch() };
    CHECK_EQ(rwords.size(), expected_rwords);
    CHECK_UNARY(std::find(rwords.cbegin(), rwords.cend(), "ad") != rwords.cend());
  }

  SUBCASE("min_word_length 3, max_word_length 4") {
    WordBatchGenerator word_batch_gen{ 1, temp_file_path, 3, 4, 2 };
    constexpr std::size_t expected_rwords{ 2 };
    auto rwords{ word_batch_gen.gen_batch() };
    CHECK_EQ(rwords.size(), expected_rwords);
    CHECK_UNARY(std::find(rwords.cbegin(), rwords.cend(), "abdf") != rwords.cend());
    CHECK_UNARY(std::find(rwords.cbegin(), rwords.cend(), "abde") != rwords.cend());
  }

}

