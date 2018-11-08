#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#include "CommonVector.h"
#include "Measurements.h"
#include "MeasurementArray.h"
#include "Sorting.h"

using namespace std;

void CaseVector() {
	char key3;

	key3 = _getch();
	switch (key3)
	{
	case 49:
	{
		system("cls");
		cout << "Array sorted by the method of direct insertion (with linear search of the insertion point):" << endl;
		LinealSortingMeasurementsVector(Vector1);
		OutTable();
		_getch();
		break;

	}
	case 50:
	{
		system("cls");
		cout << "Sorted with Sorting 8: " << endl;
		Sorting_8_MeasurementsVector(Vector1);
		OutTable();
		_getch();
		break;
	}
	case 51:
	{
		system("cls");
		cout << "Sorted with Shell Sort: " << endl;
		Shell_Sort_MeasurementsVector(Vector1);
		OutTable();
		_getch();
		break;

	}
	case 52:
	{
		system("cls");
		cout << "Sorted with QuickSort: " << endl;
		QuickSort_MeasurementsVector(Vector1);
		OutTable();
		_getch();
		break;
	}
	default: break;
	}
	system("PAUSE");
}
void Zastavka() {
	system("cls");
	cout << "\n\n";
	cout << "\t\t\t\t -------------------------------------------------\n";
	cout << "\t\t\t\t|                 COURSE WORK                     |\n";
	cout << "\t\t\t\t|  The study of the effectiveness of different    |\n";
	cout << "\t\t\t\t|  methods for sorting algorithms on multidime-   |\n";
	cout << "\t\t\t\t|              nsional arrays                     |\n";
	cout << "\t\t\t\t|                 Variant #4.                     |\n";
	cout << "\t\t\t\t|             Made by Dorosh Karyna               |\n";
	cout << "\t\t\t\t|                 group KV - 72                   |\n";
	cout << "\t\t\t\t ------------------------------------------------- \n";
	cout << "\n\n\n";
	cout << "\n\t\t\t\tPress Enter to start the program.  \n";
	cout << "\n\t\t\t\tPress any other key to quit the program. \n";
}
void Menu() {//menu of the programm
	system("cls");
	cout << "\n\t\tPlease make a choice: " << endl;
	cout << "\n\tPress 1 to sort simple sort." << endl;
	cout << "\n\tPress 2 to sort 8." << endl;
	cout << "\n\tPress 3 to shell sort." << endl;
	cout << "\n\tPress 4 to quick sort." << endl;
	cout << "\n\tPress 5 to look on the table with measurements for all algorithms." << endl;
	cout << "\n\tPress 6 to work with simple vector." << endl;
	cout << "\n\tPress SPACE if you wanna read the information about the programm." << endl;
	cout << "\n\tIf you want to quit the program, press any other key.\n";
}
void AboutProgramm() {//the information about the programm
	system("cls");
	cout << "\n\n\n\t\t\tAbout the program\n\n";
	cout << "\tWhat the program needs to do is to sort three-dimensional massive with the help of different algorithms.\n\t\n\n";
	cout << "\tEnter Escape to return back to menu";
}
void MenuCases(char key1)
{

	char key2;
	switch (key1)
	{
		case 13://in case Enter
		{
			system("cls");//clearing the screen
			Menu();
			char key2;
			key2 = _getwch();
			switch (key2)
			{
				case 49://in case '1'
				{
					system("cls");
					cout << "Array sorted by the method of direct insertion (with linear search of the insertion point):" << endl;
					LinealSortingMeasurements(array_3D, arr_of_sums);
					OutTable();
					key1 = _getwch();
					break;
				}
				case 50://in case '2'
				{
					system("cls");
					cout << "Sorted with Sorting 8: " << endl;
					Sorting_8_Measurements(array_3D, arr_of_sums);
					OutTable();
					key1 = _getwch();
					break;
				}
				case 51:
				{
					system("cls");
					cout << "Sorted with Shell Sort: " << endl;
					Shell_Sort_Measurements(array_3D, arr_of_sums);
					OutTable();
					key1 = _getwch();
					break;
				}
				case 52:
				{
					system("cls");
					cout << "Sorted with QuickSort: " << endl;
					QuickSort_Measurements(array_3D);
					OutTable();
					key1 = _getwch();
					break;
				}
				case 53: 
				{
					system("cls");
					Table();
					key1 = _getwch();
					break;
				}
				case 32:
				{
					system("cls");
					AboutProgramm();//information about the programm
					key2 = _getwch();
					break;
				}
				case 54:
				{
					system("cls");
					cout << "\n\n\t\t Press 1 if you want to sort vector with Lineal Sorting.\n" << endl;
					cout << "\t\t Press 2 if you want to sort vector with Sorting with selection method # 8.\n" << endl;
					cout << "\t\t Press 3 if you want to sort vector with Shell Sort.\n" << endl;
					cout << "\t\t Press 4 if you want to sort vector with QuickSort.\n" << endl;
					CaseVector();
				}
				default: break;
			}
			break;
		}

	}
}	
