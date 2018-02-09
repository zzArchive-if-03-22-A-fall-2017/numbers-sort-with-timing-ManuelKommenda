/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			sorting_algorithms.cpp
 * Author(s):		<your name>
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "sorting_algorithms.h"
#include "stopwatch.h"
#include <stdlib.h>

void bubble_sort(int* array, int length){
  bool is_sorted = false;

  int index = length - 1;

  while (is_sorted == false) {
    is_sorted = true;
    for (int i = 0; i < index; i++) {
      if (array[i] > array[i + 1]) {
        int swap = array[i];
        array[i] = array[i + 1];
        array[i + 1] = swap;
        is_sorted = false;
      }
    }
    index--;
  }

}
void insertion_sort(int* array, int length){

  int index = length;
  int j = 0;
  for (int i = 1; i < index; i++) {
    int swap = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > swap) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = swap;
  }

}
int* init_random(int* array, int length){
  for (int i = 0; i < length; i++) {
    array[i] = rand() % length;
  }

  return array;
}
