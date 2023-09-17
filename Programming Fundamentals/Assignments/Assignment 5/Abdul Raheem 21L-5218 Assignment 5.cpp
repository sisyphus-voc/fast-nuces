#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Input function
void GetInput(int& students, string rollno[], string firstName[], string lastName[], 
			  int calc[],int prog[], int phy[], int eng[], int isl[]);

void CalculateGrade(int students,const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
					char Gcalc[], char Gprog[], char Gphy[], char Geng[], char Gisl[]);

void CalculateGPA(int students, const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
				  double GPAcalc[],double GPAprog[],double GPAphy[],double GPAeng[],double GPAisl[]);

void CalculateSGPA(int students, double GPAcalc[], double GPAprog[], double GPAphy[], double GPAeng[], double GPAisl[],
					double sGPA[]);

double AverageSGPA(int students, double sGPA[], double& AvgSGPA,string&highestSGPAstudent, string firstName[], string lastName[]);

void PrintMarksheet(int students,string rollno[], string firstName[], string lastName[], const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
					char Gcalc[], char Gprog[], char Gphy[], char Geng[], char Gisl[], double GPAcalc[], double GPAprog[],
					double GPAphy[], double GPAeng[], double GPAisl[], double sGPA[], double AvgSGPA, double highestSGPA,string highestSGPAstudent);


/*-----------------------------------------------The main function begins here*---------------------------------------------------------*/


int main()
{

	/************ Input Variables ***********/
	
	

	//Array sizes
	const int size = 100;

	//no of students 
	int students=0;

	//Arrays for Roll Numbers and Names
	string rollno[size], firstName[size], lastName[size];

	/********* Calculation Variables *******/

	//Arrays for Marks
	int calc[size], prog[size], phy[size], eng[size], isl[size];

	//Arrays for Grade 
	char Gcalc[size], Gprog[size], Gphy[size], Geng[size], Gisl[size];

	//Arrays and variables for GPA & SGPA & Average SGPA
	double GPAcalc[size], GPAprog[size], GPAphy[size], GPAeng[size], GPAisl[size];
	double sGPA[size];
	double AvgSGPA=0.0,highestSGPA=0.0;
	string highestSGPAstudent;
	/************** Processess *************/

	//takin input through function
	GetInput(students, rollno, firstName, lastName, calc, prog, phy, eng, isl);



	//Calculating grades for each subject through function
	CalculateGrade(students, calc, prog, phy, eng, isl,Gcalc, Gprog, Gphy, Geng, Gisl);

	//Calculating GPA 
	CalculateGPA(students, calc, prog, phy, eng, isl, GPAcalc, GPAprog, GPAphy, GPAeng, GPAisl);
	
	//Calculating SGPA
	CalculateSGPA(students, GPAcalc, GPAprog, GPAphy, GPAeng, GPAisl,sGPA);

	//Average SGPA of the class 
	highestSGPA = AverageSGPA(students, sGPA, AvgSGPA, highestSGPAstudent, firstName,lastName);

	//Displaying Output
	PrintMarksheet(students, rollno, firstName, lastName, calc, prog, phy, eng, isl, Gcalc, Gprog, Gphy, Geng, Gisl,
					GPAcalc, GPAprog, GPAphy, GPAeng, GPAisl, sGPA,AvgSGPA,highestSGPA,highestSGPAstudent);

	return 0;
}


