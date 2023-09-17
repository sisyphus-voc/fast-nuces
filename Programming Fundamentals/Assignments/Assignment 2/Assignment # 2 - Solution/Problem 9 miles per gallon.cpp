
//********************** km/l to m/g ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 9)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: reads in the number of liter of gasoline consumed by the user’s car and the
// number of kilometers traveled by the car, and will then output the
// number of miles per gallon the car delivered.
// INPUT: litre,kilometer, times the user wants to run the calculation
// OUTPUT: miles per gallon
// OTHER:gallon, mile count
// ALGORITHM: take input.convert litres and kms into miles and gallon. calculate miles/gallon.display output.



#include <iostream>
using namespace std;

int main()
{
	//declaring and initializing variables.
	float t, c=0, l, k, g, m, mpg;

	//taking input
	cout << "Enter the number of times you want to run this calculation :";
	cin >> t;

	while (c < t)
	{
		//taking input
		cout << "Enter the gasoline consumed in litres  :";
		cin >> l;
		cout << "Enter distance travelled in kilommeters : ";
		cin >> k;

		//converting litres and kms into gallons and miles
		g = (l * 0.264179);
		m = (k * 1.609);

		//calculating miles per gallon and displaying result
		mpg = m / g;
		cout << "Number of miles per gallon :" << mpg << endl;
		c = c + 1;

	}


	

	
	return 0;



}
