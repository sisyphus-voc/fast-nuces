#include <iostream>
#include <string>
using namespace std;


class Computer
{
private:
	string companyName;
	int price;
public:
	Computer()
	{
		companyName = ' ';
		price = 0;
	}

	Computer(string c, int p)
	{
		companyName =c;
		price = p;
	}
	virtual void show() = 0;
};

class Desktop:public Computer
{
	string color,processor_type;
	int monitor_size;
	
public:
	Desktop():Computer()
	{
		monitor_size = 0;
	}
	Desktop(string c, int p, string co, string pt, int ms) :Computer(c, p)
	{
		color = co;
		processor_type = pt;
		monitor_size = ms;
	}

	void show()
	{
		cout << "Color : " << color << "\nProcessor Type : " << processor_type << "\n Monitor Size : " << monitor_size << endl;
	}

};

class Laptop :public Computer
{
	string color, processor_type,size;
	int weight;

public:
	Laptop():Computer()
	{
		weight=0;

	}
	Laptop(string c, int p, string co, string pt, int w,string s) :Computer(c, p)
	{
		color = co;
		processor_type = pt;
		weight = w;
		size = s;
	}

	void show()
	{
		
		cout << "Color : " << color << "\nProcessor Type : " << processor_type << "\n Weight : " << weight<<"g" << "\nSize : " << size << endl;
	}

};


int main()
{

	cout << "\nLaptop\n";
	Laptop Mylaptop("Asus", 150000, "Black", "Intel", 400, "16'");
	Mylaptop.show();
	cout << "\nDesktop\n";
	Desktop MyDesktop("Hp", 100000, "White", "AMD", 30);
	MyDesktop.show();
}
