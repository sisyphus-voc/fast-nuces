//																			OOP ASSIGNMENT - 1
//																				Abdul Raheem
//																				 21L-5218
//																				  BCS-2N
//																					Q1
#include <iostream>
#include <string>

using namespace std;

class student
{
public:
	string RollNum, Name;
	char Gender=' ';


	int test_scores[2]={0,0};
	int mid_score = 0, final_score = 0, total_score = 0;

	int TotalScore(int test[], int mid, int final)
	{
		total_score = test[0]+test[1] + mid + final;
		return total_score;
	}


};

void AddStudents(student Students[], int& size);
void ViewStudents(student Students[],int size);
int GetStudentID(student Students[],int size);
void CalculateAvgScore(student Students[], int index);
void MaxScore(student Students[], int size);
void FindStudent(student Students[], int index);

int main()
{
	int choice = 0;
	string name, id;
	student Students[5];
	student temp_student;
	int size = 0;
	int index = -1;
	do
	{

		cout << "I. Add student record from user \n"
			<< "II.View all student records \n"
			<< "III.Calculate average score of a student \n"
			<< "IV.Show student who gets the max total score \n"
			<< "V.Find a student by ID \n"
			<< "VI.Exit Program \n"
			<< "Enter your choice \n" << "-->";
		cin >> choice;
		while (!(cin >> choice)) {
			cout << "Invalid Input \n"<<"Choose any option from(1-6):";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


		if (choice == 1)
		{
			if (size < 5)
			{
				AddStudents(Students, size);
			
			}
			else
				cout << "Memory full \n\n";
			
		}
		else if (choice == 2)
		{
			ViewStudents(Students,size);
		}
		else if (choice == 3)
		{
			index=GetStudentID(Students,size);
			cout << index;
			CalculateAvgScore(Students, index);
		}
		else if (choice == 4)
		{
			MaxScore(Students,size);
		}
		else if (choice == 5)
		{
			index =GetStudentID(Students,size);
			FindStudent(Students, index);
		}
	}
	while (choice != 6);

	system("pause");
	return 0;
}

void AddStudents(student Students[],int& size)
{
	cout << "Enter your roll number:" << endl;
	cin >> Students[size].RollNum;
	cout << "Enter Name: " << endl;
	cin.ignore();
	getline(cin, Students[size].Name);
	cout << "Enter Gender (M/F/O):" << endl;
	cin >> Students[size].Gender;
	cout << "Enter test score 1 and 2: \n";
	for (int i = 0; i < 2; i++)
	{
		cin >> Students[size].test_scores[i];
	}
	cout << "Enter mid score: ";
	cin >> Students[size].mid_score;
	cout << "Enter final score: ";
	cin >> Students[size].final_score;
	Students[size].total_score= Students->TotalScore(Students[size].test_scores , Students[size].mid_score,Students[size].final_score);

	size++;
}
void ViewStudents(student Students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Students[i].RollNum << endl << Students[i].Name << endl << Students[i].Gender << endl << Students[i].total_score<<"\n\n";
	}
}
int GetStudentID(student Students[], int size)
{
	int index = -1;
	student temp_student;

	cout << "Enter the ID of the student: \n";
	cin >> temp_student.RollNum;
	for (int i = 0; i < size; i++)
	{
		if (Students[i].RollNum == temp_student.RollNum)
		{
			index = i;
		}
	}
	return index;

}
void CalculateAvgScore(student Students[], int index)
{
	int avg_score = 0;
	avg_score = Students[index].total_score / 4;
	cout << "Average score of " << Students[index].Name << " is " << avg_score<<endl;
}
void MaxScore(student Students[], int size)
{
	string name ;
	int max_total = -1;
	for (int i = 0; i < size; i++)
	{
		if (Students[i].total_score > max_total)
		{
			max_total = Students[i].total_score;
			name = Students[i].Name;

		}
	}
	cout << "Student with max score is " << name << " with " << max_total << " marks \n";
}
void FindStudent(student Students[], int index)
{
	cout << Students[index].Name << endl << Students[index].Gender << endl << Students[index].total_score << "\n\n";
}


