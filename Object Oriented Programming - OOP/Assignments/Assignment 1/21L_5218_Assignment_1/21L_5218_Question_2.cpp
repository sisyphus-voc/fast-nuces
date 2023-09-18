//																			OOP ASSIGNMENT - 1
//																				Abdul Raheem
//																				 21L-5218
//																				  BCS-2N
//																				    Q2
#include <iostream>
using namespace std;

int* SearchGreater(int*, int*, int*, int*);
int main()
{
	int w, x, y, z;
	int* a = &w, * b = &x, * c = &y, * d = &z;
	int* greatest = NULL;
	
	cout << "Enter 4 numbers: ";
	cin >> *a >> *b >> *c >> *d;

	greatest=SearchGreater(a, b, c, d);
	
	cout << *greatest;
	* a = NULL, * b = NULL, * c = NULL, * d = NULL;
	system("pause");
	return 0;
}
int* SearchGreater(int* a, int* b, int* c, int* d)
{
	int g = 0;
	int* greatest=&g;
	
	if (*a >= *b && *a >= *c && *a >= *d)
	{
		*greatest = *a;
	}
	else if (*b >= *a && *b >= *c && *b >= *d)
	{
		*greatest = *b;
	}
	else if (*c >= *a && *c >= *b && *c >= *d)
	{
		*greatest = *c;
	}
	else if (*d >= *a && *d >= *c && *d >= *b)
	{
		*greatest = *d;
	}

	return greatest;


}