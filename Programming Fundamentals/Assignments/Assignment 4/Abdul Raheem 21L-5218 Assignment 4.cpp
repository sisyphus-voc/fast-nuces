#include <iostream>
#include <iomanip>

using namespace std;
//declaration of functions

int Factorial(int);
float Power(float, int);
float SquareRoot(float sqrtno);
bool IsPrime(int num);
void PrintPrimeFactors(int a);
int LCM(int x, int y);
int GCD(int x, int y);
void PrintInvalid();
int Max(int a, int b);
double Exponent(int a);
double DegreeToRadian(double a);
double Sin(double a);
double Cos(double a);
long double SinInverse(long double a);
int Fib(int a);


int main()
{
	string number, option;
	int o = 0, a = 0, c = 0, tempnum = 0, num1, num2;
	float sqrtno;
	//Input Validation
	do {

		
		cout << "Enter your option (1 to 10):\n"
			<< "1. Finding the factorial of a given number(number ranges from 0 to 15)\n"
			<< "2. Finding x^y.\n"
			<< "3. Finding the square root of a given positive integer.\n"
			<< "4. Finding all the prime factors of a given integer.\n"
			<< "5. Finding LCM and GCD of 2 integers.\n"
			<< "6. Finding nth element of Fibonacci Series.First two terms being 0 and 1.\n"
			<< "7. Finding the value of ex using Taylor expansion.\n"
			<< "8. Finding sin of an angle.\n"
			<< "9. Finding cos of an angle.\n"
			<< "10. Finding sin-1 of a number.\n";
		cin >> option;

		if (option == "1")
			o = 1;
		else if (option == "2")
			o = 2;
		else if (option == "3")
			o = 3;
		else if (option == "4")
			o = 4;
		else if (option == "5")
			o = 5;
		else if (option == "6")
			o = 6;
		else if (option == "7")
			o = 7;
		else if (option == "8")
			o = 8;
		else if (option == "9")
			o = 9;
		else if (option == "10")
			o = 10;
		if (!(o >= 1 && o <= 10))
		{
			PrintInvalid();
		}
	} 
	while (!(o >= 1 && o <= 10));

	//Factorial
	if (option == "1")
	{
		do
		{

			cout << "1. Finding the factorial of a given number(number ranges from 0 to 15)\n";
			cin >> number;

			if (number == "0")
				tempnum = 0;
			else if (number == "1")
				tempnum = 1;
			else if (number == "2")
				tempnum = 2;
			else if (number == "3")
				tempnum = 3;
			else if (number == "4")
				tempnum = 4;
			else if (number == "5")
				tempnum = 5;
			else if (number == "6")
				tempnum = 6;
			else if (number == "7")
				tempnum = 7;
			else if (number == "8")
				tempnum = 8;
			else if (number == "9")
				tempnum = 9;
			else if (number == "10")
				tempnum = 10;
			else if (number == "11")
				tempnum = 11;
			else if (number == "12")
				tempnum = 12;
			else if (number == "13")
				tempnum = 13;
			else if (number == "14")
				tempnum = 14;
			else if (number == "15")
				tempnum = 15;
			else
				tempnum = 1000000;
			if (!(tempnum >= 0 && tempnum <= 15))
			{
				PrintInvalid();
			}

		} 
		while (!(tempnum >= 0 && tempnum <= 15));

		cout << Factorial(tempnum);

	}


	//Power 
	else if (option == "2")

	{
		int exponent;
		float base;
		float power;
		cout << "Enter a Number : \n";
		cin >> base;
		cout << "Enter the exponent : \n";
		cin >> exponent;
		power= Power(base, exponent);
		cout  << power;
	}



	//Squareroot
	else if (option == "3")

	{

		cout << "Enter a number : \n";
		cin >> sqrtno;

		cout << setprecision(6) << SquareRoot(sqrtno);

	}



	else if (option == "4")

	{
		bool notprime;
		int count1 = 2, number4, x;
		cout << "Enter a number : ";
		cin >> number4;
		while (number4 <=1)
		{
			PrintInvalid();
			cout << "Prime Factors of 0, 1 or negative numbers do not exist \n";
			cout << "Enter a number : ";
			cin >> number4;

		}
		PrintPrimeFactors(number4);

	}
	//LCM and GCD
	else if (option == "5")
	{
		int lcm = 0, gcd = 0;
		cout << "Enter two numbers: ";
		cin >> num1 >> num2;
		while (num2 == 0 || num1 == 0)
		{
			PrintInvalid();
			cout << "Enter numbers greater than 0 \n";
			cout << "Enter two numbers: \n";
			cin >> num1 >> num2;

		}
		lcm = LCM(num1, num2);
		gcd = GCD(num1, num2);
		cout << "LCM : " << lcm << endl << "GCD : " << gcd << endl;



	}
	//Fibonacci Series 
	else if (option == "6")
	{
	int n, element = 0;

	cout << "Enter the number of term : \n";
	cin >> n;
	element = Fib(n);
	cout << element;

		

	}


	//7.e^x using taylor series 
	else if (option == "7")
	{
		int x;
		double epowx;
		cout << "Enter exponent : ";
		cin >> x;
		epowx = Exponent(x);
		cout  << epowx << endl;



	}

	//8.Sin
	else if (option == "8")
	{
		double angle = 0, sin = 0;
		cout << "Enter angle : \n";
		cin >> angle;
		angle = DegreeToRadian(angle);
		sin = Sin(angle);
		cout << setprecision(2)<< sin;



	}
	//9.cos
	else if (option == "9")
	{
		double angle = 0, cos = 0;
		cout << "Enter angle : \n";
		cin >> angle;
		angle = DegreeToRadian(angle);
		cos = Cos(angle);
		cout << setprecision (2) <<cos;


	}
	//10.sin-1
	else if (option == "10")
	{
		long double angle = 0, sinInverse = 0;
		cout << "Enter angle between -1 and 1 : \n";
		cin >> angle;
		while (angle < -1 && angle>1)
		{
			PrintInvalid();
			cout << "Enter angle between -1 and 1 : \n";
			cin >> angle;

		}
		angle = DegreeToRadian(angle);
		sinInverse = SinInverse(angle);

	}
	return 0;
	
	

}






