
#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter a number : ";
	cin >> num;
	for (int row = 1; row <= num; row++)
	{
		cout << row << '*' << '\t';

			for (int col = 1; col <= 6; col++)
			{
				

				cout << row * col;
				cout << "\t";
			}
		
		cout << endl;

	}
  
}
