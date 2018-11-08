#include "stdafx.h"
#include "CommonVector.h"
#include <cmath>
#include "Sorting.h"

clock_t Shell_Sort(int***a, int *b) {
	clock_t time_start, time_stop;

	int arr1[N];
	unsigned int Sum, t, count_j, k, temp, temp_sum;

	

	if (N < 4) t = 0;
	else
	{
		t = (log(N) / log(2)) - 1;
	}
	arr1[t] = 0;
	time_start = clock();
	for (int count_i = t - 1; count_i >= 0; count_i--)
	{
		arr1[count_i] = 2 * arr1[count_i + 1] + 1;
	}
	for (int p = 0; p < P; p++)
	{
		for (int h = 0; h < N; h++)
		{
			Sum = 0;
			for (int m = 0; m < M; m++)
			{
				Sum += a[p][m][h];
			}
			b[h] = Sum;
		}
		for (int count_p = 0; count_p < t; count_p++)
		{
			k = arr1[count_p];
			for (int i = k; i < N; i++)
			{
				temp_sum = b[i];
				count_j = i;
				for (int j = 0; j < M; j++)
				{
					temp = a[p][j][i];

					while ((count_j >= k) && (temp_sum < (b[count_j - k])))
					{
						a[p][j][count_j] = a[p][j][count_j - k];
						b[count_j] = b[count_j - k];
						count_j = count_j - k;
					}
					a[p][j][count_j] = temp;

				}
				b[count_j] = temp_sum;
			}
		}
	}
	time_stop = clock();

	return time_stop - time_start;
}
