//																			OOP ASSIGNMENT - 1
//																				Abdul Raheem
//																				 21L-5218
//																				  BCS-2N
//																					Q4
#include <iostream>
using namespace std;

class Student
{
public:
	string Roll_number;
	int total_marks = 0;

	void CalculateGrade(int total_marks)
	{
		if (total_marks > 90 && total_marks<=100)
		{
			cout << "Grade: A+ \n";
		}
		else if (total_marks > 80 && total_marks <= 90)
		{
			cout << "Grade: A \n";
		}
		else if (total_marks > 70 && total_marks <= 80)
		{
			cout << "Grade: B+ \n";
		}
		else if (total_marks > 60 && total_marks <= 70)
		{
			cout << "Grade: B \n";
		}
		else if (total_marks > 50 && total_marks <= 60)
		{
			cout << "Grade: B- \n";
		}
		else if (total_marks >= 40 && total_marks <= 50)
		{
			cout << "Grade: B- \n";
		}
		else if (total_marks < 40 && total_marks>=0)
		{
			cout << "Grade: F\n" << "You have failed the course and need to enroll again!!!! \n";
		}
		else
		{
			cout << "Invalid Marks" << endl;
		}

	 }

};

int main()
{
	char choice='y';
	int size = 0;
	Student* temp_student = NULL;
	

	for (size=0;choice!='n'; size++)
	{
		Student* students = new Student[size + 1];

		for (int i = 0; i < size; i++)
		{
			students[i] = temp_student[i];
		}

		cout << "Enter Roll no: ";
		cin >> students[size].Roll_number;
		cout << "Enter Total Marks: ";
		cin >> students[size].total_marks;

		students->CalculateGrade(students[size].total_marks);

		cout << "Do you want to add more information? (y/n) \n";
		cin >> choice;

		delete[] temp_student;
		temp_student = students;
		


		

	}

	if (choice == 'n')
	{
		cout << "Thankyou \n";
	}



system("pause");
	return 0;

}