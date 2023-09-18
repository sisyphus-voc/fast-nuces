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



	fin.open("Problem2part2.txt");
	fout.open("Problem2_part_2_Output_file.txt");
	fout << "The even values are " << "\n\n";
	for (int row = 1; row<=5;row++)
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
