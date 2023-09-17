//********************** Addition in DMS ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 3)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Adds two number in degree min and seconds. 
// INPUT: 2 DMS measurements
// OUTPUT: Total DMS measurement.
// ALGORITHM:Take two DMS measurements from user.
// Add degrees minutes and seconds of first measurement in degrees minutes and seconds of second measurement respectively.
// If seconds exceed 60, for each exceeding 60 carry 1 to mins and dispay reamining seconds.
// If mins exceed 60, for each exceeding 60 carry 1 to degree and dispay reamining mins.
// If Degree exceeds 360 display for each 360 . 


#include <iostream>
using namespace std;
int main()
{
	//declaration of variables
	int d, m, s, d1, m1, s1, d2, m2, s2;
	
	//taking input from user
	cout << "Enter first angular measurement in degrees minutes seconds : " << endl;
	cin >> d1 >> m1 >> s1;
	cout << "Enter second angular measurement in degrees minutes seconds : " << endl;
	cin >> d2 >> m2 >> s2;

	//calculating DMS
	d = d1 + d2;
	m = m1 + m2;
	s = s1 + s2;
	
	//If seconds exceed 60
	if (s >= 60)
	{
		m = m + (s / 60);
		s = s % 60;
	}

	//If minutes exceeed 60
	if (m >= 60)
	{
		d = d + (m / 60);
		m = m % 60;
	}

	//If degrees equals 360, and minutes and seconds equals 0.
	if (d == 360 && m == 0 && s == 0)
	{
		d = 0;
		m = 0;
		s = 0;
	}
	
	//if degrees exceed 360.
	else if (d > 360)
	{
		d = d % 360;
			}

	//displaying output.
	cout << d1 << "°" << m1 << "'" << s1 << "\"" << " + ";
	cout << d2 << "°" << m2 << "'" << s2 << "\"" << " = ";
	cout << d << "°" << m << "'" << s << "\"" << endl;

	return 0;

}



