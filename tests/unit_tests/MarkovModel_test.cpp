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

#include "MarkovModel.hpp"

/*******************************************************************************
* CONSTANTS
*******************************************************************************/

constexpr std::size_t order{ 2 };
constexpr std::size_t num_rand_samples{ 50 };

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("empty model") {

  MarkovModel mm{order};

  SUBCASE("get_total_num_states()") {
    CHECK_EQ(mm.get_total_num_states(), 0);
  }

}

TEST_CASE("model with one state") {

  MarkovModel mm{order};
  mm.add_transition("ab", 'c');
  mm.add_transition("ab", 'd');
  mm.add_transition("ab", 'e');
  mm.add_transition("ab", 'c');
  mm.add_transition("ab", 'd');
  mm.add_transition("ab", 'c');

  SUBCASE("get_total_num_states()") {
    CHECK_EQ(mm.get_total_num_states(), 1);
  }

  SUBCASE("get_weighted_random_next_state(curr_state_chain)") {
    std::unordered_set<char> rand_states{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(mm.get_weighted_random_next_state("ab"));
    CHECK_GT(rand_states.size(), 1);
  }

}

TEST_CASE("model with three states") {

  MarkovModel mm{order};
  mm.add_transition("ab", 'c');
  mm.add_transition("ab", 'd');
  mm.add_transition("ab", 'e');
  mm.add_transition("ab", 'c');
  mm.add_transition("ab", 'd');
  mm.add_transition("ab", 'c');
  mm.add_transition("cm", 'n');
  mm.add_transition("cm", 'o');
  mm.add_transition("cm", 'p');
  mm.add_transition("cm", 'n');
  mm.add_transition("cm", 'o');
  mm.add_transition("cm", 'n');
  mm.add_transition("nr", 's');
  mm.add_transition("nr", 't');
  mm.add_transition("nr", 'u');
  mm.add_transition("nr", 's');
  mm.add_transition("nr", 't');
  mm.add_transition("nr", 's');

  SUBCASE("get_total_num_states()") {
    CHECK_EQ(mm.get_total_num_states(), 3);
  }

  SUBCASE("get_weighted_random_next_state(curr_state_chain)") {
    std::unordered_set<char> rand_states{};
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(mm.get_weighted_random_next_state("ab"));
    CHECK_GT(rand_states.size(), 1);
    rand_states.clear();
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(mm.get_weighted_random_next_state("cm"));
    CHECK_GT(rand_states.size(), 1);
    rand_states.clear();
    for (std::size_t i{0}; i < num_rand_samples; ++i)
      rand_states.emplace(mm.get_weighted_random_next_state("nr"));
    CHECK_GT(rand_states.size(), 1);
  }

}

