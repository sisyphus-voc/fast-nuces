
//********************** Assign date to day ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 6)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Take date from user and calculate day on that date.
// INPUT: date, 2 for month, 2 for year, century and revernads calculation variables.
// OTHER: day in a string
// ALGORITHM : Take input from user.
// if month is greater than or equal 3 subtract 2 from it and if it is 1 or 2 add 2 and assign it to reverand's
// month variable
// calculate year of century and century from year provided.
// compute day of year using reverands formula and output the day.
//

#include <iostream>
using namespace std;
int main()
{
	//decleration of variables.
	int a, b, c, d, m, w, x, y, z, r, year;


	//Taking input from user
	cout << "Enter date : "<< endl;
	cin >> b;
	cout << "Enter number of month : " << endl;
	cin >> m;
	cout << "Enter year :" << endl;
	cin >> year;

	//precaution incase user enters invalid date or month
	if (m > 0 && m < 13 && b >=1 && b <=31)
	{
		//assigning value to month
		if (m >= 3)
			a = m - 2;
		else if (m == 1 || m == 2)
		{
			a = m + 10;
			year = year - 1;
		}

	//calculating century and year of century from the given year.
	d = year / 100;
	c = year % 100;

	//computing day of the year
	w = ((13*a) - 1) / 5;
	x = c / 4;
	y = d / 4;
	z = (w + x + y + b + c) - 2*d;
	
	//In case z<0 visual studio doesn't take positive mod of -ve numbers.
	if (z < 0)
	{
		z = z + 7;
	}

	r = z % 7;

	//Assigning day to integer value
	if (r == 0)
		cout << "It is  Sunday" << endl;
	else if (r == 1)
		cout << "It is Monday" << endl;
	else if (r == 2)
		cout << "It is Tuesday" << endl;
	else if (r == 3)
		cout << "It is Wednesday" << endl;
	else if (r == 4)
		cout << "It is Thursday" << endl;
	else if (r == 5)
		cout << "It  is Friday" << endl;
	else if (r == 6)
		cout << "It is saturday" << endl;
	}

	//If user enter invalid month or date.
	else
		cout << "Invalid date or month" << endl;

	return 0;

}

