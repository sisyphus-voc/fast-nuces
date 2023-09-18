#include <iostream>

using namespace std;

class Date 
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date()
	{
		Day = 1;
		Month = 1;
		Year = 1926;
		cout << "Default Constructor Called\n";
	}
	Date(int d, int m, int y)
	{
		Day = d;
		Month = m;
		Year = y;
		cout << "Overloaded Constructor Called\n";

	}
	Date(const Date& newDate)
	{
		Day = newDate.Day;
		Month = newDate.Month;
		Year = newDate.Year;
		
	}

	
	
	void SetDay(int d)
	{
		Day = d;
	}
	void SetMonth(int m)
	{
		Month = m;
	}
	void SetYear(int y)
	{
		Year = y;
	}

	int GetDay()
	{
		return Day;
	}
	int GetMonth()
	{
		return Month;
	}
	int GetYear()
	{
		return Year;
	}

	void Input()
	{
		cout << "Enter Date: (dd/mm/yyyy)\n";
		cin >> Day;
		cin.ignore();
		cin >> Month;
		cin.ignore();
		cin >> Year;
	}
	void Print()
	{
		cout << Day << "/" << Month << "/" << Year << endl;
	}
	int Compare(const Date& newDate)
	{
		int compare = -2;

		if (Year > newDate.Year)
		{
			cout << "greater ";
			compare = 1;
		}
		else if (Month > newDate.Month && Year == newDate.Year)
		{
			cout << "greater ";
			compare = 1;
		}

		else if (Day > newDate.Day && Month == newDate.Month && Year == newDate.Year)
		{
			cout << "greater ";
			compare = 1;
		}


		else if (Year < newDate.Year)
		{
			cout << "smaller ";
			compare = -1;
		}
		else if (Month < newDate.Month && Year == newDate.Year)
		{
			cout << "smaller ";
			compare = -1;
		}
		else if (Day < newDate.Day && Month == newDate.Month && Year == newDate.Year)
		{
			cout << "smaller ";
			compare = -1;
		}


		else if (Day == newDate.Day && Month == newDate.Month && Year == newDate.Year)
		{
			cout << "equal ";
			compare=0;
		}
		return compare;
	}
	Date IncrementMonth()
	{
		Date IncrementedDate;

		if (Month == 12)
		{
			IncrementedDate.Day = Day;
			IncrementedDate.Month = 1;
			IncrementedDate.Year = Year+1;
		}
		else
		{
			IncrementedDate.Day = Day;
			IncrementedDate.Month = Month + 1;
			IncrementedDate.Year=Year;
		}
		return IncrementedDate;

	}

	~Date()
	{
		cout << "Destructor Called\n";
	}
};


int main()
{
	//Exercise 1, 2 & 3
	Date date1;
	cout << "Date 1 : ";
	date1.Print();

	//Exercise 4
	Date inpendanceDay(14, 8, 2018);
	cout << "Independance Day :";
	inpendanceDay.Print();

	//Exercise 5, 6
	date1.Input();
	cout << "Date 1 : ";
	date1.Print();

	//Exercise 7
	Date xmasDay;
	cout << "Xmas : ";
	xmasDay.Print();
	xmasDay.SetDay(25);
	xmasDay.SetMonth(12);
	xmasDay.SetYear(2018);

	//Exercise 8
	cout <<"Xmas : " << xmasDay.GetDay() << "/" << xmasDay.GetMonth() << "/" << xmasDay.GetYear() << endl;

	//Exercise 9
	Date temp;
	temp = xmasDay;
	cout << "temp : ";
	temp.Print();

	//Exercise 10
	int compare = -2;
	compare = date1.Compare(inpendanceDay);
	cout << "\n\n\n\Compare = " << compare << endl<<endl<<endl;

	//Exercise 11
	Date date2=date1.IncrementMonth();
	cout << "Incremented Date : ";
	date2.Print();

	return 0;

}