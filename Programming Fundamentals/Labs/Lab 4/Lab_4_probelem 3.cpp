// Lab_4_probelem 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{

	int n = 0, opinion = 0, count = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
	



	cout << "Enter number of classmates : ";
	cin >> n;

	while (count < n)
	{
		cout << "Rank the food : \n";
		cin >> opinion;
		switch (opinion)
		{
		case 1: 

			c1++;
			break;
		case 2:
			c2++;
			break;
		case 3:
			c3++;
			break;

		case 4:
			c4++;
			break;
		case 5:
			c5++;
			break;

		}
		count++;
		
	}
	cout << "Frequency of rank is 1 :  " << c1 << endl;
	cout << "Frequency of rank is 2 : " << c2 << endl;
	cout << "Frequency of rank is 3 : " << c3 << endl;
	cout << "Frequency of rank is 4 : " << c4 << endl;
	cout << "Frequency of rank is 5 : " << c5 << endl;




	return 0;
}
