#include "stdafx.h"
#include <cmath>
#include <ctime> 
#include "SortingVector.h"
#include "CommonVector.h"

clock_t LinealSortingArray(int *a)
{ 
	clock_t time_start, time_stop;
	int temp, j;
	time_start = clock();
	for (int i = 1; i < N; i++) 
	{
		temp = a[i];
		j = 0;
		while (temp > a[j]) 
		{
			j++;
		}
		for (int k = i - 1; k >= j; k--) 
		{
			a[k + 1] = a[k];
		}
		a[j] = temp;
	}
	time_stop = clock();
	return time_stop - time_start;
}

clock_t ShellSortingArray(int *arr)
{
	clock_t time_start, time_stop;
	int const max_t = (N - 1) / 4 + 1;
	int arr1[max_t];
	int temp;
	int j, k, t;
	if (N < 4) t = 0;
	else 
	{
		t = (log(N) / log(2)) - 1;
	}
	arr1[t] = 0;
	time_start = clock();
	for (int i = t - 1; i >= 0; i--)
	{
		arr1[i] = 2 * arr1[i + 1] + 1;
	}
	for (int p = 0; p <= t; p++) 
	{
		k = arr1[p];
		for (int i = k; i < N; i++) 
		{
			temp = arr[i];
			j = i;
			while ((j >= k) && (temp < (arr[j - k]))) {
				arr[j] = arr[j - k];
				j = j - k;
			}
			arr[j] = temp;
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}
void QuickSortArray(int *vectA, int L, int R)
{
	int B, x;
	int i, j;
	i = L;
	j = R;
	x = vectA[(L + R) / 2];
	while (i <= j)
	{
		while (vectA[i] < x)
			i++;
		while (vectA[j] > x)
			j--;
		if (i <= j)
		{
			B = vectA[i];
			vectA[i] = vectA[j];
			vectA[j] = B;
			i++;
			j--;
		}
	}
	if (L < j) QuickSortArray(vectA, L, j);
	if (i < R) QuickSortArray(vectA, i, R);
}

clock_t QuickSortArray2(int *a)//special function for calling quick sort
{
	clock_t time_start, time_stop;
	time_start = clock();
		QuickSortArray(a, 0, N - 1);
	time_stop = clock();

	return time_stop - time_start;

}
		
clock_t Sorting8Array(int *A)
{
	clock_t time_start, time_stop;
	int L, R, imin, imax, B;
	L = 0;
	R = N - 1;
	time_start = clock();
	while (L < R)
	{
		imin = L;
		imax = L;
		for (int i = L + 1; i <= R; ++i)
		{
			if (A[i] < A[imin])
			{
				imin = i;
			}
			else if (A[i] > A[imax])
			{
				imax = i;
			}
		}
		if (imin != L)
		{
			B = A[imin];
			A[imin] = A[L];
			A[L] = B;
		}
		if (imax != R)
		{
			if (imax == L)
			{
				B = A[imin];
				A[imin] = A[R];
				A[R] = B;
			}
			else
			{
				B = A[imax];
				A[imax] = A[R];
				A[R] = B;
			}
		}
		L++;
		R--;
	}
	time_stop = clock();
	return time_stop - time_start;
}	

