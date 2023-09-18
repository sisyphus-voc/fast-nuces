//#include <iostream>
//using namespace std;
//
//
//int* InputArray(int& size)
//{
//	cout << "Enter size of array : ";
//	cin >> size;
//	int* newArr = new int[size];
//
//	
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter Element # " << i <<" : ";
//		cin >> newArr[i];
//		cout << endl;
//	}
//	return newArr;
//
//}
//void OutputArray(const int* myArray, const int& size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Element # " << i << " : "<< myArray[i]<<endl;
//	}
//}
//
//
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
//
//int* CompressArray(int* originalArr, int& size)
//{
//	
//	int* tempArr=new int[size];
//	int compressedSize=0;
//
//
//	for (int i = 0; i < size; i++)
//	{
//		tempArr[i] = 0;
//	}
//
//
//	
//	for (int i = 0; i < size; i++)
//	{
//		
//		
//		{
//			if (i == 0)
//			{
//				tempArr[compressedSize] = originalArr[i];
//				compressedSize++;
//			}
//			
//			else
//			{
//				if (originalArr[i] != originalArr[i - 1])
//				{
//					tempArr[compressedSize] = originalArr[i];
//					compressedSize++;
//				}
//			}
//			
//		}
//		
//	}
//	size = compressedSize;
//	int* compressedArr = new int[compressedSize];
//	for (int i = 0; i < compressedSize; i++)
//	{
//		compressedArr[i] = 0;
//		compressedArr[i] = tempArr[i];
//	}
//	delete[] tempArr;
//	
//	return compressedArr;
//}
//int* Intersection(int* setA, int& size1, int* setB, int& size2, int& size3)
//{
//	
//
//	if (size1 < size2)
//	{
//		size3 = size1;
//	}
//	else
//	{
//		size3 = size2;
//	}
//	
//	int c = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		for (int j = 0; j < size2; j++)
//		{
//			if (setA[i] == setB[j])
//			{
//				c++;
//			}
//		}
//	}
//	size3 = c;
//	int* IntersectArr = new int[size3];
//	c = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		for (int j = 0; j < size2; j++)
//		{
//			if (setA[i] == setB[j])
//			{
//				IntersectArr[c] = 0;
//				IntersectArr[c] = setA[i];
//				c++;
//			}
//		}
//	}
//	return IntersectArr;
//}
//int main()
//{
//	int size = 0;
//
//	int* myArray;
//	int* CompressedArray;
//	//////////////exercise 1,2 & 3
//	myArray=InputArray(size);
//	AscendingSort(myArray, size);
//	CompressedArray=CompressArray(myArray, size);
//	cout << "CompressedArray : " << endl;
//	OutputArray(CompressedArray, size);
//	
//	////////////Exercise 4 intersection
//	int* set1, *set2, *set3;
//	int size1=0, size2=0, size3=0;
//
//	set1 = InputArray(size1);
//	set2 = InputArray(size2);
//
//	cout << "A  = " << endl;
//	OutputArray(set1, size1);
//	cout << "B = " << endl;
//	OutputArray(set2, size2);
//
//	set3 = Intersection(set1, size1, set2, size2, size3);
//	cout << "A intersection B = " << endl;
//	OutputArray(set3, size3);
//return 0;
//
//}