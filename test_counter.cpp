/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			test_counter.cpp
* Author(s):		Peter Bauer
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* Unit tests for counter.
*-----------------------------------------------------------------------------
*/
#include "counter.h"
#include "test_counter.h"

/**
* Tests whether new_counter accepts a directions and returns a valid counter.
* (POS_PRPR_06, POS_PRPR_10, POS_PRPR_11, POS_PRPR_12, POS_PRPR_16)
*/
TEST(test_get_new)
{
  Counter c = new_counter(UP);
  ASSERT_TRUE(c != 0, "c must be a valid counter");
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_02, POS_PRPR_07, POS_PRPR_09, POS_PRPR_10, POS_PRPR_11)
*/
TEST(init) {
  init();
  Counter counters_so_far[COUNTER_COUNT];

  for (int i = 0; i < COUNTER_COUNT; i++) {
    Counter c = new_counter(UNDEFINED);
    ASSERT_TRUE(c != 0, "c must NOT be 0");

    for (int j = 0; j < i; j++)
      ASSERT_TRUE(c != counters_so_far[j], "Current counter must be different to all counters so far");

    counters_so_far[i] = c;
  }

  Counter c = new_counter(DOWN);
  ASSERT_TRUE(c == 0, "c must be 0");
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_10, POS_PRPR_11)
*/
TEST(directions)
{
  init();
  Counter c = new_counter(UNDEFINED);
  ASSERT_EQUALS(UNDEFINED, get_direction(c));

  set_direction(c, UP);
  ASSERT_EQUALS(UP, get_direction(c));

  set_direction(c, DOWN);
  ASSERT_EQUALS(DOWN, get_direction(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_10)
*/
TEST(increment_values)
{
  init();
  Counter c = new_counter(UP);
  ASSERT_EQUALS(1, get_increment_value(c));

  set_increment_value(c, 5);
  ASSERT_EQUALS(5, get_increment_value(c));

  set_increment_value(c, 0);
  ASSERT_EQUALS(0, get_increment_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_02)
*/
TEST(invalid_increment_value)
{
  init();
  Counter c = new_counter(UP);

  set_increment_value(c, 5);
  set_increment_value(c, -1);
  ASSERT_EQUALS(5, get_increment_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_11)
*/
TEST(init_resets_increment_value)
{
  init();
  Counter c = new_counter(DOWN);
  ASSERT_EQUALS(1, get_increment_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_11)
*/
TEST(increment_undefined)
{
  init();
  Counter c = new_counter(UNDEFINED);
  ASSERT_EQUALS(1, get_increment_value(c));
  ASSERT_EQUALS(0, get_value(c));
  increment(c);
  ASSERT_EQUALS(0, get_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_02)
*/
TEST(increment_up)
{
  init();
  Counter c = new_counter(UP);
  ASSERT_EQUALS(0, get_value(c));
  increment(c);
  ASSERT_EQUALS(1, get_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_11)
*/
TEST(init_resets_value)
{
  init();
  Counter c = new_counter(DOWN);
  ASSERT_EQUALS(0, get_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_11)
*/
TEST(set_value_down)
{
  init();
  Counter c = new_counter(DOWN);
  ASSERT_TRUE(set_value(c, 5), "Only DOWN allows set_value");
  ASSERT_EQUALS(5, get_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_02)
*/
TEST(set_value_others)
{
  init();
  Counter c = new_counter(UNDEFINED);
  ASSERT_FALSE(set_value(c, 5), "Only DOWN allows set_value");
  ASSERT_EQUALS(0, get_value(c));

  c = new_counter(UP);
  ASSERT_FALSE(set_value(c, 5), "Only DOWN allows set_value");
  ASSERT_EQUALS(0, get_value(c));
}

/**
* Describe (POS_PRPR_14):
* (POS_PRPR_02)
*/
TEST(increment_down_different_to_1)
{
  init();
  Counter c = new_counter(DOWN);
  ASSERT_EQUALS(1, get_increment_value(c));
  ASSERT_EQUALS(0, get_value(c));

  set_increment_value(c, 3);
  ASSERT_TRUE(set_value(c, 15), "set value expected to be ok");

  for (int i = 15; i >= 0; i -= 3) {
    ASSERT_EQUALS(i, get_value(c));
    increment(c);
  }
}
