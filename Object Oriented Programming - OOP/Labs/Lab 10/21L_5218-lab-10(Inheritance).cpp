#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;

class Person
{
private:
	char* first_name;
	char* last_name;
protected:
	int age;
public:
	Person()
	{
		cout << "Person() Called\n";
		first_name = 0;
		last_name = 0;
		age = 0;
	}
	Person(const char fname[],const char lname[], int a)
	{
		cout << "Person() Called\n";
		int size_f = 0, size_l = 0;
		size_f = strlen(fname) + 1;
		size_l = strlen(lname) + 1;

		first_name = new char[size_f];
		last_name = new char[size_l];
		strcpy(first_name, fname);
		strcpy(last_name, lname);
		first_name[size_f - 1] = '\0';
		last_name[size_l - 1] = '\0';

		age = a;
	


	}
	void SetFirstName(const char fname[])
	{
		int size_f = 0;
		size_f = strlen(fname) + 1;
		first_name = new char[size_f];
		strcpy(first_name, fname);
		first_name[size_f] = '\0';
	}

	void SetLastName(const char lname[])
	{
		int  size_l = 0;
		size_l = strlen(lname) + 1;
		last_name = new char[size_l];
		strcpy(last_name, lname);
		last_name[size_l - 1] = '\0';

		
	}
	void SetAge(int a)
	{
		age = a;
	}
	char* GetFirstName()
	{
		return first_name;
	}
	char* GetLastName()
	{
		return last_name;
	}
	int GetAge()
	{
		return age;
	}

	void PrintInformation()
	{
		cout << first_name << " " << last_name << " is " << age << " years old ";
	}
	~Person()
	{
		cout << "~Person() Called \n";

	}
};
class Student :public Person
{
private:
	float cgpa;
public:
	Student()
	{

		cout << "Student() Called\n";
		cgpa = 0.0;
	}
	Student(const char fname[], const char lname[], int a, double c) : Person(fname, lname, a)
	{
		cout << "Student() Called\n";
		cgpa = c;
	}

	void SetCGPA(float c)
	{
		cgpa = c;
	}
	float GetCGPA()
	{
		return cgpa;
	}
	void printStudent()
	{
		cout << endl;
		PrintInformation();
		cout << "and his cgpa is " << cgpa ;
	}


	~Student()
	{
		cout << "~Student() called \n";
	}

};

class Faculty :public Person
{
private:
	int course_count;
	int* extension_no;
public:
	Faculty()
	{
		cout << "Faculty() Called\n";
		course_count = 0;
		extension_no = 0;
	}
	Faculty(const char fname[],const char lname[], int a, int cc, int* e) :Person(fname, lname, a)
	{
		cout << "Faculty() Called\n";
		course_count = cc;
		extension_no = new int[3];

		for (int i = 0; i < 3; i++)
		{
			extension_no[i] = e[i];
		}

	}
	void SetCourseCount(int cc)
	{
		course_count = cc;
	}
	void SetExtensionNo(int* e)
	{
		extension_no = new int[3];

		for (int i = 0; i < 3; i++)
		{
			extension_no[i] = e[i];
		}

	}

	int GetCourseCount()
	{
		return course_count;
	}
	int* GetExtensionNo()
	{
		return extension_no;
	}

	void printFaculty()
	{
		cout << "Faculty Member Name: " << GetFirstName() << " " << GetLastName() << ", Age :" << GetAge() << " Number of Courses: " << course_count
			<< ", Ext. ";
		for (int i = 0; i < 3; i++)
		{
			cout << extension_no[i];
		}
		cout << endl;
	}

	~Faculty()
	{
		cout << "~Faculty Called \n";
		delete[] extension_no;
	}

};


