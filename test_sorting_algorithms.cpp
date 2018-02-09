/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_sorting_algorithms.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <string.h>

#include "stopwatch.h"
#include "sorting_algorithms.h"
#include "test_sorting_algorithms.h"

#define SMALL 1024

TEST(init_random)
{
	int small_array[SMALL];
	init_random(small_array, SMALL);

	int equal_successor_count = 0;

	for (int i = 1; i < SMALL; i++) {
		if (small_array[i - 1] == small_array[i])
			equal_successor_count++;
	}

	ASSERT_TRUE(equal_successor_count <  SMALL/10, "Expected to have fewer than 10 \% numbers equal in a row");
}

TEST(test_bubble_sort)
{
	int small_array[SMALL];

	init_random(small_array, SMALL);
	bubble_sort(small_array, SMALL);
	for (int i = 0; i < SMALL - 1; i++)
		ASSERT_TRUE(small_array[i] <= small_array[i + 1], "Values expected to be sorted");
}

TEST(test_insertion_sort)
{
	int small_array[SMALL];

	init_random(small_array, SMALL);
	insertion_sort(small_array, SMALL);
	for (int i = 0; i < SMALL - 1; i++)
		ASSERT_TRUE(small_array[i] <= small_array[i + 1], "Values expected to be sorted");
}

TEST(compare_bubble_and_insertion)
{
	int small_array1[SMALL];
	int small_array2[SMALL];

	init_random(small_array1, SMALL);
	memcpy(small_array2, small_array1, sizeof(int) * SMALL);

	start_stopwatch();
	bubble_sort(small_array1, SMALL);
	float elapsed = elapsed_time();

	insertion_sort(small_array2, SMALL);
	stop_stopwatch();
	ASSERT_TRUE(elapsed >= elapsed_time() - elapsed, "2nd sort expected to be at least as fast as 1st");
}
