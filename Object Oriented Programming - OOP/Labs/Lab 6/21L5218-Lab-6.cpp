#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
private:
	int* real; //Integer will be saved on heap
	int* imaginary; //Data will be saved on heap
public:
	ComplexNumber()
	{
		cout << "Default Constructor Called\n";
		real = new int;
		imaginary = new int;

		/**real = 0;
		*imaginary = 0;*/
	}
	ComplexNumber(int r, int i)/*Constructor with Default arguments,
	allocate memory properly and display Constructor Called message with
	data.*/
	{
		cout << "Constructor called";
		real = new int;
		imaginary = new int;
		*real = r;
		*imaginary = i;
	}
	ComplexNumber(const ComplexNumber& newNum)
	{
		int temp_real = 0, temp_imaginary = 0;
		temp_real = *newNum.real;
		temp_imaginary = *newNum.imaginary;


		cout << "Copy constructor called\n";
		*real = temp_real;
		*imaginary = temp_imaginary;

	}

	void Input() //Takes input from user
	{
		cout << "Enter the number (x+yi) : ";
		
		cin >> *real;
		cin.ignore();
		cin >> *imaginary;
	}
	void Output() //Properly display Complex number like a+bi
	{
		cout << *real << "+" << *imaginary << "i\n";
	}
	void Print() //Properly display Complex number like a+bi
	{
		cout << *real << "+" << *imaginary << "i\n";
	}
	float Magnitude() //Calculates magnitude of a complex number
	{
		float magnitude = 0.0;
		magnitude = ((*real) * (*real))+((*imaginary) * (*imaginary));
		magnitude = sqrt(magnitude);
		return magnitude;
	}

	~ComplexNumber()/*Deallocate memory properly and Display
					Destructor Called message with data.*/
	{

		cout << "Destructor Called\n";
		cout << *real << "+" << *imaginary << "i\n";
		
		delete real;
		delete imaginary;
	}

};

int main()

{
	//Exercise 2
	/*ComplexNumber c1;
	c1.Input();
	c1.Output();*/

	//Exercise 3 
	//Ans: It doesn't call the constructor implicitly;
	ComplexNumber* cPtr;

	//Exercise 4
	ComplexNumber myComplexNumber(3,5);
	cPtr = &myComplexNumber;
	cPtr->Output();

	//Exercise 5
	//Ans : No we dont have to delete the array
	ComplexNumber complexArray[5];
	for (int i = 0; i < 5; i++)
	{
		complexArray[i].Input();
		
		complexArray[i].Output();
		cout << "Magnitude : " << complexArray[i].Magnitude() << endl;
		cin.ignore();
	}

	//Exercise 6
	//Ans : We need to do de allocate the memory allocated to the array
	int size = 0;
	cout << "Enter size of Array: ";
	cin >> size;
	ComplexNumber* dynamicArray=new ComplexNumber[size];
	for (int i = 0; i < size; i++)
	{
		complexArray[i].Input();

		complexArray[i].Output();
		cout << "Magnitude : " << complexArray[i].Magnitude() << endl;
		cin.ignore();
	}
	delete[] dynamicArray;

	//Exercise 7


	/*ComplexNumber c1(3, 4);
	ComplexNumber c2(4, 5);
	{
		ComplexNumber temp = c1;
		c1 = c2;
		c2 = temp;
	}
	c1.Print();

	c2.Print();*/

	//Exercise 8


	/*ComplexNumber c1(5, 10);
	{
		ComplexNumber c2(c1);
		cout << "C2 = ";
		c2.Print();
	}
	cout << "C1 = ";
	c1.Print();
	return 0;*/
}
