// Lab_4_Problem 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{

	int month, year, calc_year;
	cout << "Enter month: \n";
	cin >> month;
	cout << "Enter year : \n";
	cin >> year;


	year = year % 100;
	if (month == 2 && year == 0 && year % 400 == 0)
		cout << "29 days";
	else if (month == 2 && year != 0 && year % 4 == 0)
		cout << "29 days";
	else
	switch (month)
	{
	case 1: 
	case 3:
	case 5:
	case 7:
	case 9:
	case 11:
		cout << "31 days \n";
		break;
	case 2: cout << "28 days \n";
		break;
	case 4:
	case 6:
	case 8:
	case 10:
	case 12:
		cout << "30 days \n";
		break;

	}

	return 0;
}

