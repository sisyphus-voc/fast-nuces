// Lab_4_Problem_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int year = 0;
	cout << "Enter year : \n";
	cin >> year;
	year = year % 12;
	switch (year)
	{
	case 4: cout << "rat";
		break;
	case 5: cout << "ox";
		break;
	case 6: cout << "tiger";
		break;
	case 7: cout << "rabbit";
		break;
	case 8: cout << "dragon";
		break;
	case 9: cout << "snake";
		break;
	case 10: cout << "horse";
		break;
	case 11: cout << "goat";
		break;
	case 0: cout << "monkey";
		break;
	case 1: cout << "rooster";
		break;
	case 2: cout << "dog";
		break;
	case 3: cout << "boar";
		break;
	


	}

	return 0;



}