void GetInput(int& students, string rollno[], string firstName[], string lastName[], int calc[], int prog[], int phy[], int eng[], int isl[])
{
	ifstream fin;
	fin.open("Marksheet.txt");
	
	
	fin >> students;
	
	

	//while (!fin.eof())
	{
		

		for (int i = 0; i<students && (!fin.eof()); i++)
		{
			getline(fin, rollno[i], ',');
			fin >> firstName[i];
			getline(fin, lastName[i], ',');
			fin >> calc[i];
			fin.ignore(2,',');
			fin >> prog[i];
			fin.ignore(2,',');
			fin >> phy[i];
			fin.ignore(2,',');
			fin >> eng[i];
			fin.ignore(2,',');
			fin >> isl[i];
		}

		
	}
	fin.close();

	
}
void CalculateGrade(int students,const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
	char Gcalc[], char Gprog[], char Gphy[], char Geng[], char Gisl[])
{
	for (int i = 0; i < students; i++)
	{
		
		if (calc[i] >= 80)
			Gcalc[i] = 'A';
		else if (calc[i] < 80 && calc[i] >= 70)
			Gcalc[i] = 'B';
		else if (calc[i] < 70 && calc[i] >= 60)
			Gcalc[i] = 'C';
		else if (calc[i] < 60 && calc[i] >= 50)
			Gcalc[i] = 'D';
		else if (calc[i] <=50)
			Gcalc[i] = 'F';

		if (prog[i] >= 80)
			Gprog[i] = 'A';
		else if (prog[i] < 80 && prog[i] >= 70)
			Gprog[i] = 'B';
		else if (prog[i] < 70 && prog[i] >= 60)
			Gprog[i] = 'C';
		else if (prog[i] < 60 && prog[i] >= 50)
			Gprog[i] = 'D';
		else if (prog[i] <= 50)
			Gprog[i] = 'F';

		if (phy[i] >= 80)
			Gphy[i] = 'A';
		else if (phy[i] < 80 && phy[i] >= 70)
			Gphy[i] = 'B';
		else if (phy[i] < 70 && phy[i] >= 60)
			Gphy[i] = 'C';
		else if (phy[i] < 60 && phy[i] >= 50)
			Gphy[i] = 'D';
		else if (phy[i] <= 50)
			Gphy[i] = 'F';

		if (eng[i] >= 80)
			Geng[i] = 'A';
		else if (eng[i] < 80 && eng[i] >= 70)
			Geng[i] = 'B';
		else if (eng[i] < 70 && eng[i] >= 60)
			Geng[i] = 'C';
		else if (eng[i] < 60 && eng[i] >= 50)
			Geng[i] = 'D';
		else if (eng[i] <= 50)
			Geng[i] = 'F';

		if (isl[i] >= 80)
			Gisl[i] = 'A';
		else if (isl[i] < 80 && isl[i] >= 70)
			Gisl[i] = 'B';
		else if (isl[i] < 70 && isl[i] >= 60)
			Gisl[i] = 'C';
		else if (isl[i] < 60 && isl[i] >= 50)
			Gisl[i] = 'D';
		else if (isl[i] <= 50)
			Gisl[i] = 'F';




	}

}
void CalculateGPA(int students, const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
	double GPAcalc[], double GPAprog[], double GPAphy[], double GPAeng[], double GPAisl[])
{
	for (int i = 0; i < students; i++)
	{
		if (calc[i] >= 80)
			GPAcalc[i] =4.0;
		else if (calc[i] < 80 && calc[i] >= 70)
			GPAcalc[i] = 3.0;
		else if (calc[i] < 70 && calc[i] >= 60)
			GPAcalc[i] = 2.0;
		else if (calc[i] < 60 && calc[i] >= 50)
			GPAcalc[i] = 1.0;
		else if (calc[i] <= 50)
			GPAcalc[i] = 0.0;
		
		if (prog[i] >= 80)
			GPAprog[i] = 4.0;
		else if (prog[i] < 80 && prog[i] >= 70)
			GPAprog[i] = 3.0;
		else if (prog[i] < 70 && prog[i] >= 60)
			GPAprog[i] = 2.0;
		else if (prog[i] < 60 && prog[i] >= 50)
			GPAprog[i] = 1.0;
		else if (prog[i] <= 50)
			GPAprog[i] = 0.0;

		if (phy[i] >= 80)
			GPAphy[i] = 4.0;
		else if (phy[i] < 80 && phy[i] >= 70)
			GPAphy[i] = 3.0;
		else if (phy[i] < 70 && phy[i] >= 60)
			GPAphy[i] = 2.0;
		else if (phy[i] < 60 && phy[i] >= 50)
			GPAphy[i] = 1.0;
		else if (phy[i] <= 50)
			GPAphy[i] = 0.0;

		if (eng[i] >= 80)
			GPAeng[i] = 4.0;
		else if (eng[i] < 80 && eng[i] >= 70)
			GPAeng[i] = 3.0;
		else if (eng[i] < 70 && eng[i] >= 60)
			GPAeng[i] = 2.0;
		else if (eng[i] < 60 && eng[i] >= 50)
			GPAeng[i] = 1.0;
		else if (eng[i] <= 50)
			GPAeng[i] = 0.0;

		if (isl[i] >= 80)
			GPAisl[i] = 4.0;
		else if (isl[i] < 80 && isl[i] >= 70)
			GPAisl[i] = 3.0;
		else if (isl[i] < 70 && isl[i] >= 60)
			GPAisl[i] = 2.0;
		else if (isl[i] < 60 && isl[i] >= 50)
			GPAisl[i] = 1.0;
		else if (isl[i] <= 50)
			GPAisl[i] = 0.0;




	}
	
}
void CalculateSGPA(int students, double GPAcalc[], double GPAprog[], double GPAphy[], double GPAeng[], double GPAisl[], double sGPA[])
{
	double gradepoint = 0;
	double CG = 0.0;
	int totalcreds = 0;

	for (int i = 0; i < students; i++)
	{
		CG = GPAcalc[i] * 4 + GPAprog[i] * 4 + GPAphy[i] * 3 + GPAeng[i] * 3 + GPAisl[i] * 3;
		totalcreds = 4 + 4 + 3 + 3 + 3;
		sGPA[i] = CG / totalcreds;
		
	}


}
double AverageSGPA(int students, double sGPA[], double& AvgSGPA,string& highestSGPAstudent, string firstName[], string lastName[])
{
	double totalSGPA = 0.0;
	double highestSGPA = sGPA[1];
	for (int i = 0; i < students; i++)
	{
		if (sGPA[i] > highestSGPA)
			highestSGPA = sGPA[i];
		highestSGPAstudent = firstName[i] + lastName[i];
		totalSGPA += sGPA[i];
		
	
	}
	AvgSGPA = totalSGPA / students;
	return highestSGPA;
	
}

