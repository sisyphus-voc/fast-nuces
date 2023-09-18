#include <iostream>

using namespace std;

//float Divide(int a, int b)
//{
//
//}
//float Mod(int a, int b)
//{
//
//}
int BinarySearch(int arr[], int x, int low, int high)
{
	int mid = low + (high-low) / 2;
	if (low > high)
	{

		return -1;
	}
	else
	{

		if (arr[mid] == x)
		{
			return mid;
		}
		else if (arr[mid]>x)
		{
			return BinarySearch(arr, x, low, mid-1);
		}
		else
		{
			return BinarySearch(arr, x, mid + 1, high);
		}
	}

}
void print(int  idx)
{
	if (idx == -1)
	{
		cout << "The value doesn't exist\n";
	}
	else
		cout << "The element is present at index: " << idx << endl;
}

int FibRec(int x)
{
	if (x <= 1)
	{
		return 0;
	}
	else if (x == 2 ||x==3)
	{
		return 1;
	}
	else
		return FibRec(x - 2) + FibRec(x - 1);
}
void FibIterate(int x)
{
	
		int a = 0, b = 1, sum = 0;

	

		cout << "Fibonacci Series: ";

		for (int i = 0; i < x; ++i)
		{
		
			if (i == 0)
			{
				cout << a << ", ";
				continue;
			}
			if (i == 1)
			{
				cout << b << ", ";
				continue;
			}
		
			sum = a + b;
			a = b;
			b = sum;

			cout << sum<< ", ";
		}
		cout << endl;
		
	
}
void DivnMod(int A, int B, int quotient)
{
	int remainder = A - B;

	if (remainder < B)
	{
		cout << "A / B : " << quotient+1 << endl;
		cout << "A % B : " << remainder << endl;
		return;
	}

	DivnMod(A - B, B, quotient + 1);
}

void TriSums(int num)
{

	int x = 0;
	int y = 1;
	int z = 2;
	for (int i = 0; i < num; i++)
	{
		int sum = 0;
		if (i == 0)
		{
			cout << y << endl;
			cout << z << endl;
		}
	

		sum = x + y + z;
		x = y;
		y = z;
		z = sum;
		cout << sum << endl;
	}
}
int main()
{
	cout << "Q1:\n\n";
	int arr[] = { 2, 4, 8, 12, 16, 32, 64 };

	int index = BinarySearch(arr, 12, 0, 6);

	print(index);
	index = BinarySearch(arr, 5, 0, 6);
	print(index);

	cout << "Q3:\n\n";
	cout << "Fib Recursive: " << FibRec(10)<<endl;
	cout << "Fib Iterative: ";
	FibIterate(10);

	cout << "Q2:\n\n";
	DivnMod(17, 6, 0);

	cout << "\nQ Trisum:\n\n";
	TriSums(5);
	system("pause");
	return 0;
}