


/*Note:
I did all the templates and mains in 1 file and labeled them u can check them
by uncommenting them one by one along with their respective templates and int main
*/


#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////Template for exercise 1 a- c

//template <class T> T GetMax(T x, T y)
//{
//	if (x > y)
//	{
//		return x;
//	}
//	else if (x < y)
//	{
//		return y;
//	}
//}
//template <class T> T GetMin(T x, T y)
//{
//	if (x < y)
//	{
//		return x;
//	}
//	else if (x > y)
//	{
//		return y;
//	}
//}

////////////////////////////////////////////////////////////////Template for exercise 1 d and 1 e

//template <class T,class U> T GetMax(T x, U y)
//{
//	if (x > y)
//	{
//		return x;
//	}
//	else if (x < y)
//	{
//		return y;
//	}
//}
//template <class T, class U> T GetMin(T x, U y)
//{
//	if (x < y)
//	{
//		return x;
//	}
//	else if (x > y)
//	{
//		return y;
//	}
//}

/////////////////////////////////////////////////////////////////////Template for Exercise 2
// 

//template <typename T> class Pair
//{
//private:
//	T values[2];
//public:
//	Pair()
//	{
//		values = 0;
//	}
//	Pair(T x, T y)
//	{
//		values[0] = x;
//		values[1] = y;
//	}
//	T GetMax()
//	{
//		if (values[0] > values[1])
//		{
//			return values[0];
//		}
//		else if (values[0] < values[1])
//		{
//			return values[1];
//		}
//	}
//	T GetMin();
//};
//template <typename T> T Pair <T>::GetMin()
//{
//
//	if (values[0] < values[1])
//	{
//		return values[0];
//	}
//	else if (values[0] > values[1])
//	{
//		return values[1];
//	}
//
//}
////////////////////////////////////////////////////////////////////////Template for Exercise 3
//
//template<class t>
//class container
//{
//	t data;
//public:
//	container(t x) {
//		data = x;
//	}
//	t increase() {
//
//		data++;
//		return data;
//	}
//};
//template<>
//class container <char>
//{
//	char data;
//
//
//
//public:
//	container(char x) {
//		data = x;
//
//	}
//	char uppercase() {
//		if(data>=97&&data<=122)
//		data = data - 32;
//		return data;
//	}
//};

//////////////////////////Mains begin here ///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////Exercise 1 b

//int main()
//{
//	int i = 5, j = 6, k;
//	long l = 10, m = 5, n;
//	k = GetMax<int>(i, j);
//	n = GetMin<long>(l, m);
//	cout << k << endl;
//	cout << n << endl;
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////Exercise 1c


//int main()
//{
//	int i = 5, j = 6, k;
//	long l = 10, m = 5, n;
//	k = GetMax(i, j);
//	n = GetMin(l, m);
//	cout << k << endl;
//	cout << n << endl;
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////Exercise 1   d


//// as char has been passed through int parameter it considers its ascii value
//int main()
//{
//	char i = 'Z';
//	int j = 6, k;
//	long l = 10, m = 5, n;
//	k = GetMax<int, long>(i, m);
//	n = GetMin<int, char>(j, l);
//	cout << k << endl;
//	cout << n << endl;
//
//	return 0;
//}


//////////////////////////////////////////////////////////////////Exercise 1  e
//int main()
//{
//	char i = 'Z';
//	int j = 6, k;
//	long l = 10, m = 5, n;
//	k = GetMax(i, m);
//	n = GetMin(j, l);
//	cout << k << endl;
//	cout << n << endl;
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////Exercise 2

//int main()
//{
//	Pair <double> myobject(1.012, 1.01234);
//	cout << myobject.GetMax();
//	return 0;
//}
//

//////////////////////////////////////////////////////////////////Exercise 3

//int main()
//{
//	container <int> myint(7);
//	container <char> mychar('j');
//	cout << myint.increase() << endl;
//	cout << mychar.uppercase() << endl;
//	return 0;
//}

