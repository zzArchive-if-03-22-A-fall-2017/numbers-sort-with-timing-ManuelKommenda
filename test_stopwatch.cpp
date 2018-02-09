/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_number_sort_timing.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <math.h>
#include <unistd.h>

#include "stopwatch.h"
#include "test_stopwatch.h"

static void long_taking_function();

TEST(test_stopwatch)
{
	start_stopwatch();
	long_taking_function();
	stop_stopwatch();
	ASSERT_TRUE(elapsed_time() > 0, "Elapsed expected to be greater than 0");
}

#if __x86_64__ || __ppc64__
#define LARGE_PRIME 1125899839733759
#else
#define LARGE_PRIME 1073676287
#endif

static void long_taking_function()
{
	unsigned long i = 2;
	unsigned int last_step = sqrt(LARGE_PRIME);

	while (i <= last_step && LARGE_PRIME % i != 0) {
		i++;
	}
}

TEST(test_stopwatch_advanced)
{
	start_stopwatch();

	long_taking_function();
	double elapsed1 = elapsed_time();
	ASSERT_TRUE(elapsed1 > 0., "Elapsed expected to be greater than 0");

	long_taking_function();
	stop_stopwatch();
	double elapsed2 = elapsed_time();
	ASSERT_TRUE(elapsed1 < elapsed2, "elapsed1 expected to be smaller than elapsed2");

	long_taking_function();
	double elapsed3 = elapsed_time();
	ASSERT_EQUALS(elapsed2, elapsed3);
}

TEST(test_stopwatch_cpu_time)
{
	start_stopwatch();
	sleep(1);
	stop_stopwatch();
	ASSERT_EQUALS(0, elapsed_time());
}
