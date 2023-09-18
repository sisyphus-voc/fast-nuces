#include <iostream>
#include <cstring>
using namespace std;


int** AllocateMemory(int& rows, int& cols)
{
	int** Matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		Matrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Matrix[i][j] = 0;
		}
	}
	return Matrix;
}
void InputMatrix(int** Matrix, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter element of Row # " << i << " col # " << j<<" : ";
			cin >> Matrix[i][j];
		}
	}
}
void DisplayMatrix(int** Matrix, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void DeallocateMemory(int** Matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete Matrix[i];
	}
	delete[] Matrix;
}
int* MaxofCols(int** Matrix, const int& rows, const int& cols)
{
	int* MaxCols = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		MaxCols[i] = 0;
	}

	int greatestElement;
	int c = 0;

	for (int i = 0; i < cols; i++)
	{
		greatestElement = 0;
		for (int j = 0; j < rows; j++)
		{
			if (Matrix[j][i] > greatestElement)
			{
				greatestElement = Matrix[j][i];
			}
		}
		MaxCols[c] = greatestElement;
		c++;
	}


	return MaxCols;
}
void DisplayMatrix(int* Matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		cout << Matrix[i] << "\t";

		cout << endl;
	}
}
int* GetDiagonal(int** Matrix, const int& rows, const int& cols)
{
	int* Diagonal = new int[rows];
	for (int i = 0; i < cols; i++)
	{
		Diagonal[i] = 0;
	}

	int c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				Diagonal[c] = Matrix[i][j];
				c++;
			}
		}
	}

	return Diagonal;
}

void Election(char** candidates, const int* votes, const int& size)
{
	float totalVotes = 0;
	int winner = -1;
	int mostVotes = votes[0];
	float* percentagevotes = new float[size];
	for (int i = 0; i < size; i++)
	{
		totalVotes += votes[i];
	}
	cout << "Candidate \t" << "Votes Recieved \t" << "% of Vote \t" << endl;
	for (int i = 0; i < size; i++)
	{
		percentagevotes[i] = ((votes[i] / totalVotes) * 100.0);
		cout << candidates[i] << "\t\t"<<votes[i]<<"\t\t" <<percentagevotes[i]<<"\t";
		if (votes[i] > mostVotes)
		{
			mostVotes = votes[i];
			winner = i;
		}
		cout << endl;
	}
	cout << "Total \t" << totalVotes<<endl;
	cout << "The Winner of the Election is " << candidates[winner]<<endl;

}

bool IsMatrixUpperTriangular(int** Matrix, const int& rows, const int& cols)
{
	bool isUpper = false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i > j&&Matrix[i][j]==0)
			{
				isUpper = true;
			}
			else if (i > j && Matrix[i][j] != 0)
			{
				isUpper = false;
				return isUpper;
			}
		}
	}
	return isUpper;
}

int main()
{


	int rows = 0, cols = 0;
	int** myArray;
	int* MaxCols;
	int* Diagonal;
	cout << "Enter rows and columns of 2D Array:\n";
	cin >> rows >> cols;

	myArray = AllocateMemory(rows, cols);
	InputMatrix(myArray, rows, cols);
	DisplayMatrix(myArray, rows, cols);
	cout << "MaxCols \n";
	MaxCols=MaxofCols(myArray, rows, cols);
	DisplayMatrix(MaxCols, cols);
	Diagonal=GetDiagonal(myArray, rows, cols);
	cout << "Diagonal: \n";
	DisplayMatrix(Diagonal, rows);
	

	int noOfCandidates = 5;

	char** candidates=new char*[noOfCandidates];
	for (int i = 0; i < noOfCandidates; i++)
	{
		candidates[i] = new char[30];
	}
	int* Votes = new int[noOfCandidates];
	
	cin.ignore();
	for (int i = 0; i < noOfCandidates; i++)
	{
		
		cout << "Enter Last Name of Candidate : \n";
		cin.getline(candidates[i],30);
		cout << "\nEnter no of Votes of the candidate : \n";
		cin >> Votes[i];
		cin.ignore();
	}
	Election(candidates, Votes, noOfCandidates);

	bool isMatrixUpperTriangular=false;
	isMatrixUpperTriangular =IsMatrixUpperTriangular(myArray, rows, cols);
	if (isMatrixUpperTriangular)
	{
		cout << "Matrix is upper triangular \n";

	}
	else
	{
		cout << "Matrix is not upper triangular \n";
	}
	DeallocateMemory(myArray, rows);
	return 0;
}
