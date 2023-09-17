
//********************** Square of numbers ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 8)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: outputs the squares of consecutive positive integers until the 
// difference between a square and the preceding one is greater than 50
// INPUT: 
// OUTPUT: square of integers.
// ALGORITHM :
#include <iostream>
using namespace std;

int main()
{
	//delaring variables
	int n=1;
	//while difference between a square of a number and square of the preceding one is less than 50.
	while ((n*n-((n-1)*(n-1))) <=50)
	{
		//calculating square and displaying output
		cout << n*n << endl;
		n++;
	}
	return 0;


	
}
