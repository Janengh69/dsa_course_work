#ifndef MEASURMENTS_H_INCLUDED
#define MEASURMENTS_H_INCLUDED

#include <time.h>
#include "Sorting.h"
#define measurements_number 28

extern clock_t ResOrdered[measurements_number];
extern clock_t ResRandom[measurements_number];
extern clock_t ResBackOrdered[measurements_number];

void MeasurementProcessing(clock_t *Res);
void Shell_Sort_Measurements(int ***a, int *b);//function for time measurement of shell sort 
void Sorting_8_Measurements(int ***a, int *b);// function for time measurement of sorting algorithm of direct selection method #8
void LinealSortingMeasurements(int ***a, int *b);//function for time measurmet of lineal sorting
void QuickSort_Measurements(int ***a);//function for time measurement of quick sort
void Table();
void OutTable();//function for outputting the table


#endif// MEASURMENTS_H_INCLUDED