void PrintMarksheet(int students, string rollno[], string firstName[], string lastName[],
					const int calc[], const int prog[], const int phy[], const int eng[], const int isl[],
					char Gcalc[], char Gprog[], char Gphy[], char Geng[], char Gisl[], double GPAcalc[], double GPAprog[],
					double GPAphy[], double GPAeng[], double GPAisl[], double sGPA[], double AvgSGPA, double highestSGPA, string highestSGPAstudent)
{

	for (int i = 0; i < students; i++)
	{
		cout << "Name: " << firstName[i] << lastName[i] << endl;
		cout << "Roll no:" << rollno[i] << "\n\n";
		cout << "SUBJECT \t" << "MARKS " << " Grade " << "  GPA \n\n";
		cout << "Calculus " << "\t" << calc[i] << "\t" << Gcalc[i] << "\t" << GPAcalc[i] << endl;
		cout << "Programming " << "\t" << prog[i] << "\t" << Gprog[i] << "\t" << GPAprog[i] << endl;
		cout << "Physics " << "\t" << phy[i] << "\t" << Gphy[i] << "\t" << GPAphy[i] << endl;
		cout << "English " << "\t" << eng[i] << "\t" << Geng[i] << "\t" << GPAeng[i] << endl;
		cout << "Islamiyat " << "\t" << isl[i] << "\t" << Gisl[i] << "\t" << GPAisl[i] << "\n";
		cout << "\t\t\t" << "SGPA = " << setprecision(3) << sGPA[i] << "\n\n";
		cout << "Average SGPA of the class = " << AvgSGPA << "\n";
		cout << "Highest SGPA of the class = " << setprecision(3)<<  highestSGPA << " by " << highestSGPAstudent << "\n\n";
	}


}
