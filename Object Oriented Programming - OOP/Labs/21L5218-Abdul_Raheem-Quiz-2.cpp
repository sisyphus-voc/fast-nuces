#include <iostream>
#include <string>
using namespace std;

class Month
{
private:
	string name;
	int monthNumber;
public:
	Month()
	{
	
	name="January";
	monthNumber=1;
	}

	Month(string n)
	{
		name =n;
		
	if(name=="January")
	{
		monthNumber=1;
	}
	else if(name=="Feburary")
	{
		monthNumber=2;
	}
	else if(name=="March")
	{
		monthNumber=3;
	}
	else if(name=="April")
	{
		monthNumber=4;

	}
	else if(name=="May")
	{
		monthNumber=5;
	}
	else if(name=="June")
	{
		monthNumber=6;
	}
	else if(name=="July")
	{
		monthNumber=7;
	}
	else if(name=="August")
	{
		monthNumber=8;
	}
	else if(name=="September")
	{
		monthNumber=9;
	}
	else if(name=="October")
	{
		monthNumber=10;
	}
	else if(name=="November")
	{
		monthNumber=11;
	}
	else if(name=="December")
	{
		monthNumber=12;
	}
	}

	Month(int mn)
	{
	monthNumber=mn;
	if(monthNumber==1)
	{
		name="January";
		
	}
	else if(monthNumber==2)
	{
		name="Feburary";
	}
	else if(monthNumber==3)
	{
		name="March";
	}
	else if(monthNumber==4)
	{
		
		name="April";
	}
	else if(monthNumber==5)
	{
		name="May";
	}
	else if(monthNumber==6)
	{
		
		name="June";
	}
	else if(monthNumber==7)
	{
		
		name="July";
	}
	else if(monthNumber==8)
	{
		
		name="August";
	}
	else if(monthNumber==9)
	{
		
		name="September";
	}
	else if(monthNumber==10)
	{
		
		name="October";
	}
	else if(monthNumber==11)
	{
		
		name="November";
	}
	else if(monthNumber==12)
	{
		
		name="December";
	}
	}
	//setters
	void SetMonthName(string n)
	{
		name =n;

	}
	void SetMonthNumber(int mn)
	{
		monthNumber=mn;
	}
	//getters
	string GetMonthName()
	{
		return name;
	}
	int GetMonthNumber()
	{
		return monthNumber;
	}
	friend Month operator++(Month& newMonth);
	friend Month operator++(Month& newMonth,int x);
		friend Month operator--(Month& newMonth);
	friend Month operator--(Month& newMonth,int x);
};
Month operator++(Month& newMonth)
{
	
	int mn;
	mn=newMonth.GetMonthNumber();
	++mn;
	Month M1(mn);
return M1;

	
	
}
Month operator++(Month& newMonth,int x)
{
	int mn;
	mn=newMonth.GetMonthNumber();
	mn+=x;
	Month M1(mn);
return M1;
}

Month operator--(Month& newMonth)
{
	
	int mn;
	mn=newMonth.GetMonthNumber();
	--mn;
	Month M1(mn);
return M1;

	
	
}
Month operator--(Month& newMonth,int x)
{
	int mn;
	mn=newMonth.GetMonthNumber();
	mn-=x;
	Month M1(mn);
return M1;
}

int main()

{

	Month M1;
	cout<<M1.GetMonthName()<<"\t"<<M1.GetMonthNumber()<<endl;

	string mName="Feburary";
	Month M2(mName);
	cout<<M2.GetMonthName()<<"\t"<<M2.GetMonthNumber()<<endl;
	Month M3(9);
	cout<<M3.GetMonthName()<<"\t"<<M3.GetMonthNumber()<<endl;
	M3.SetMonthName("January");
	M3.SetMonthNumber(1);
	cout<<M3.GetMonthName()<<"\t"<<M3.GetMonthNumber()<<endl;

	++M3;
	cout<<M3.GetMonthName()<<"\t"<<M3.GetMonthNumber()<<endl;
	M3++;
	cout<<M3.GetMonthName()<<"\t"<<M3.GetMonthNumber()<<endl;

	--M2;
	cout<<M2.GetMonthName()<<"\t"<<M2.GetMonthNumber()<<endl;
	M2--;
	cout<<M2.GetMonthName()<<"\t"<<M2.GetMonthNumber()<<endl;
	system("pause");
	return 0;
	
}