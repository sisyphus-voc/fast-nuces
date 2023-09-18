#include <iostream>

using namespace std;


class Polynomial
{

private:
	int totalTerm;
	int* coeff;
	int* exp;
	static int objectcount;
public:
	Polynomial()
	{
		totalTerm = 0;
		coeff = 0;
		exp = 0;
		objectcount++;
	}

	Polynomial(int t, int* c, int* e)
	{
		totalTerm = t;
		coeff = new int[totalTerm];
		exp = new int[totalTerm];

		for (int i = 0; i < totalTerm; i++)
		{
			coeff[i] = c[i];
			exp[i] = e[i];
		}
		objectcount++;
	}

	static int GetCount()
	{
		return objectcount;
	}

	void print()
	{
		for (int i = 0; i < totalTerm; i++)
		{
			if (exp[i] != 0 && coeff[i]!=0)
			{
				if (coeff[i] == 1)
				{
					cout << "x^" << exp[i];
				}
				else
				cout << coeff[i] << "x^" << exp[i];

			}
			else
				cout << coeff[i];
			if (i < totalTerm - 1)//checks last term
			{
				cout << "+";
			}
		}
		cout << endl;
	}
	bool operator !()
	{
		if (totalTerm == 1 && coeff == 0 && exp == 0)
		{
			return true;
		}
		else
			return false;
	}
	bool operator != (const Polynomial &newP)
	{
		bool isNotequal=false;
		if (totalTerm == newP.totalTerm)
		{
			for (int i = 0; i < totalTerm; i++)
			{
				if (coeff[i] == newP.coeff[i] && exp[i] == newP.exp[i])
				{
					return false;
				}
				else
					isNotequal = true;
			}
			return isNotequal;
		}
		else
			return true;

	}

	Polynomial operator + (const Polynomial& newP)
	{
		Polynomial temp;
		temp.totalTerm = totalTerm;

		temp.coeff = new int[temp.totalTerm];
		temp.exp = new int[temp.totalTerm];


		for (int i = 0; i < temp.totalTerm; i++)
		{
			temp.coeff[i] = coeff[i] + newP.coeff[i];
			temp.exp[i] = exp[i];

		}
		return temp;
	}
	Polynomial operator - (const Polynomial& newP)
	{
		Polynomial temp;
		temp.totalTerm = totalTerm;

		temp.coeff = new int[temp.totalTerm];
		temp.exp = new int[temp.totalTerm];
		for (int i = 0; i < temp.totalTerm; i++)
		{
			temp.coeff[i] = coeff[i] - newP.coeff[i];
			temp.exp[i] = exp[i];

		}
		return temp;


	}
	void operator = (const Polynomial &newP)
	{
		totalTerm = newP.totalTerm;
		for (int i = 0; i < totalTerm; i++)
		{
			coeff[i] = newP.coeff[i];
			exp[i] = newP.exp[i];
		}
		
	}
};

int Polynomial::objectcount = 0;

int main()
{
	int coeff_P1[] = { 1,2,5 };
	int exp_P1[] = { 4,2,0 };

	int coeff_P2[] = { 4,3,7 };
	int exp_P2[] = { 6,2 ,1};


	int coeff_P3[] = { 1,6,5 };
	int exp_P3[] = { 6,2,1 };
	
	

	Polynomial P1(3, coeff_P1, exp_P1);
	Polynomial P2(3, coeff_P2, exp_P2);
	Polynomial P3(3, coeff_P3, exp_P3);
	

	cout << "P1 : ";
	P1.print();
	cout << "P2 : ";
	P2.print();

	if (!P1)
	{
		cout << "P1 is zero \n";
	}

	if (P1 != P2)
	{
		cout << "P1 is not equal to P2\n";
	}

	Polynomial P4 = P2 + P3;
	cout << "P4 : ";
	P4.print();
	Polynomial P5 = P4 - P3;
	cout << "P5 : ";
	P5.print();

	Polynomial P6 = P5;
	cout << "P6 : ";
	P6.print();
	
	cout << "Total count : " << Polynomial::GetCount() << endl;

	return 0;
}