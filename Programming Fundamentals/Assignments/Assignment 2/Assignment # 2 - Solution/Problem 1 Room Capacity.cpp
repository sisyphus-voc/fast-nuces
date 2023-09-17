//********************** Room Capacity ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 1)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Identifies whether the meetning is legal or not 
// INPUT: Maximum capacity and number of people attending the meeting
// OUTPUT: Legality of meeting and how many more people can attend or should be excluded 
// ALGORITHM: Take maximum capacity of the meeting and number of people attending the meeting from the user.
// If people attending the meeting is less than or equal to the maximum capacity display the meeting is legal and how may more people can attend 
// else people attending the meeting is greater than the maximum capacity desplay the meeting is illegal and the number of people that should be 
// excluded to make it legal.


#include <iostream>
using namespace std;

int main()
{
	//declaration of variables
	int m=0, n=0;
	
	//taking input from user
	cout << "Enter Maximum room capacity : ";
	cin >> m;
	cout << "Enter number of people : ";
	cin >> n;
	
	

	if (n <= m)
	{
		//computing more people that can attend when meeting is legal.
		
		m = m - n;

		//displaying output when meeting is legal

		cout << "The meeting is legal \n";
		cout << "More people that can attend :" << m << endl;

	}

	else
	{
		//computing number of people that should be excluded to make the meeting legal.

		m = n - m;

		//displaying output when meeting is illegal

		cout << "The meeting is illegal. \n";
		cout << "Number of people that should be excluded :" << m << endl;


	}

    return 0;

}

