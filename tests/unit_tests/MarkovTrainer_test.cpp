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

#include "MarkovTrainer.hpp"
#include "MarkovWordModel.hpp"

/*******************************************************************************
* CONSTANTS
*******************************************************************************/

constexpr std::size_t num_rand_samples{ 1000 };

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("train models with word sets") {

  SUBCASE("create_and_train_model(): order 1") {
    MarkovTrainer trainer{ 1 };
    std::vector<std::string> trng_words{{ "abc", "abd", "ade", "adf", "mno", "rst" }};
    auto model{ trainer.create_and_train_model(trng_words) };
    constexpr std::size_t expected_rand_words{ 9 };
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(model->make_random_word());
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

  SUBCASE("create_and_train_model(): order 2") {
    MarkovTrainer trainer{ 2 };
    std::vector<std::string> trng_words{{ "abc", "abd", "ade", "adf", "mno", "rst" }};
    auto model{ trainer.create_and_train_model(trng_words) };
    constexpr std::size_t expected_rand_words{ 6 };
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(model->make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

  SUBCASE("create_and_train_model(): order 3") {
    MarkovTrainer trainer{ 3 };
    std::vector<std::string> trng_words{{ "abc", "abd", "ade", "adf", "mno", "rst" }};
    auto model{ trainer.create_and_train_model(trng_words) };
    constexpr std::size_t expected_rand_words{ 6 };
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(model->make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

  SUBCASE("create_and_train_model(): order 4") {
    MarkovTrainer trainer{ 4 };
    std::vector<std::string> trng_words{{ "abc", "abd", "ade", "adf", "mno", "rst" }};
    auto model{ trainer.create_and_train_model(trng_words) };
    constexpr std::size_t expected_rand_words{ 6 };
    std::unordered_set<std::string> rand_words{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_words.emplace(model->make_random_word());
    CHECK_EQ(rand_words.size(), expected_rand_words);
    CHECK_EQ(rand_words.count("abc"), 1);
    CHECK_EQ(rand_words.count("abd"), 1);
    CHECK_EQ(rand_words.count("ade"), 1);
    CHECK_EQ(rand_words.count("adf"), 1);
    CHECK_EQ(rand_words.count("mno"), 1);
    CHECK_EQ(rand_words.count("rst"), 1);
  }

}

