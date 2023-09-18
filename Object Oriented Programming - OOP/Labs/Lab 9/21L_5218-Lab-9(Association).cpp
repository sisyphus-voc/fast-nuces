//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Student
//{
//private:
//	char name[50];
//	char rollno[8];
//	float cgpa;
//
//public:
//	Student()
//	{
//		const char n[] = "Aslam Baig";
//		const char r[] = "12L9356";
//		strcpy_s(name, n);
//		strcpy_s(rollno, r);
//		cgpa = 0.0;
//
//	}
//	Student(const char r[],const char n[],float c)
//	{
//		strcpy_s(name, n);
//		strcpy_s(rollno, r);
//		cgpa = c;
//	}
//	void SetRollNo(const char r[])
//	{
//		strcpy_s(rollno, r);
//	}
//	void SetName(const char n[])
//	{
//		strcpy_s(name, n);
//	}
//	void SetCGPA(float c)
//	{
//		cgpa = c;
//	}
//	char* GetName()
//	{
//		return name;
//	}
//	char* GetRollNo()
//	{
//		return rollno;
//	}
//	float GetCGPA()
//	{
//		return cgpa;
//	}
//
//
//
//
//
//	void  Print()
//	{
//		cout << name << "(" << rollno << ")\n";
//	}
//	//we dont need a destructor bcz no memory has been allocated on heap
//
//
//};
//class Society
//{
//private:
//	char name[50];
//	Student* president;
//public:
//	Society()
//	{
//		const char n[] = "Society # 1";
//		strcpy_s(name, n);
//		president = NULL;
//	
//	}
//	Society(const char n[])
//	{
//
//		strcpy_s(name, n);
//		
//	}
//	void AppointPresident(Student &Pr)
//	{
//		if (Pr.GetCGPA() > 3.0 && president == 0)
//		{
//			
// 			president = &Pr;
//			cout << Pr.GetName() << " has been appointed as President\n";
//		}
//		else if (Pr.GetCGPA() < 3.0)
//		{
//			cout << Pr.GetName() << " cannot be appointed as President. CGPA criteria not met.\n";
//		}
//		else if (president != 0)
//		{
//			cout << Pr.GetName() << " cannot be appointed as President.President Position is not vacant.\n";
//		}
//
//	}
//	void PrintInfo()
//	{
//		cout << "Society Name : " << name << "\n";
//		if (president != 0)
//		{
//			president->Print();
//		}
//		else
//		{
//			cout << "President: \tNot Available\n";
//		}
//	}
//
//
//};
//
//
//int main()
//{
//	Student s0;
//	Student s1("12L1111", "Hashim Amla", 3.99);
//	Student s2("13L1121", "Virat Kohli", 3.45);
//	Student s3("13L1126", "Quinten de Kock",2.98);
//	Student s4("14L1361", "Joe Root", 2.99);
//	Student s5("14L1124", "Martin Guptil", 3.09);
//	Student s6("15L1314", "Rohit Sharma", 3.19);
//	s0.Print();
//
//	s1.Print();
//	s2.Print();
//	s3.Print();
//	s4.Print();
//	s5.Print();
//	s6.Print();
//
//	Society s10;
//	s10.PrintInfo();
//
//	Society sports("sports");
//	sports.PrintInfo();
//
//	sports.AppointPresident(s1);
//	sports.AppointPresident(s2);
//	sports.AppointPresident(s3);
//
//	return 0;
//}