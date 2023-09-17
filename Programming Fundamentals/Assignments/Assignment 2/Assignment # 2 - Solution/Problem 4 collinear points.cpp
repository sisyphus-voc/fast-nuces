//********************** Collinear points ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 4)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Takes three points and checks if they are collinear.
// INPUT: 3 x and 3 y coordinates
// OUTPUT:Whether points are collinear or not.
// ALGORITHM : Take input 3 points from user as x and y coordinates.Calculate area of triangle.
// if area = 0, points are collinear else they are non collinear.


#include <iostream>
using namespace std;
int main()
{//decleration of variables.
	int x1, y1, x2, y2, x3, y3;
	float a;

//Intput from user
	cout << "Enter x and y coordinates of first point : " << endl;
	cin >> x1 >> y1 ;
	cout << "Enter x and y coordinates of second point : " << endl;
	cin >> x2 >> y2;
	cout << "Enter x and y coordinates of third point : " << endl;
    cin >> x3 >> y3;

//computing result i.e. calculating area of triangle.
	a = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3*(y1 - y2))/2;

//assigning output on the basis of result
	if (a==0)
		cout << "The given points are collinear." << endl;
	else
		cout << "The given points are non collinear." << endl;
	return 0;
}



