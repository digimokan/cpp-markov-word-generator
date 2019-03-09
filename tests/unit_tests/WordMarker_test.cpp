/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "WordMarker.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("first order WordMarker") {

  WordMarker wm{ 1 };

  SUBCASE("is_marker(char)") {
    CHECK_UNARY(wm.is_marker('_'));
    CHECK_FALSE(wm.is_marker('a'));
  }

  SUBCASE("get_prefix()") {
    CHECK_EQ(wm.get_prefix(), "_");
  }

  SUBCASE("single char word") {
    std::string scword{ "a" };
    CHECK_EQ(wm.apply_markers(scword), "_a_");
    CHECK_EQ(scword, "a");
  }

  SUBCASE("three char word") {
    std::string tcword{ "abc" };
    CHECK_EQ(wm.apply_markers(tcword), "_abc_");
    CHECK_EQ(tcword, "abc");
  }

}

TEST_CASE("third order WordMarker") {

  WordMarker wm{ 3 };

  SUBCASE("is_marker(char)") {
    CHECK_UNARY(wm.is_marker('_'));
    CHECK_FALSE(wm.is_marker('a'));
  }

  SUBCASE("get_prefix()") {
    CHECK_EQ(wm.get_prefix(), "___");
  }

  SUBCASE("single char word") {
    std::string scword{ "a" };
    CHECK_EQ(wm.apply_markers(scword), "___a_");
    CHECK_EQ(scword, "a");
  }

  SUBCASE("three char word") {
    std::string tcword{ "abc" };
    CHECK_EQ(wm.apply_markers(tcword), "___abc_");
    CHECK_EQ(tcword, "abc");
  }

}

