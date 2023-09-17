//********************** Calculator ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 7)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Takes operator and operand from user and performs the given operation.
// INPUT: operator, operands.
// OUTPUT: Result 
// OTHER:
// ALGORITHM : Takes operator and operand from user and performs the given operation.
//
//
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	//declaration of variable.
	float x, y,z,a=1,c=1;
	string r = "The result is ";
	char o = '0';

	//displaying instructions
	cout << "Welcome to the 8 - function Calculator!\n" << "Enter\n" << "+ for addition operation\n";
	cout << "- for subtraction operation\n" << "* for multiplication operation\n" << "/ for division operation\n";
	cout << "^ for exponentiation operation\n" << "l for base - 10 logarithm operation\n" << "!for factorial operation\n";
	cout << "q to quit" << endl;

	//until the user quits 
	while (o != 'q')
		
	{
		//Taking the operator as input 
		cout << "\n  --> ";
		cin >> o;
		if (o == '+')
		{
			//Calculations and output if operator is +
			cout << "Enter the first operand :";
			cin >> x;
			cout << "Enter the second operand: ";
			cin >> y;
			cout << r << x + y;

		}
		else if (o == '-')
		{
			//Calculations and output if operator is -
			cout << "Enter the first operand :";
			cin >> x;
			cout << "Enter the second operand :";
			cin >> y;
			cout << r << x - y;

		}
		else if (o == '*')
		{
			//Calculations and output if operator is *
			cout << "Enter the first operand :";
			cin >> x;
			cout << "Enter the second operand :";
			cin >> y;
			cout << r << x * y;
		}
		else if (o == '/')
		{
			//Calculations and output if operator is/
			cout << "Enter the first operand :";
			cin >> x;
			cout << "Enter the second operand :";
			cin >> y;
			cout << r << x / y;
		}
		else if (o == '^')
		{
			//Calculations and output if operator is^
			cout << "Enter the first operand :";
			cin >> x;
			cout << "Enter the second operand :";
			cin >> y;
			cout << r << pow(x, y);
		}
		else if (o == 'l')
		{
			//Calculations and output if operator is l
			cout << "Enter an operand :";
			cin >> z;
			cout << r << log10(z);
		}
		else if (o == '!')
		{
			//Calculations and output if operator is !
			cout << " Enter an operand :";
			cin >> z;
			while (c <= z)
			{
				a = a * c;
				c++;
			}
			cout << r << a;

		}

		//output if user quits the menu.
		else if (o == 'q')
			cout << "(Quit the menu)";
		//output if user enters any character other than operators provided in instructions.
		else
			cout << "Invalid operator";

	}
	

    return 0;
	

}


