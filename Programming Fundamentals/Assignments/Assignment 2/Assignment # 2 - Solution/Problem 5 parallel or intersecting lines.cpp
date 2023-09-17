
//********************** Parallel or intersecting lines ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 5)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Take coefficients of equations from user and tell whether the lines are parallel or
// intersecting and if intersecting whether they are perpendicular.
// INPUT: 6 Coeffiecients
// OTHER: slopes of 2 equations.
// ALGORITHM : take input. calculate slope of the given equations. if slopes are equal display lines are parallel
// else display lines are intersecting. If one slope equals negative of other lines are perpendicular.
//


#include <iostream>
using namespace std;
int main()
{
	//declaration of variables
	int A, B, C, D, E, F, m1, m2;

	//taking input from user 
	cout << "Enter 3 coefficients of first equation : ";
	cin >> A >> B >> C;
	cout << "Enter 3 coefficients of second equation : ";
	cin >> D >> E >> F;
	
	//precaution to avoid undefined or 0 slope.
	if (A == 0 || B == 0 || D == 0 || E == 0)
		cout << "Enter valid value of the coeffiecient x and y. (i.e. non-zero)";
	else
	{
		//calculating slope
		m1 = -A / B;
		m2 = -D / E;

		//output if parallel
		if (m1 == m2)
			cout << "The lines are parallel.";
		else
		{
			//output if intersecting
			cout << "The lines intersect.";
			if (m1 * m1 == -1)
				cout << "The lines are perpendicular.";

		}
	}
	return 0;

	

}
