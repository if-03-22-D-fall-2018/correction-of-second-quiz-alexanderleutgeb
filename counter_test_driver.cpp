/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter_test_driver.cpp
* Author(s):		Peter Bauer
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* Unit tests for counter.
*-----------------------------------------------------------------------------
*/
#include "test_counter.h"

int main(int argc, char* argv[])
{
  ADD_TEST(test_get_new);
  ADD_TEST(init);
  ADD_TEST(directions);
  ADD_TEST(increment_values);
  ADD_TEST(invalid_increment_value);
  ADD_TEST(init_resets_increment_value);
  ADD_TEST(increment_undefined);
  ADD_TEST(increment_up);
  ADD_TEST(init_resets_value);
  ADD_TEST(set_value_down);
  ADD_TEST(set_value_others);
  ADD_TEST(increment_down_different_to_1);

  run_tests();
  return 0;
}
