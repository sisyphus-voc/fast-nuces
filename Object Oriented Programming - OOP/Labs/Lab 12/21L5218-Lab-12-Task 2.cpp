//#include <iostream>
//#include <string>
//using namespace std;
//
//
//
////Exercise-2
//
//class tornadoException
//{
//public:
//	const char* what()
//	{
//		return "Tornado : Take cover immediately!";
//	}
//	string what(int m)
//	{
//
//		string temp1 = to_string(m);
//
//		string temp;
//		temp = "Tornado: " + temp1;
//		temp += " miles away; and approaching!";
//		return temp;
//	}
//	tornadoException()
//	{
//		cout << what() << endl;
//	}
//	tornadoException(int m)
//	{
//
//		cout << what(m) << endl;
//
//	}
//};
//
//int main()
//{
//	tornadoException t1;
//	tornadoException t2(5);
//
//}