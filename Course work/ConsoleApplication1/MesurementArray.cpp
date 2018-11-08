#include "stdafx.h"
#include "MeasurementArray.h"
#include "Measurements.h"
#include "SortingArray.h"

using namespace std;

clock_t ResOrderedVector[measurements_number];
clock_t ResRandomVector[measurements_number];
clock_t ResBackOrderedVector[measurements_number];

void FillArray(int * a, int b)
{
	switch (b)
	{
	case 1:
	{	
		for (int i = 0; i < N; i++)
		{
			a[i] = i;
		}
		break;
	}
	case 2:
	{
		for (int j = 0; j < N; j++)
		{
			a[j] = rand() % N;//random array
		}
		break;
	}
	case 3:
	{
		for (int j = 0; j < N; j++)
		{
			a[j] = N - j;//ordered by decreasing array
		}
	}
	default:
		break;
	}

}
void OutputArray(int *a)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
}
void Shell_Sort_MeasurementsVector(int *a)//function for time measurement of shell sort 
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "\n\nOrdered array before sorting :" << endl;
		FillArray(Vector1, 1);
		//OutputArray(Vector1);

		//cout << "\n\nOrdered array by Shell Sort :" << endl;
		ResOrdered[i] = ShellSortingArray(Vector1);
	//	OutputArray(Vector1);

	//	cout << "\n\nRandom array before sorting :" << endl;
		FillArray(Vector1, 2);
		//OutputArray(Vector1);

		//cout << "\n\nRandom array by Shell Sort :" << endl;
		ResRandom[i] = ShellSortingArray(Vector1);
		//OutputArray(Vector1);

	//	cout << "\n\nBackordered before sorting :" << endl;
		FillArray(Vector1, 3);
	//	OutputArray(Vector1);
		
	//	cout << "\n\nBackordered array by Shell Sort :" << endl;
		ResBackOrdered[i] = ShellSortingArray(Vector1);
	//	OutputArray(Vector1);

	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);
	cout << "\n";
	
}

void LinealSortingMeasurementsVector(int *a)//function for time measurement of lineal sorting
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "\n\nOrdered array before sorting :" << endl;
		FillArray(Vector1, 1);
	//	OutputArray(Vector1);

	//	cout << "\n\nOrdered array by Lineal Sort :" << endl;
		ResOrdered[i] = LinealSortingArray(Vector1);
		//OutputArray(Vector1);

		FillArray(Vector1, 2);
	//	cout << "\n\nRandom array before sorting :" << endl;
		//OutputArray(Vector1);

		ResRandom[i] = LinealSortingArray(Vector1);
		//cout << "\n\nRandom array by Lineal Sort :" << endl;
		//OutputArray(Vector1);
		
		FillArray(Vector1, 3);
		//cout << "\n\nBackordered before sorting :" << endl; 
		//OutputArray(Vector1);

		ResBackOrdered[i] = LinealSortingArray(Vector1);
		//cout << "\n\nBackordered array by Lineal Sort :" << endl;
		//OutputArray(Vector1);
	}

	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);

}
void QuickSort_MeasurementsVector(int *a)//function for time measurement of quick sort
{
	for (int i = 0; i < measurements_number; i++)
	{
		//cout << "\n\nOrdered array before sorting :" << endl;
		FillArray(Vector1, 1);
		//OutputArray(Vector1);
		ResOrdered[i] = QuickSortArray2(Vector1);
	//	cout << "\n\nOrdered array by Quick Sort :" << endl;
	//	OutputArray(Vector1);
		FillArray(Vector1, 2);
	//	cout << "\n\nRandom array before sorting :" << endl;
	//	OutputArray(Vector1);
		ResRandom[i] = QuickSortArray2(Vector1);
	//	cout << "\n\nRandom array by Quick Sort :" << endl;
	//	OutputArray(Vector1);
		FillArray(Vector1, 3);
	//	cout << "\n\nBackordered before sorting :" << endl;
	//	OutputArray(Vector1);
		ResBackOrdered[i] = QuickSortArray2(Vector1);
	//	cout << "\nBackordered array by Quick Sort :" << endl;
	//	OutputArray(Vector1);
	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);

}
void Sorting_8_MeasurementsVector(int *a)// function for time measurement of sorting algorithm of direct selection #8 method 
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "\n\nOrdered array before sorting :" << endl;
		FillArray(Vector1, 1);
		//OutputArray(Vector1);
		ResOrdered[i] = Sorting8Array(Vector1);
		//cout << "\n\nOrdered array by Sorting 8 :" << endl;
		//OutputArray(Vector1);
		FillArray(Vector1, 2);
		//cout << "\n\nRandom array before sorting :" << endl;
	//	OutputArray(Vector1);
		ResRandom[i] = Sorting8Array(Vector1);
	//	cout << "\n\nRandom array by Sorting 8 :" << endl;
		//OutputArray(Vector1);
		FillArray(Vector1, 3);
	//	cout << "\n\nBackordered before sorting :" << endl;
	//	OutputArray(Vector1);
		ResBackOrdered[i] = Sorting8Array(Vector1);
	//	cout << "\n\nBackordered array by Sorting 8 :" << endl;
		//OutputArray(Vector1);
	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);

}