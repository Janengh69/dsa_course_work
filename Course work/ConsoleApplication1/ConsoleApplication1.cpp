#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "CommonVector.h"
#include "MENU.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Multi_Dimentional_Dynamic_Array();//function that allocates memory for multidimensional array
	Vector();//allocates memory for vector of sums and Vector1
	char key1;
	do
	{
		Zastavka();
		key1 = _getwch();//reading what user have pressed
		MenuCases(key1);
	//	key1 = 32;

	} while (key1 == 13);//while user presses enter it will return on the main screen of     the programm
	FreeMemory();//free memory that was used for dynamic arrays
//	system("pause");
	return 0;
}
