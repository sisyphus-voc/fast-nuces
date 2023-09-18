//																			OOP ASSIGNMENT - 1
//																				Abdul Raheem
//																				 21L-5218
//																				  BCS-2N
//																					Q5

#include <iostream>

using namespace std;

class fraction
{
public:
	int numerator = 0, denominator = 0;
	char slash='/';

	void ReadData(int &numerator, int &denominator)
	{
		

			cout << "Enter fraction: (x/y form): \n";
			cin >> numerator >> slash >> denominator;

			while (denominator == 0)
			{
				if (denominator == 0)
				{
					cout << "Invalid denominator ! \nDenominator can not be zero\n";
				}
				cout << "Enter fraction: (x/y form): \n";
				cin >> numerator >> slash >> denominator;

			}
		
	}

	void Sum(fraction f1,fraction f2, fraction& f3)
	{	
		int lcm = 0, gcd = 0;
		lcm = LCM(f1.denominator, f2.denominator);
		cout << "lcm " << lcm << endl;
		f3.denominator = lcm;
		if (f1.denominator == f2.denominator)
		{
			f3.numerator = f1.numerator + f2.numerator;

		}
		else
		{
			f3.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
		}
		
		gcd = GCD(f3.denominator, f3.numerator);
		cout << "GCD " << gcd << endl;
		if (f3.denominator % gcd == 0 && f3.numerator % gcd == 0)
		{
			f3.denominator = f3.denominator / gcd;
			f3.numerator = f3.numerator / gcd;
		}
	}

	int LCM(int x, int y)
	{

		int c = 2;
		while (c % x != 0 || c % y != 0)
		{
			c++;
		}
		if (c % x == 0 && c % y == 0)
		{
			return c;
		}


	}
	int GCD(int x, int y)
	{
		int max = 0, c = 0;
		max = Max(x, y);


		c = max;
		while (x % c != 0 || y % c != 0)
		{
			c--;
		}
		if (x % c == 0 && y % c == 0)
		{
			return c;
		}






	}
	int Max(int a, int b)
	{
		int max = 0;

		if (a == b)
		{
			max = a;
		}

		else if (a >= b)
		{
			max = a;
		}
		else if (b >= a)
		{
			max = b;


		}
		return max;

	}
};


int main()
{
	fraction f1, f2, f3;
	char choice = 'y';

	while (choice == 'y')
	{
		
		f1.ReadData(f1.numerator, f1.denominator);
		f2.ReadData(f2.numerator, f2.denominator);
		f3.Sum(f1, f2, f3);
		cout <<"The sum is : " << f3.numerator << "/" << f3.denominator << "\n\n";
		cout << "Press y to continue \t Press any key to exit\n--> ";
		cin >> choice;

	}

	system("pause");
	return 0;
	
}
