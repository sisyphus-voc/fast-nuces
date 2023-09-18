// Problem 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream fout;
	ifstream fin;
	int num;



	fin.open("Problem2.txt");
	fout.open("Problem 2 Output file.txt");
	fout << "The even values are " << "\n\n";
	while (!fin.eof())
	{


		fin >> num;
		
		
		if (num % 2 == 0)
		{
			fout << num << "\n\n";

		}

	}
	fin.close();
	

	return 0;
}
