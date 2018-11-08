#include "stdafx.h"
#include "CommonVector.h"
#include "Sorting.h"
clock_t sorting(int***a, int *b) {//function that sorts three-dimentional array with lineal sorting

	clock_t time_start, time_stop;
	int temp_sum, temp2, count1;
	unsigned int Sum;

	time_start = clock();//starting the clock
	for (int p = 0; p < P; p++)
	{
		for (int h = 0; h < N; h++)
		{
			Sum = 0;
			for (int m = 0; m < M; m++)
			{
				Sum += a[p][m][h];//counting the Sum
			}
			b[h] = Sum;//recording sum in vector
		}
		for (int l = 1; l < N; l++)
		{
			temp_sum = b[l];//recoring template integer from vector Sum in temp_sum
			count1 = 0;
			while (temp_sum > b[count1])
			{
				count1++;
			}//after loop count1 shows the place of insertion temp_sum
			for (int k = l - 1; k >= count1; k--)
			{
				b[k + 1] = b[k];
			}
			b[count1] = temp_sum;
			for (int i = 0; i < M; i++)
			{
				temp2 = a[p][i][l];
				for (int k = l - 1; k >= count1; k--)
				{
					a[p][i][k + 1] = a[p][i][k];
				}
				a[p][i][count1] = temp2;
			}
		}
	}
	time_stop = clock();//stoping the clock
	return time_stop - time_start;
}
