/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			number_sort_timing_test_driver.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
/**
*** @file test_driver.c
*** @brief File with main function built if <code>make test</code> is called
*** @details <code>make test</code> makes an executable by linking the main
*** function of this file. It simply adds all unit tests of this project and
*** then executes these tests.
*/

#include "test_stopwatch.h"
#include "test_sorting_algorithms.h"

int main(int argc, char *argv[])
{
	ADD_TEST(test_stopwatch);
	ADD_TEST(test_stopwatch_advanced);
	ADD_TEST(test_stopwatch_cpu_time);

	ADD_TEST(init_random);
	ADD_TEST(test_bubble_sort);
	ADD_TEST(test_insertion_sort);
	ADD_TEST(compare_bubble_and_insertion);

	run_tests();
}
