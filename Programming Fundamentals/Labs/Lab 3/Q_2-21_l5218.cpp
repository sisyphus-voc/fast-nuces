//Post Lab 3
//Q no.2
//Name : Abdul Raheem
//Roll no: 21L-5218
//Section : BCS-1N1

#include <iostream>
using namespace std;
int main()
{
	//Decleration of variables. 

	int a,f1,f2,t1,t2,o=1000000000;

	//Taking input from user.

	cout << "Enter the amount your brother has asked : ";
	cin >> a;
	cout << "Enter the amount of 5 rupee coins you have : ";
	cin >> f1;
	cout << "Enter the amount of 2 rupee coins : ";
	cin >> t1;

	//calculating the 5rs, 2rs and 1rs coins you have to give to your brother.

	f2=a / 5;
	t2 =((a - f2 * 5) / 2);
	o = a - (t2 * 2 + f2 * 5);

 //If you have the 5rs coins you have to give your brother.

	if (f2 <= f1)
	{
		cout << "Number of 5 rupee coins to bro = " << f2 << endl;

		//If you have the amount of 2rs coins you have to give your brother.

		if (t2 <= t1)
		{
			cout << "Number of 2 rupee coins to bro = " << t2 << endl;
			cout << "Number of 1 rupee coins to bro = " << o << endl;
		}

		//If you don't have enough 2rs coins compared to required 2rs coins.

		else if (t2>t1)

		{
			cout << "Number of 2 rupee coins to bro = " << t1 << endl;
			//calculating number of 1rs coins you have to give to your brother.
			o = a - (t1 * 2 + f2 * 5);
			cout << "Number of 1 rupee coins to bro = " << o << endl;
			

		}

	}
	//If you don't have enough 5rs coins compared to required 5rs coins.

	else if (f2>f1)
	{
		cout << "Number of 5 rupee coins to bro = " << f1 << endl;
		//calculating number of 2rs coins you have to give to your brother.
		t2 = ((a - f1 * 5) / 2);

		//If you have the amount of 2rs coins you have to give your brother.
		if (t2 <= t1)
		{

			cout << "Number of 2 rupee coins to bro = " << t2 << endl;
			//calculating number of 1rs coins you have to give to your brother.
			o = a - (t2 * 2 + f1 * 5);
			cout << "Number of 1 rupee coins to bro = " << o << endl;
		}
		//If you don't have enough 2rs coins compared to required 2rs coins.

		else if (t2>t1)
		{
			//calculating number of 2rs coins you have to give to your brother.
			t2 = ((a - f1 * 5) / 2);
			cout << "Number of 2 rupee coins to bro = " << t1 << endl;
			//calculating number of 1rs coins you have to give to your brother.
			o = a - (t1 * 2 + f1 * 5);
			cout << "Number of 1 rupee coins to bro = " << o << endl;
		}
	}
	
	return 0;



 
}
