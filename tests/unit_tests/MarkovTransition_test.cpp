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

#include "MarkovTransition.hpp"

/*******************************************************************************
* CONSTANTS
*******************************************************************************/

constexpr std::size_t num_rand_samples{ 50 };

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("empty transition") {

  MarkovTransition tr{};

  SUBCASE("get_weight() for missing state") {
    CHECK_EQ(tr.get_weight('z'), 0);
  }

  SUBCASE("get_total_weights()") {
    CHECK_EQ(tr.get_total_weights(), 0);
  }

}

TEST_CASE("transition filled with a, b, c") {

  MarkovTransition tr{};
  tr.add_transition('a');
  tr.add_transition('b');
  tr.add_transition('c');

  SUBCASE("get_weight() for missing state") {
    CHECK_EQ(tr.get_weight('z'), 0);
  }

  SUBCASE("get_weight() for valid states") {
    CHECK_EQ(tr.get_weight('a'), 1);
    CHECK_EQ(tr.get_weight('b'), 1);
    CHECK_EQ(tr.get_weight('c'), 1);
  }

  SUBCASE("get_total_weights()") {
    CHECK_EQ(tr.get_total_weights(), 3);
  }

  SUBCASE("get_weighted_random_next_state()") {
    std::unordered_set<char> rand_states{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(tr.get_weighted_random_next_state());
    CHECK_GT(rand_states.size(), 1);
  }

}

TEST_CASE("transition filled with many repeat states") {

  MarkovTransition tr{};
  tr.add_transition('a');
  tr.add_transition('b');
  tr.add_transition('c');
  tr.add_transition('a');
  tr.add_transition('b');
  tr.add_transition('a');

  SUBCASE("get_weight() for missing state") {
    CHECK_EQ(tr.get_weight('z'), 0);
  }

  SUBCASE("get_weight() for valid states") {
    CHECK_EQ(tr.get_weight('a'), 3);
    CHECK_EQ(tr.get_weight('b'), 2);
    CHECK_EQ(tr.get_weight('c'), 1);
  }

  SUBCASE("get_total_weights()") {
    CHECK_EQ(tr.get_total_weights(), 6);
  }

  SUBCASE("get_weighted_random_next_state()") {
    std::unordered_set<char> rand_states{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(tr.get_weighted_random_next_state());
    CHECK_GT(rand_states.size(), 1);
  }

}

