
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int  dim=0;
	char kind, ch;
	char space = ' ';
	string  shape, num;
	//Input validations 
	do
	{



		//displaying output to user until valid output is entered 
		cout << "Enter your option for the shape type(1 to 6) : \n1. Right Triangle \n2. Isosceles Triangle \n3. Diamond \n4. Square \n";
		cout << "5. Rectangle(rows fixed at 6)	\n6. Parallelogram(rows fixed at 6) \n";
		cin >> shape;
	}

	
	while (!(shape == "1" || shape == "2" || shape == "3" || shape == "4" || shape == "5" || shape == "6"));



	cout << "Enter s for solid \nh for hollow \nb for both solid and hollow shapes \n";
	cin >> kind;

	//invalid shape kind
	while (!(kind == 's' || kind == 'h' || kind == 'b'))
	{
		cout << "Invalid input !!! \n";
		cout << "Enter s for solid \nh for hollow \nb for both solid and hollow shapes \n";
		cin >> kind;

	}
	//after getting a valid shape
	if (kind == 's' || kind == 'h' || kind == 'b')
	{



		//data type validation of dimension
		do
		{

			cout << "Enter the dimension (between 2 and 20): \n";
			cin >> num;
			if (num == "2")
				dim = 2;
			else if (num == "3")
				dim = 3;
			else if (num == "4")
				dim = 4;
			else if (num == "5")
				dim = 5;
			else if (num == "6")
				dim = 6;
			else if (num == "7")
				dim = 7;
			else if (num == "8")
				dim = 8;
			else if (num == "9")
				dim = 9;
			else if (num == "10")
				dim = 10;
			else if (num == "11")
				dim = 11;
			else if (num == "12")
				dim = 12;
			else if (num == "13")
				dim = 13;
			else if (num == "14")
				dim = 14;
			else if (num == "15")
				dim = 15;
			else if (num == "16")
				dim = 16;
			else if (num == "17")
				dim = 17;
			else if (num == "18")
				dim = 18;
			else if (num == "19")
				dim = 19;
			else if (num == "20")
				dim = 20;

		} 
		while (!(dim >= 2 && dim <= 20));




		//getting valid dimension
		if (dim >= 2 && dim <= 20)
		{
			//taking character input
			cout << "Enter the character type (only *, ?, %, $ and & are allowed): \n";
			cin >> ch;
			while (ch != '*' && ch != '?' && ch != '%' && ch != '$' && ch != '&')
			{
				cout << "Invalid character type !!! \n";
				cout << "Enter the character type (only *, ?, %, $ and & are allowed): \n";
				cin >> ch;
			}

		}






	}

	//Right triangle
	if (shape == "1")


	{
		//right triangle solid
		for (int row = 1; row <= dim && kind == 's'; row++)
		{
			{
				for (int col = 1; col <= row; col++)
					cout << ch;
			}
			cout << endl;
		}

		//right triangle hollow
		for (int row = 1; row <= dim && kind == 'h'; row++)
		{
			{
				for (int col = 1; col <= row; col++)
				{
					if (col == 1 || col == row || row == dim)
					{
						cout << ch;
					}
					else
					{
						cout << space;
					}

				}
				cout << endl;


			}


		}

		//Right triangle both
		if (kind == 'b')
		{
			//right triangle solid in both
			for (int row = 1; row <= dim; row++)
			{
				{
					for (int col = 1; col <= row; col++)
						cout << ch;
				}
				cout << endl;
			}
			//for seperation between solid and hollow shape
			cout << endl;

			//right triangle hollow in both
			for (int row = 1; row <= dim; row++)
			{
				{
					for (int col = 1; col <= row; col++)
					{
						if (col == 1 || col == row || row == dim)
						{
							cout << ch;
						}
						else
						{
							cout << space;
						}

					}
					cout << endl;


				}


			}

		}
	}
	//For Isosceles Triangle
	else if (shape == "2")
	{
		{
			//Isosceles Triangle solid
			for (int row = 1; row <= dim && kind == 's'; row++)
			{
				//column number less than the highest column number of row with max characters 
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{

					if (col >= dim - (row - 1) && col <= dim + (row - 1))
						cout << ch;
					else
						cout << space;

				}
				cout << endl;
			}
			//Isosceles Triangle hollow 
			for (int row = 1; row <= dim && kind == 'h'; row++)
			{
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{
					if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
						cout << ch;
					else
						cout << space;

				}
				cout << endl;
			}
			//Isosceles  Triangle both 
			if (kind == 'b')
			{
				//Isosceles Triangle solid in both
				for (int row = 1; row <= dim; row++)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col >= dim - (row - 1) && col <= dim + (row - 1))
							cout << ch;
						else
							cout << space;

					}
					cout << endl;
				}
				//Isosceles Triangle hollow  in both
				for (int row = 1; row <= dim; row++)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
							cout << ch;
						else
							cout << space;

					}
					cout << endl;
				}

			}

		}
	}

	//For Diamond
	//In case of diamond two isosceles triangles are used 
	//One is normal while other is inverted 
	//in case of odd no of rows an additional row is added after the normal isosceles triangle i.e upper part of diamond 

	else if (shape == "3")
	{
		//For diamond solid 

		//upper part of diamond
		for (int row = 1; row <= ((dim / 2) + 1) && kind == 's'; row++)
		{
			//for even amount of rows
			if (row <= dim / 2)
			{
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{
					if (col >= dim - (row - 1) && col <= dim + (row - 1))
						cout << ch;
					else
						cout << space;
				}
				cout << endl;
			}
			//for odd no of rows a row is added in the upper part od diamond 
			else if (dim % 2 != 0 && row == (dim / 2) + 1)
			{
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{
					if (col >= dim - (row - 1) && col <= dim + (row - 1))
						cout << ch;
					else
						cout << space;
				}
				cout << endl;
			}
		}
		//lower part of diamond 
		for (int row = dim / 2; row >= 1 && kind == 's'; row--)
		{
			for (int col = ((dim * 2) - 1); col >= 1; col--)
			{
				if (col >= dim - (row - 1) && col <= dim + (row - 1))
					cout << ch;
				else
					cout << space;
				;

			}
			cout << endl;
		}
		//For Hollow
			//upper part of diamond
		for (int row = 1; row <= ((dim / 2) + 1) && kind == 'h'; row++)
		{
			//for even no of rows 
			if (row <= dim / 2)
			{
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{
					if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
						cout << ch;
					else
						cout << space;

				}
				cout << endl;
			}
			//for odd no of rows a row is added in the upper part od diamond 
			else if (dim % 2 != 0 && row == (dim / 2) + 1)
			{
				for (int col = 1; col <= ((dim * 2) - 1); col++)
				{
					if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
						cout << ch;
					else
						cout << space;

				}
				cout << endl;
			}
		}
		//lower part of diamond 
		for (int row = dim / 2; row >= 1 && kind == 'h'; row--)
		{
			for (int col = ((dim * 2) - 1); col >= 1; col--)
			{
				{
					if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
						cout << ch;
					else
						cout << space;

				}

			}
			cout << endl;
		}
		if (kind == 'b')
		{
			//For diamond solid in both

	//upper part of diamond
			for (int row = 1; row <= ((dim / 2) + 1); row++)
			{
				if (row <= dim / 2)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col >= dim - (row - 1) && col <= dim + (row - 1))
							cout << ch;
						else
							cout << space;
					}
					cout << endl;
				}
				//additional row in case of odd number of rows
				else if (dim % 2 != 0 && row == (dim / 2) + 1)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col >= dim - (row - 1) && col <= dim + (row - 1))
							cout << ch;
						else
							cout << space;
					}
					cout << endl;
				}
			}
			//lower part of diamond 
			for (int row = dim / 2; row >= 1; row--)
			{
				for (int col = ((dim * 2) - 1); col >= 1; col--)
				{
					if (col >= dim - (row - 1) && col <= dim + (row - 1))
						cout << ch;
					else
						cout << space;
					;

				}
				cout << endl;
			}
			//to seperate hollow and solid diamond 
			cout << endl;

			//For Hollow in both
				//upper part of diamond
			for (int row = 1; row <= ((dim / 2) + 1); row++)
			{
				if (row <= dim / 2)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
							cout << ch;
						else
							cout << space;

					}
					cout << endl;
				}
				//additional row in case if odd no of rows
				else if (dim % 2 != 0 && row == (dim / 2) + 1)
				{
					for (int col = 1; col <= ((dim * 2) - 1); col++)
					{
						if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
							cout << ch;
						else
							cout << space;

					}
					cout << endl;
				}
			}
			//lower part of diamond 
			for (int row = dim / 2; row >= 1 && kind; row--)
			{
				for (int col = ((dim * 2) - 1); col >= 1; col--)
				{
					{
						if (col == dim - (row - 1) || col == dim + (row - 1) || row == dim)
							cout << ch;
						else
							cout << space;

					}

				}
				cout << endl;
			}

		}



	}

	//for square

	else if (shape == "4")

	{



		//Square solid 
		for (int row = 1; row <= dim && kind == 's'; row++)
		{
			for (int c2 = 1; c2 <= dim; c2++)
			{
				cout << ch;
			}
			cout << endl;

		}
		//Square hollow 
		for (int row = 1; row <= dim && kind == 'h'; row++)
		{
			for (int col = 1; col <= dim; col++)
			{
				if (col == 1 || col == dim || row == dim || row == 1)
					cout << ch;
				else
					cout << space;
			}

			cout << endl;
		}


		//Square both 
		if (kind == 'b')
		{
			//Square solid in both 
			for (int row = 1; row <= dim; row++)
			{
				for (int col = 1; col <= dim; col++)
				{
					cout << ch;
				}
				cout << endl;

			}
			//for seperation between solid and hollow shape
			cout << endl;
			//Square hollow in both 
			for (int row = 1; row <= dim; row++)
			{
				for (int col = 1; col <= dim; col++)
				{
					if (col == 1 || col == dim || row == dim || row == 1)
						cout << ch;
					else
						cout << space;
				}

				cout << endl;

			}

		}
	}
	//Rectangle 
	else if (shape == "5")

	{

		//Rectangle solid 
		for (int row = 1; row <= 6 && kind == 's'; row++)
		{
			for (int col = 1; col <= dim; col++)
			{
				cout << ch;
			}
			cout << endl;

		}

		//Rectangle hollow 
		for (int row = 1; row <= 6 && kind == 'h'; row++)
		{
			for (int col = 1; col <= dim; col++)
			{
				if (col == 1 || col == dim || row == 6 || row == 1)
					cout << ch;
				else
					cout << space;
			}

			cout << endl;

		}
		//Rectangle both 
		if (kind == 'b')
		{
			//Rectangle solid 
			for (int row = 1; row <= 6; row++)
			{
				for (int col = 1; col <= dim; col++)
				{
					cout << ch;
				}
				cout << endl;

			}
			//for seperation between solid and hollow shape
			cout << endl;
			//Rectangle hollow 
			for (int row = 1; row <= 6; row++)
			{
				for (int col = 1; col <= dim; col++)
				{
					if (col == 1 || col == dim || row == 6 || row == 1)
						cout << ch;
					else
						cout << space;
				}

				cout << endl;

			}
		}

	}
	else if (shape == "6")

		//For parallelogram 

	{
		//Parallelogram Solid
		for (int row = 1, n = 6; row <= 6 && kind == 's'; row++, n--)
		{
			for (int col = 1; col <= dim; col++)
			{
				if (col == 1)
				{
					cout << setw(n) << ch;
				}
				else
				{
					cout << ch;
				}
			}
			cout << endl;

		}
		//Parallelogram hollow 
		for (int row = 1, n = 6; row <= 6 && kind == 'h'; row++, n--)
		{
			for (int col = 1; col <= dim; col++)
			{
				if (col == 1)
				{
					cout << setw(n) << ch;
				}
				else if (col == dim || row == 6 || row == 1)
					cout << ch;
				else
					cout << space;
			}

			cout << endl;

		}
		//parallelogram both
		if (kind == 'b')
		{
			//Parallelogram Solid in both
			for (int row = 1, n = 6; row <= 6; row++, n--)
			{
				for (int col = 1; col <= dim; col++)
				{
					if (col == 1)
					{
						cout << setw(n) << ch;
					}
					else
					{
						cout << ch;
					}
				}
				cout << endl;

			}

			//for seperation between solid and hollow shape
			cout << endl;
			//Parallelogram hollow in both
			for (int row = 1, n = 6; row <= 6; row++, n--)
			{
				for (int col = 1; col <= dim; col++)
				{
					if (col == 1)
					{
						cout << setw(n) << ch;
					}
					else if (col == dim || row == 6 || row == 1)
						cout << ch;
					else
						cout << space;
				}

				cout << endl;

			}


		}



	}
	

		
		
	
	
 

		return 0;
}


