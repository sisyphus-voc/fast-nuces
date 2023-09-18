#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:

	Point(int a=0, int b=0)
	{
		cout << "Point() called\n";
		x = a, y = b;
	}
	void Print()
	{
		cout << "(" << x << "," << y << ")\n";
	}
	~Point()
	{
		cout << "~Point() called\n";
	}
};
class Style
{
private:
	char color[10];
	bool isFilled;
public:
	Style()
	{
		const char c[] = "null";
		strcpy_s(color, c);
		isFilled = false;
	}
	Style(const char c[], bool Isf)
	{
		cout << "Style() called\n";
		strcpy_s(color, c);
		isFilled = Isf;

	}
	void SetColor(const char c[])
	{
		strcpy_s(color, c);
	}
	void SetFilled(bool Isf)
	{

		isFilled = Isf;
	}
	char* GetColor()
	{
		return color;
	}
	bool GetFilled()
	{
		return isFilled;
	}
	void Print()
	{
		cout << "Color : " << color<<endl;
		cout << "IsFilled : " << isFilled << endl;
	}
	~Style()
	{
		cout << "~Style() called\n";
	}

};

class Circle
{
private:
	Point center;
	float radius;
	Style* st;

public:
	Circle()
	{
		
		radius = 0.0;
		st = NULL;
	}
	Circle(int a, int b, float r) :center(a, b)
	{
		 
		cout << "Circle() called\n";
		radius = r;

	}
	void SetStyle(Style* s)
	{

		st = s;

	}
	void SetColor(const char c[])
	{
		st->SetColor(c);
	}
	void SetFilled(bool isf)
	{
		st->SetFilled(isf);
	}

	void Print()
	{
		center.Print();
		cout << "Radius : "<<radius<<endl;
		
		st->Print();
	}
	~Circle()
	{
		cout << "~Circle() called\n";

	}
};


int main()
{
	//Circle c(3, 4, 2.5);
	//c.Print();

	///output
//	Point() called
//		Circle() called
//		(3, 4)
//		Radius : 2.5
//		~Circle() called
//		~Point() called
//



	Style style1("Blue",true);
	Circle circle1(3,4,2.5);
	circle1.SetStyle(&style1);
	circle1.Print();

	//output
	/*Style() called
Point() called
Circle() called
(3,4)
Radius : 2.5
Color : Blue
IsFilled : 1
~Circle() called
~Point() called
~Style() called*/
	return 0;
}