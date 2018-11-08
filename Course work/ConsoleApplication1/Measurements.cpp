#include "stdafx.h"
#include "CommonVector.h"
#include "MeasurementArray.h"
#include "Sorting.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

clock_t ResOrdered[measurements_number];
clock_t ResRandom[measurements_number];
clock_t ResBackOrdered[measurements_number];

void MeasurementProcessing(clock_t *Res)
{
	long int Sum, Min1, Min2, Min3, Max1, Max2, Max3;
	int imin1, imin2, imin3, imax1, imax2, imax3;

	Sum = Res[2]; Min1 = Res[2]; Max1 = Res[2]; imin1 = 2; imax1 = 2;
	for (int i = 3; i < measurements_number; i++)
	{
		Sum = Sum + Res[i];
		if (Res[i] > Max1) { Max1 = Res[i]; imax1 = i; }
		else if (Res[i] < Min1) { Min1 = Res[i]; imin1 = i; }
	}
	Res[imin1] = -1; Res[imax1] = -1;

	// Знаходимо другий мінімальний та другий максимальний елементи
	// і виключаємо їх з наступних пошуків, встановивши їм значення -1
	if (Res[2] == -1) { Min2 = Res[3]; imin2 = 3; }
	else { Min2 = Res[2]; imin2 = 2; }
	Max2 = Res[2]; imax2 = 2;
	for (int i = 3; i < measurements_number; i++)
	{
		if (Res[i] > Max2) { Max2 = Res[i]; imax2 = i; }
		else if (Res[i]<Min2 && Res[i] != -1) { Min2 = Res[i]; imin2 = i; }
	}
	Res[imin2] = -1; Res[imax2] = -1;

	// Знаходимо третій мінімальний та третій максимальний елементи
	if (Res[2] == -1)
		if (Res[3] == -1) { Min3 = Res[4]; imin3 = 4; }
		else { Min3 = Res[3]; imin3 = 3; }
	else { Min3 = Res[2]; imin3 = 2; }
	Max3 = Res[2]; imax3 = 2;
	for (int i = 3; i < measurements_number; i++)
	{
		if (Res[i] > Max3) { Max3 = Res[i]; imax3 = i; }
		else if (Res[i]<Min3 && Res[i] != -1) { Min3 = Res[i]; imin3 = i; }
	}

	// Сума всіх вимірів мінус три максимальних та три мінімальних значення буде записана до 0-го елемента масива Res
	Res[0] = Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;

}

