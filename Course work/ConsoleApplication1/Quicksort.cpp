#include "stdafx.h"
#include "CommonVector.h"
#include "Sorting.h"


void QSort(int ***a, int L, int R, int lol) {//sorting three-dimentional array with quick sort
	int i, j, B, Tmp, Tmp2;
	
		B = arr_of_sums[(L + R) / 2];
		i = L;
		j = R;
		while (i <= j)
		{
			while (arr_of_sums[i] < B)
			{
				i++;
			}
			while (arr_of_sums[j] > B)
			{
				j--;
			}
			if (i <= j)
			{
				Tmp = arr_of_sums[i];
				arr_of_sums[i] = arr_of_sums[j];
				arr_of_sums[j] = Tmp;
				for (int m = 0; m < M; m++) {
					Tmp2 = a[lol][m][i];
					a[lol][m][i] = a[lol][m][j];
					a[lol][m][j] = Tmp2;
				}
				i++;
				j--;
			}
		}
			if (L < j) QSort(a, L, j, lol);
			if (i < R) QSort(a, i, R, lol);
}


clock_t QuickSort(int ***a)//special function for calling quick sort
{
	unsigned int Sum;
	clock_t time_start, time_stop;
	time_start = clock();
	for (int k = 0; k < P; k++)
	{
		for (int m = 0; m < N; m++)
		{
			Sum = 0;
			for (int i = 0; i < M; i++) {

				Sum += a[k][i][m];
			}
			arr_of_sums[m] = Sum;
		}
		QSort(a, 0, N - 1, k);

	}
	time_stop = clock();

	return time_stop - time_start;

}