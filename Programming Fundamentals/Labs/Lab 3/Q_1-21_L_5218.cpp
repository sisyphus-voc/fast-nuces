//Post Lab 3
//Q no.1
//Name : Abdul Raheem
//Roll no: 21L-5218
//Section : BCS-1N1

#include <iostream>
using namespace std;

int main()
{
	//decleration of variables.
	double w, h,bmi;
	
	//taking input from user.
	cout << "Enter weight in pounds :";
	cin >> w;
	cout << "Enter height in inches :";
	cin >> h;

	//calculating BMI.
	bmi = w / (703 * h * h);

	//Displaying BMI as output.
	cout << "BMI = " << bmi <<endl;

	//Displaying whether according to the entered measurements the user is optimal weight, underweight or overweight.
	if (bmi >= 18.5 && bmi <= 25)
		cout << "You have optimal weight."<<endl;
	else if (bmi < 18.5)
		cout << "You are underweight."<<endl;
	else if (bmi > 25)
		cout << "You are overweight."<<endl;
	return 0;
}

