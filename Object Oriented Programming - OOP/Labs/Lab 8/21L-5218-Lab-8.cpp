#include <iostream>

using namespace std;

class rectangleType
{
	friend ostream& operator<<(ostream&, const rectangleType&);
	friend istream& operator>>(istream&, rectangleType&);

	friend rectangleType operator+(const rectangleType&, const rectangleType&);
	friend rectangleType operator-(const rectangleType&, const rectangleType&);
	friend rectangleType operator*(const rectangleType&, const rectangleType&);
	friend rectangleType operator/(const rectangleType&, const rectangleType&);

	//pre increment
	friend rectangleType operator++(rectangleType&);
	//post increment
	friend rectangleType operator++(rectangleType&,int);

	//pre decrement
	friend rectangleType operator--(rectangleType&);
	//post decrement
	friend rectangleType operator--(rectangleType&, int);

	friend bool operator==(const rectangleType&, const rectangleType&);
	friend bool operator!=(const rectangleType&, const rectangleType&);
	friend bool operator<=(const rectangleType&, const rectangleType&);
	friend bool operator<(const rectangleType&, const rectangleType&);
	friend bool operator>=(const rectangleType&, const rectangleType&);
	friend bool operator>(const rectangleType&, const rectangleType&);
private:
	double length;
	double width;
public:
	rectangleType()
	{
		length = 0.0;
		width = 0.0;
	}
	rectangleType(double l,double w)
	{
		length = l;
		width = w;
	}
	void setDimension(double l, double w)
	{
		length = l;
		width = w;
	}

	double getLength()const
	{
		return length;
	}
	double getWidth()const
	{
		return width;
	}
	double area()const
	{
		double area = 0.0;
		area = length * width;
		return area;
	}
	double perimeter()const
	{
		double perimeter = 0.0;
		perimeter = (2*length) + (2*width);
		return perimeter;
	}



};
ostream& operator<<(ostream&, const rectangleType& newRectangle)
{
	cout << "Length : " << newRectangle.getLength()<<endl;
	cout << "Width : " << newRectangle.getWidth() << endl;
	cout << "Area : " << newRectangle.area() << endl;
	cout << "Perimeter : " << newRectangle.perimeter() << endl;
	return cout;
}
istream& operator>>(istream&, rectangleType& newRectangle)
{
	double l = 0.0, w = 0.0;

	cout << "Enter Length : ";
	cin >> l;
	cout << "Enter Width : ";
	cin >> w;
	newRectangle.setDimension(l, w);
	return cin;
}

rectangleType operator+(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	rectangleType rectangleC;
	double l = 0.0, w = 0.0;
	l = rectangleA.getLength() + rectangleB.getLength();
	w = rectangleA.getWidth() + rectangleB.getWidth();

	rectangleC.setDimension(l,w);

	return rectangleC;

}

rectangleType operator-(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	rectangleType rectangleC;
	double l = 0.0, w = 0.0;
	if (rectangleA < rectangleB)
	{
		cout << "Invalid Subtraction values: Length and width ends up being negative\n";
	}
	else
	{
		l = rectangleA.getLength() - rectangleB.getLength();
		w = rectangleA.getWidth() - rectangleB.getWidth();

		rectangleC.setDimension(l, w);
	}

	return rectangleC;
}
rectangleType operator*(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	rectangleType rectangleC;
	double l = 0.0, w = 0.0;
	l = rectangleA.getLength() * rectangleB.getLength();
	w = rectangleA.getWidth()  *rectangleB.getWidth();

	rectangleC.setDimension(l, w);

	return rectangleC;
}
rectangleType operator/(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	rectangleType rectangleC;
	double l = 0.0, w = 0.0;
	l = rectangleA.getLength()/rectangleB.getLength();
	w = rectangleA.getWidth() /rectangleB.getWidth();

	rectangleC.setDimension(l, w);

	return rectangleC;
}

//pre increment
rectangleType operator++(rectangleType& newRectangle)
{
	rectangleType temp;
	double l = 0.0, w = 0.0;

	l = newRectangle.getLength();
	w = newRectangle.getWidth();
	temp.setDimension(++l,++w);
	return temp;
}
//////post increment
rectangleType operator++(rectangleType& newRectangle,int x)
{
	rectangleType temp;
	double l = 0.0, w = 0.0;

	l = newRectangle.getLength();
	w = newRectangle.getWidth();
	temp.setDimension(l+=x, w+=x);
	return temp;

}

//pre decrement
rectangleType operator--(rectangleType& newRectangle)
{
	rectangleType temp;
	double l = 0.0, w = 0.0;

	l = newRectangle.getLength();
	w = newRectangle.getWidth();
	temp.setDimension(--l , --w );
	return temp;
}
//post decrement
 rectangleType operator--(rectangleType& newRectangle,int x)
{
	rectangleType temp;
	double l = 0.0, w = 0.0;

	l = newRectangle.getLength();
	w = newRectangle.getWidth();
	temp.setDimension(l-=x, w-=x);
	return temp;
}

bool operator==(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area()==rectangleB.area())
	{
		return true;
	}
	else
		return false;


}
bool operator!=(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area() != rectangleB.area())
	{
		return true;
	}
	else
		return false;


}

bool operator<=(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area() <= rectangleB.area())
	{
		return true;
	}
	else
		return false;


}
bool operator<(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area() < rectangleB.area())
	{
		return true;
	}
	else
		return false;


}
bool operator>=(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area() >= rectangleB.area())
	{
		return true;
	}
	else
		return false;


}
bool operator>(const rectangleType& rectangleA, const rectangleType& rectangleB)
{
	if (rectangleA.area() > rectangleB.area())
	{
		return true;
	}
	else
		return false;


}



int main()
{
	//to check constructors
	rectangleType R1;
	rectangleType R2(5, 6);

	cin >> R1;
	cout << "\n\nR1 : \n" << R1;

	rectangleType R3 = R2 + R1;
	cout << "\n\nR3 : \n" << R3;

	rectangleType R4 = R2 - R1;
	cout << "\n\nR4 : \n" << R4;

	rectangleType R5 = R2 * R1;
	cout << "\n\nR5 : \n" << R5;

	rectangleType R6 = R2 / R1;
	cout << "\n\nR6 : \n" << R6;

	cout << "\n\n++R6 : \n" << ++R6;
	cout << "\n\nR6++ : \n" << R6++;

	cout << "\n\n--R6 : \n" << --R6;
	cout << "\n\nR6-- : \n" << R6--;

	rectangleType R7(4, 6),R8(4,6),R9(6,7);
	
	cout << "\n\nR7 : \n" << R7;
	cout << "\n\nR8 : \n" << R8;
	cout << "\n\nR9 : \n" << R9;

	if (R7 == R8)
	{
		cout << "R7 and R8 are equal\n";
	}
	else
		cout << "R7 and R8 are not equal\n";
	if (R7 != R9)
	{
		cout << "R7 and R9 are not equal\n";
	}
	if (R9 > R8)
	{
		cout << "R9 is greater than R8\n";
	}
	if (R9 >= R8)
	{
		cout << "R9 is greater than equal to R8\n";
	}
	if (R8 < R9)
	{
		cout << "R8 is less than R9\n";
	}
	if (R8 <= R9)
	{
		cout << "R8 is less than equal to R9\n";
	}










}	
