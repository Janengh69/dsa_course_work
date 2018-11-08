#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CommonVector.h"

using namespace std;


int ***array_3D;
int *arr_of_sums;
int *Vector1;


void FillVector(int ***a, int b)//filling the array
{
	switch (b)
	{
	case 1:
	{
		for (int p = 0; p < P; p++)
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					a[p][i][j] = (i + j + p) * (j + 1);//ordered by increasing array
				}
			}
		}
		break;
	}
	case 2:
	{
		for (int p = 0; p < P; p++)
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					a[p][i][j] = rand() % (1000);//random array
				}
			}
		}
		break;
	}
	case 3:
	{
		for (int p = 0; p < P; p++)
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					a[p][i][j] = (P + M + N) - (i + j + p);//ordered by decreasing array
				}
			}
		}
	}
	default:
		break;
	}
}

void Output(int ***a)//outputting three-dimentional array
{
	for (int p = 0; p < P; p++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << a[p][i][j] << "\t";
			}
			cout << endl;
		} cout << endl;
	}
}
void FreeMemory()//free memory after using our arrays
{
	for (int k = 0; k < P; k++)
	{
		for (int i = 0; i < M; i++)
			free(array_3D[k][i]);
		free(array_3D[k]);
	}
	free(array_3D);
	free(arr_of_sums);
	free(Vector1);
}


void Multi_Dimentional_Dynamic_Array()//creating dynamic three-dimentional array
{
	array_3D = (int***)malloc(P * sizeof(int**));
	for (int k = 0; k < P; k++)
	{
		array_3D[k] = (int**)malloc(M * sizeof(int*));
		for (int i = 0; i < M; i++)
			array_3D[k][i] = (int*)malloc(N * sizeof(int));
	}
}
void Vector()//creating dynamic vector for sums
{
	arr_of_sums = (int*)malloc(N * sizeof(int*));
	Vector1 = (int*)malloc(N * sizeof(int*));
}
