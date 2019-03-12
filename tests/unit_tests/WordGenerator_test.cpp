/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordFileWriter.hpp"
#include "WordGenerator.hpp"

/*******************************************************************************
* CONSTANTS
*******************************************************************************/

constexpr std::size_t num_rand_samples{ 1000 };

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("gen correct random words") {

  WordFileWriter wfwriter{};
  std::filesystem::path temp_file_path{ wfwriter.create_temp_word_file() };
  wfwriter.append_word(temp_file_path, "abc\n");
  wfwriter.append_word(temp_file_path, "abd\n");
  wfwriter.append_word(temp_file_path, "ade\n");
  wfwriter.append_word(temp_file_path, "adf\n");
  wfwriter.append_word(temp_file_path, "mno\n");
  wfwriter.append_word(temp_file_path, "rst\n");

  SUBCASE("gen_random_word() for order 1 model") {
    WordGenerator word_gen{ 1, temp_file_path };
    constexpr std::size_t expected_rand_words{ 3 };
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(word_gen.gen_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("ad"), 1);
    CHECK_EQ(rand_words.count("abdf"), 1);
    CHECK_EQ(rand_words.count("abde"), 1);
  }

}

