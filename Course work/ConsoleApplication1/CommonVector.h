#ifndef __CommonVector_H__
#define __CommonVector_H__

#define N 2000//defines sizes of array
#define P 1
#define M 100

extern int ***array_3D;
extern int *arr_of_sums;
extern int *Vector1;

void Multi_Dimentional_Dynamic_Array();
void Vector();

void FillVector(int ***a, int b);
void Output(int ***a);
void FreeMemory();

#endif