void Shell_Sort_Measurements(int ***a, int *b)//function for time measurement of shell sort 
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "Ordered array before sorting :" << endl; 
		FillVector(array_3D, 1);
	//	Output(array_3D);
		ResOrdered[i] = Shell_Sort(array_3D, arr_of_sums);
	//	cout << "\nOrdered array by Shell Sort :" << endl;
	//	Output(array_3D);
		//cout << "\nRandom array before sorting :" << endl;
		FillVector(array_3D, 2);
		//Output(array_3D);
		ResRandom[i] = Shell_Sort(array_3D, arr_of_sums);
		//cout << "\nRandom array be shell Sort :" << endl;
		//Output(array_3D);
		
		FillVector(array_3D, 3);
	//	cout << "\nBackordered before sorting :" << endl;
		//Output(array_3D);
		ResBackOrdered[i] = Shell_Sort(array_3D, arr_of_sums);
		//cout << "\nBackordered array by Shell Sort :" << endl;
		//Output(array_3D);
		
		
	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);


}
void LinealSortingMeasurements(int ***a, int *b)//function for time measurement of lineal sorting
{
	for (int i = 0; i < measurements_number; i++)
	{
		//cout << "Ordered array before sorting :" << endl;
		FillVector(array_3D, 1);
		//Output(array_3D);
		ResOrdered[i] = sorting(array_3D, arr_of_sums);
	//	cout << "\nOrdered array by Lineal Sort :" << endl;
		//Output(array_3D);

		//cout << "\nRandom array before sorting :" << endl;
		FillVector(array_3D, 2);
		//Output(array_3D);
		ResRandom[i] = sorting(array_3D, arr_of_sums);
	//  cout << "\nRandom array by Lineal Sort :" << endl;
	//	Output(array_3D);
		
		FillVector(array_3D, 3);
		//cout << "\nBackordered before sorting :" << endl;
		//Output(array_3D);
		ResBackOrdered[i] = sorting(array_3D, arr_of_sums);
		//cout << "\nBackordered array by Lineal Sort :" << endl;
		//Output(array_3D);
	}
	
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);
}
void QuickSort_Measurements(int ***a)//function for time measurement of quick sort
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "Ordered array before sorting :" << endl;
		FillVector(array_3D, 1);
	//Output(array_3D);
		ResOrdered[i] = QuickSort(array_3D);
	//	cout << "\nOrdered array by Quick Sort :" << endl;
	//	Output(array_3D);

		//cout << "\nRandom array before sorting :" << endl;
		FillVector(array_3D, 2);
	//	Output(array_3D);
		ResRandom[i] = QuickSort(array_3D);
	//	cout << "\nRandom array by Quick Sort :" << endl;
	//		Output(array_3D);

		FillVector(array_3D, 3);
	//	cout << "\nBackordered before sorting :" << endl;
	//	Output(array_3D);
		ResBackOrdered[i] = QuickSort(array_3D);
	//	cout << "\nBackordered array by Quick Sort :" << endl;
	//	Output(array_3D);
	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);
}
void Sorting_8_Measurements(int ***a, int *b)// function for time measurement of sorting algorithm of direct selection #8 method 
{
	for (int i = 0; i < measurements_number; i++)
	{
	//	cout << "Ordered array before sorting :" << endl;
		FillVector(array_3D, 1);
		//Output(array_3D);
		ResOrdered[i] = sorting_3(array_3D, arr_of_sums);
	//	cout << "\nOrdered array by Sorting 8 :" << endl;
	//	Output(array_3D);

	//	cout << "\nRandom array before sorting :" << endl;
		FillVector(array_3D, 2);
	//	Output(array_3D);
		ResRandom[i] = sorting_3(array_3D, arr_of_sums);
	//	cout << "\nRandom array by Sorting 8 :" << endl;
	//	Output(array_3D);

		FillVector(array_3D, 3);
	//	cout << "\nBackordered before sorting :" << endl;
	//	Output(array_3D);
		ResBackOrdered[i] = sorting_3(array_3D, arr_of_sums);
	//	cout << "\nBackordered array by Sorting 8 :" << endl;
	//	Output(array_3D);
	}
	MeasurementProcessing(ResOrdered);
	MeasurementProcessing(ResRandom);
	MeasurementProcessing(ResBackOrdered);

}
void OutTable()
{
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t|\t Ordered |\t Random |\t BackOrdered | \n";
	cout << "\t------------------------------------------------------" << endl;
	printf("\t| %6.1f  \t|%6.1f \t| %10.1f\t     |\n", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	cout << "\t------------------------------------------------------" << endl;
	cout << "\n\n";
}

void Table()
{
	printf("\n\t\t TABLEs WITH MEASUREMENTS: \n");
	printf("\n\t   Measurement table for array array_3D[%d][%d][%d]\n", P, M, N);
	
	printf("\n\t----------------------------------------------------------------\n");
	LinealSortingMeasurements(array_3D, arr_of_sums);
	printf("\t|Lineal Sort\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
	Sorting_8_Measurements(array_3D, arr_of_sums);
	printf("\t|Sorting 8\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
	Shell_Sort_Measurements(array_3D, arr_of_sums);
	printf("\t|Shell Sort\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
	QuickSort_Measurements(array_3D);
	printf("\t|QuickSort\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");

	printf("\n\t   Measurement table for Vector1[%d]\n", N);
	printf("\n\t----------------------------------------------------------------\n");
	LinealSortingMeasurementsVector(Vector1);
	printf("\t|Lineal Sorting\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
	Sorting_8_MeasurementsVector(Vector1);
	printf("\t|Sorting 8 \t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------");
	Shell_Sort_MeasurementsVector(Vector1);
	printf("\t|Shell Sort\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
	QuickSort_MeasurementsVector(Vector1);
	printf("\t|Quick Sort\t  |  %-7.1f\t|  %-7.1f\t|   %-7.1f\t|", (float)ResOrdered[0] / 20, (float)ResRandom[0] / 20, (float)ResBackOrdered[0] / 20);
	printf("\n\t----------------------------------------------------------------\n");
}
