/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MarkovWordModel.hpp"

/*******************************************************************************
* CONSTANTS
*******************************************************************************/

constexpr std::size_t num_rand_samples{ 1000 };

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("one fixed transition for various orders") {

  SUBCASE("make_random_word(): order 1") {
    MarkovWordModel mwm{ 1 };
    mwm.add_word_transitions("abc");
    CHECK_EQ(mwm.make_random_word(), "abc");
  }

  SUBCASE("make_random_word(): order 2") {
    MarkovWordModel mwm{ 2 };
    mwm.add_word_transitions("abc");
    CHECK_EQ(mwm.make_random_word(), "abc");
  }

  SUBCASE("make_random_word(): order 3") {
    MarkovWordModel mwm{ 3 };
    mwm.add_word_transitions("abc");
    CHECK_EQ(mwm.make_random_word(), "abc");
  }

}

TEST_CASE("multiple possible transitions for various orders") {

  SUBCASE("make_random_word(): order 1") {
    MarkovWordModel mwm{ 1 };
    constexpr std::size_t expected_rand_words{ 9 };
    mwm.add_word_transitions("abc");
    mwm.add_word_transitions("abd");
    mwm.add_word_transitions("ade");
    mwm.add_word_transitions("adf");
    mwm.add_word_transitions("mno");
    mwm.add_word_transitions("rst");
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(mwm.make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
    CHECK_EQ(rand_words.count("ad"), 1);
    CHECK_EQ(rand_words.count("abdf"), 1);
    CHECK_EQ(rand_words.count("abde"), 1);
  }

  SUBCASE("make_random_word(): order 2") {
    MarkovWordModel mwm{ 2 };
    constexpr std::size_t expected_rand_words{ 6 };
    mwm.add_word_transitions("abc");
    mwm.add_word_transitions("abd");
    mwm.add_word_transitions("ade");
    mwm.add_word_transitions("adf");
    mwm.add_word_transitions("mno");
    mwm.add_word_transitions("rst");
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(mwm.make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

  SUBCASE("make_random_word(): order 3") {
    MarkovWordModel mwm{ 3 };
    constexpr std::size_t expected_rand_words{ 6 };
    mwm.add_word_transitions("abc");
    mwm.add_word_transitions("abd");
    mwm.add_word_transitions("ade");
    mwm.add_word_transitions("adf");
    mwm.add_word_transitions("mno");
    mwm.add_word_transitions("rst");
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(mwm.make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

  SUBCASE("make_random_word(): order 4") {
    MarkovWordModel mwm{ 4 };
    constexpr std::size_t expected_rand_words{ 6 };
    mwm.add_word_transitions("abc");
    mwm.add_word_transitions("abd");
    mwm.add_word_transitions("ade");
    mwm.add_word_transitions("adf");
    mwm.add_word_transitions("mno");
    mwm.add_word_transitions("rst");
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(mwm.make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

}