class Graduate :public Student
{
private:
	char* thesis_topic;
public:
	Graduate()
	{
		cout << "Graduate() called\n";
		thesis_topic = 0;

	}
	Graduate(const char fname[],const char lname[], int a, float c,const char thesis[]) :Student(fname, lname, a, c)
	{
		cout << "Graduate() called\n";
		int size_thesis = strlen(thesis) + 1;
		thesis_topic = new char[size_thesis];


		strcpy(thesis_topic, thesis);

		thesis_topic[size_thesis] = '\0';

	}
	void SetThesisTopic(char* thesis)
	{
		int size_thesis = strlen(thesis) + 1;
		thesis_topic = new char[size_thesis];


		strcpy(thesis_topic, thesis);

		thesis_topic[size_thesis] = '\0';
	}
	char* GetThesisTopic()
	{
		return thesis_topic;
	}
	void printGraduate()
	{

		cout << GetFirstName() <<" " << GetLastName() << " is a graduate student , his gpa is " << GetCGPA() << " and his thesis topic is " << GetThesisTopic() << endl;
	}


	~Graduate()
	{
		cout << "~Graduate Called \n";
	}

};

class Undergraduate :public Student
{
private:
	char* fyp_name;
public:
	Undergraduate()
	{
		cout << "Undergraduate() called\n";
		fyp_name = 0;
	}
	Undergraduate(const char fname[],const char lname[], int a, float c,const char fyp[]) :Student(fname, lname, a, c)
	{
		cout << "Undergraduate() called\n";

		int size_fyp = strlen(fyp) + 1;
		fyp_name = new char[size_fyp];

		strcpy(fyp_name, fyp);
		fyp_name[size_fyp] = '\0';


	}
	void SetFypName(char* fyp)
	{
		int size_fyp = strlen(fyp) + 1;
		fyp_name = new char[size_fyp];

		strcpy(fyp_name, fyp);
		fyp_name[size_fyp] = '\0';
	}
	char* GetFypName()
	{
		return fyp_name;
	}
	void printUndergraduate()
	{
		printStudent();
		cout /*<< GetFirstName() <<" " << GetLastName() << " is an undergraduate student , his gpa is" << GetCGPA() << */<<" and his final year project is " << GetFypName() << endl;
	}

	~Undergraduate()
	{
		cout << "~Undergraduate Called \n";
	}
};


int main()
{
	Undergraduate student1;
	student1.SetFirstName("Ted");
	student1.SetLastName("Thompson");
	student1.SetCGPA(3.91);
	student1.SetAge(22);
	student1.PrintInformation();
	student1.printStudent();

	cout << endl;

	Faculty faculty1;
	faculty1.SetFirstName("Richard");
	faculty1.SetLastName("Karp");
	faculty1.SetAge(45);
	faculty1.SetCourseCount(2);
	int extension[1];
	extension[0] = 420;
	faculty1.SetExtensionNo(extension);
	faculty1.printFaculty();
	cout << endl;


	//outpput for exercise 5
	/*Person() Called
Student() Called
Undergraduate() called
Ted Thompson is 22 years old
Ted Thompson is 22 years old and his cgpa is 3.91Person() Called
Faculty() Called
Faculty Member Name: Richard Karp, Age :45 Number of Courses: 2, Ext. 420-858993460-858993460
~Faculty Called
~Person() Called
~Undergraduate Called
~Student() called
~Person() Called*/


	Student s("Ted", "Thompson", 22, 3.91);
	int arr[] = { 4, 2, 0 };
	Faculty f("Richard", "Karp", 45, 2, arr);

	//here the number of courses is 2
	//and the extension number is 420
	s.printStudent();
	cout << endl;

	f.printFaculty();
	cout << endl;

	Undergraduate u("Ted", "Thompson", 22, 3.91, "The Event locator");
	Graduate g("Arnold", "Gates", 25, 3.06, "Distributed Algorithims");
	

	u.printUndergraduate();
	cout << endl;

	g.printGraduate();
	cout << endl;

	u.printStudent();
	cout << endl;

	
	return 0;
}