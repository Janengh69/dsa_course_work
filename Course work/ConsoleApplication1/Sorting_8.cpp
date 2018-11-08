#include "stdafx.h"
#include "CommonVector.h"
#include "Sorting.h"
#include "Measurements.h"


clock_t sorting_3(int ***a, int *b) {//function with sorting algorithm of direct selection method #8
	clock_t time_start, time_stop;

	int L, R, imin, imax, B, B2;
	 int Sum;
	time_start = clock();
	for (int p = 0; p < P; p++)
	{
		L = 0;
		R = N - 1;
		for (int j = 0; j < N; j++)
		{
			Sum = 0;
			for (int i = 0; i < M; i++)
			{

				Sum += a[p][i][j];
			}
			b[j] = Sum;
		}
		while (L < R)
		{
			imin = L;
			imax = L;
			for (int i = L + 1; i <= R; ++i)
			{
				if (b[i] < b[imin])
				{
					imin = i;
				}
				else if (b[i] > b[imax])
				{
					imax = i;
				}
			}
			if (imin != L)
			{
				B = b[imin];
				b[imin] = b[L];
				b[L] = B;
				for (int j = 0; j < M; j++)
				{
					B2 = a[p][j][imin];
					a[p][j][imin] = a[p][j][L];
					a[p][j][L] = B2;
				}
			}
			if (imax != R)
			{
				if (imax == L)
				{
					B = b[imin];
					b[imin] = b[R];
					b[R] = B;
					for (int j = 0; j < M; j++)
					{
						B2 = a[p][j][imin];
						a[p][j][imin] = a[p][j][R];
						a[p][j][R] = B2;
					}
				}
				else
				{
					B = b[imax];
					b[imax] = b[R];
					b[R] = B;
					for (int j = 0; j < M; j++)
					{
						B2 = a[p][j][imax];
						a[p][j][imax] = a[p][j][R];
						a[p][j][R] = B2;
					}
				}
			}
			L++;
			R--;
		}
	}
	time_stop = clock();

	return time_stop - time_start;

}
