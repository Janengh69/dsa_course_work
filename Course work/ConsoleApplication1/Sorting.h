#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include "Measurements.h"

clock_t sorting_3(int ***a, int *b);
clock_t sorting(int ***a, int *b);
void QSort(int ***a, int L, int R, int k);
clock_t QuickSort(int ***a);
clock_t Shell_Sort(int***a, int *b);

#endif


