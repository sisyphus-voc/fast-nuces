//#include <iostream>
//using namespace std;
//
//void task1()
//{
//	
//
//
//
//	int x, y;
//	x = 3, y = 4;
//	int* p;
//	int* q;
//	p = &x;
//	q = &y;
//	cout << x << '\t' << p << '\t' << *p << '\t' << &p << '\t' << &x << endl;
//	cout << y << '\t' << q << '\t' << *q << '\t' << &q << '\t' << &y << endl;
//
//
//}
//void task2()
//{
//	
//
//
//	float x = 0, y = 0;
//	cout << "Please Enter First Number : ";
//	cin >> x;
//	cout << "Please Enter Second Number : ";
//	cin >> y;
//
//	float* a = &x, * b = &y;
//
//	float sum = *a + *b;
//	cout << "Sum of numbers is: " << sum;
//}
//void  task3()
//{
//	int* var = new int;
//	cout << "Please Enter Integer : ";
//	cin >> *var;
//
//	int sq = (*var) * (*var);
//	int cube = (*var) * (*var) * (*var);
//	int half = (*var) / 2;
//
//	cout << "Square of the numbers is : " << sq << endl;
//	cout << "cube of the numbers is : " << cube << endl;
//	cout << "Half of the numbers is : " << half << endl;
//
//	delete var;
//}
//
//
//
//int* AllocateMemory(int size)
//{
//	int* newArr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		newArr[i] = 0;
//	}
//	return newArr;
//}
//void task4()
//{
//	int size=0;
//	cout << "Enter size of array : ";
//	cin >> size;
//
//	int* newArr;
//	newArr = AllocateMemory(size);
//
//}
//void AscendingSort(int* testScores,int size)
//
//{
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = size - 1; j >= i; j--)
//		{
//			if (testScores[i] > testScores[j])
//			{
//				int temp = testScores[i];
//				testScores[i] = testScores[j];
//				testScores[j] = temp;
//			}
//		}
//	}
//
//}
//
// int AverageScore(int* testScores, int size)
//{
//	 int avg = 0;
//	 for (int i = 0; i < size; i++)
//	 {
//		 avg += testScores[i];
//
//	 }
//
//	 avg /= size;
//	 return avg;
//}
//
//void task5()
//{
//	int* testScores;
//
//	int size = 0;
//	int avgScore=0;
//	cout << "Enter size of array : ";
//	cin >> size;
//
//
//	testScores = AllocateMemory(size);
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter test score # " << i + 1<<endl;
//		cin >> testScores[i];
//
//	}
//
//	AscendingSort(testScores,size);
//	avgScore=AverageScore(testScores, size);
//
//	cout << "Sorted Test Scores : \n";
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Test score # " << i + 1 << " ";
//		cout << testScores[i] << endl;;
//
//	}
//	cout << "\n Average Score : " << avgScore << endl;
//
//}
//int Mode(int* integer, int size)
//{
//	int mode = -1;
//	int* frequency = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		*(frequency + i) = 0;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (*(integer + i) == *(integer + j))
//			{
//				*(frequency + i)+=1;
//			}
//		}
//	}
//	int greatest = 1;
//	for (int i = 0; i < size; i++)
//	{
//		if (*(frequency + i) > greatest)
//		{
//			mode = *(integer + i);
//		}
//	}
//	return mode;
//}
//void task6()
//{
//	int* integer;
//	int size;
//	cout << "Enter size of array : ";
//	cin >> size;
//	integer = AllocateMemory( size);
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter integer # " << i + 1 << endl;
//		cin >> *(integer + i);
//
//	}
//	int mode = 0;
//	mode = Mode(integer, size);
//	cout << "mode : " << mode << endl;
//
//}
//
//int main()
//{
//	task1();
//	task2();
//	task3();
//	task4();
//	
//
//	 
//	task5();
//	
//
//	/////I didn't apply check for if there are 2 elements occur most eqaully
//	/////since I didn't know whether I should make 1 of them output, none of them or both of them
//	/////also took the longer method bcz I thought we required to output the frequency of 
//	/////the mode not the actual number that occurs multiple times
//	task6();
//
//return 0;
//
//
//
//}