/*****************************************************************Functions*************************************************/



//1.Factorial Function
int Factorial(int tempnum)
{
	int c = 1, a = 1;
	
while (c <= tempnum)
{
	a = a * c;
	c++;
}
return a;
}

//2.Power function
float Power(float base, int exponent)
{
	float x = base;
	float y  = exponent;
	float power=1;
	int c=0;

	/*if (y == 1)
		power = x ;
		*/

	if (y == 0)
		power=1;

	else if (y > 0)
	{
		while (c < y)
		{
			power *= x;

			c++;
		}
	}

	/*else if (y == -1)
	{
		power = 1 / x;
	}
	*/
	else if (y < 0)
	{
		while (c > y)
		{

			power *= (1 / x);
			c--;
		}

	}

	return power;
}

//3. Square root Function
float SquareRoot(float sqrtno)
{

	float s=0,r=0;

	

	while (!(r>= sqrtno))
	{
		r = s*s;


		s += 0.00001;

	}
	return s;

	
}
//4. Prime number Function
void PrintPrimeFactors(int a) 
{
	while (a % 2 == 0) 
	{
		cout << "2 \t";
		a = a / 2;
	}
	for (int i = 3; i <= SquareRoot(a); i = i + 2) 
	{
		while (a % i == 0) 
		{
			cout << i << "\t";
			a = a / i;
		}
	}
	if (a > 2)
		cout << a << "\t";
}


//5.LCM and GCD Function
int LCM(int x, int y)
{

	int c = 2;
	while (c%x!=0||c%y!=0)
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
	int max = 0,c=0;
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


//6.Fibonacci series function
int Fib(int a)
{
	int x = 0, y = 1, z;
	if (a == 0)
		return x;

	for (int c = 2; c <= a; c++)
	{
		z = x + y;
		x = y;
		y = z;
	}
	return y;
}


//7.exponential Function
double Exponent(int a)
{
	double sum=0;
	for (int n = 0; n <= 10; n++)
	{
		sum += Power(a, n) / Factorial(n);
		
	}
	return sum;
}

//8.sin of an angle
double Sin(double a)
{
	double sin=0;
	double numerator_sign,numerator, denominator;
	for (int n = 0; n <= 10; n++)
	{
		numerator_sign = Power(-1, n);
		numerator=Power(a, (2 * n + 1));
		denominator = Factorial(2 * n + 1);
		sin += (numerator * numerator_sign) / denominator;


	}
	return sin;
}


//9.Cos of an angle
double Cos(double a)
{

	double cos = 0;
	double numerator_sign, numerator, denominator;
	for (int n = 0; n < 15; n++)
	{
		numerator_sign = Power(-1, n);
		numerator = Power(a, (2 * n ));
		denominator = Factorial(2 * n);
		cos += (numerator * numerator_sign) / denominator;


	}
	return cos;
}
//10.Sin Inverse Function
long double SinInverse(long double a)
{
	long double sinInverse = a;
	double coefficient = 1, x = 1, y = 2,z=3;
	for (int c = 1; c <= 20; c++,x+=2,y+=2,z+=2)
	{

		coefficient = coefficient * (x / y);
		
		sinInverse =  coefficient * (Power(a, z) / z);
		cout << sinInverse << endl;
	}
	
	return sinInverse*180/3.1415926535;



}

/***************Extra FUnctions**************************/

//Invalid output displaying function
void PrintInvalid()
{
	cout << "Invalid input !!! " << endl;

}


//Degree to radian
double DegreeToRadian(double a)
{
	while (a > 360)
	{
		a = a - 360;
	}
	while (a < -360)
	{
		a=a+360;
	}
	a = a / 57.295;
	return a;
}
//Greatest number finding function

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

//Unique Prime Factors
bool IsPrime(int num)
{
	bool Isprime = true;
	if (num == 0 || num == 1)
	{
		Isprime = false;
	}
	for (int c = 2; c <= num / 2; c++)
	{
		if (num % c == 0)
		{
			Isprime = false;
		}


	}
	return Isprime;

}





