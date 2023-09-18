////21L-5218
////Q1
//
//#include <iostream>
//
//using namespace std;
//
//class myVector
//{
//private:
//	int* arrayptr;
//	int capacity;
//	int current_size;
//public:
//	myVector()
//	{
//
//		capacity = 2;
//		arrayptr = new int[capacity];
//		arrayptr = NULL;
//		current_size = 0;
//	}
//	myVector(int c)
//	{
//		capacity = c;
//		arrayptr = new int[capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			arrayptr[i] = 0;
//		}
//	}
//	myVector(const myVector& newVector)
//	{
//		capacity = newVector.capacity;
//		current_size = newVector.current_size;
//		arrayptr = new int[capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			arrayptr[i] = newVector.arrayptr[i];
//		}
//
//	}
//	int* GetArrayPtr()
//	{
//		return arrayptr;
//	}
//
//	int GetCurrentSize()
//	{
//		return current_size;
//	}
//	int GetCapacity()
//	{
//		return capacity;
//	}
//
//	friend void operator +(int var, myVector& newVector)
//	{
//
//		if (newVector.current_size + 1 > newVector.capacity)
//		{
//			int* temp = new int[newVector.current_size];
//
//			for (int i = 0; i < newVector.current_size; i++)
//			{
//				temp[i] = newVector.arrayptr[i];
//			}
//			newVector.capacity = 2 * newVector.capacity;
//			delete[] newVector.arrayptr;
//
//			newVector.arrayptr = new int[newVector.capacity];
//			for (int i = 0; i < newVector.current_size; i++)
//			{
//				newVector.arrayptr[i] = temp[i];
//			}
//
//
//
//			delete[] temp;
//			temp = NULL;
//
//
//		}
//		newVector.arrayptr[newVector.current_size] = var;
//		newVector.current_size = newVector.current_size + 1;
//		
//
//
//	}
//	friend void operator -(int u,myVector& newVector)
//	{
//		newVector.arrayptr[newVector.current_size] = 0;
//		newVector.current_size = newVector.current_size - 1;;
//	}
//	int* operator+ (const myVector& newVector)
//	{
//		int i = 0;
//		int* newarr = new int[current_size + newVector.current_size];
//		for (; i < current_size; i++)
//		{
//			newarr[i] = arrayptr[i];
//			
//		}
//		for (int j = 0; j < newVector.current_size && i < current_size + newVector.current_size; j++, i++)
//		{
//			newarr[i] = newVector.arrayptr[j];
//		
//		}
//		return newarr;
//	}
//	const myVector& operator =(const myVector& newVector)
//	{
//		if (this != &newVector)
//		{
//			capacity = newVector.capacity;
//			delete arrayptr;
//			arrayptr = new int[capacity];
//
//			for (int i = 0; i < capacity; i++)
//			{
//				arrayptr[i] = 0;
//			}
//			for (int i = 0; i < capacity; i++)
//			{
//				arrayptr[i] = newVector.arrayptr[i];
//			}
//			return *this;
//
//		}
//	}
//	friend istream& operator>>(istream& cin, myVector& newVector)
//	{
//		
//		int var;
//		cin >> var;
//		var + newVector;
//		return cin;
//	}
//	friend ostream& operator<<(ostream& cout, myVector& newVector)
//	{
//		for (int i = 0; i < newVector.current_size; i++)
//		{
//			cout << newVector.arrayptr[i]<<"\t";
//
//
//		}
//		cout << endl;
//		return cout;
//	}
//
//
//	~myVector()
//	{
//		cout << "Destructor Called \n";
//		capacity = 0;
//		current_size = 0;
//		delete[] arrayptr;
//		arrayptr = NULL;
//
//	}
//
//
//	int& operator[](int idx)
//	{
//		if (idx >= 0 && idx < current_size)
//		{
//			return arrayptr[idx];
//		}
//		else
//			cout << " Out of bound\n";
//	}
//
//
//
//
//
//};
//
//
//int main()
//{
//
//	//testing constructors
//	myVector vector1;
//	cout << "Vector 1 Capacity : " << vector1.GetCapacity() << endl;
//
//	cout << "Vector 1 Current Size : " << vector1.GetCurrentSize() << endl;
//
//	myVector vector2(5);
//
//
//	cout << "Vector 2 Capacity : " << vector2.GetCapacity() << endl;
//
//	cout << "Vector 2 Current Size : " << vector2.GetCurrentSize() << endl;
//
//	myVector vector3(vector2);
//
//	cout << "Copied Vector 3 Capacity : " << vector3.GetCapacity() << endl;
//
//	cout << "Copied Vector 3 Current Size : " << vector3.GetCurrentSize() << endl;
//
//	//operators
//	//+
//	2 + vector2;
//	3 + vector2;
//	9 + vector2;
//	19 + vector2;
//	39 + vector2;
//	79 + vector2;
//
//	cout << "Vector 2 Capacity : " << vector2.GetCapacity() << endl;
//
//	cout << "Vector 2 Current Size : " << vector2.GetCurrentSize() << endl;
//	cout << "Vector 2 values : ";
//	cout << vector2;
//
//	//-
//	1-vector2;
//	cout << "Vector 2 values after subtracting last element : ";
//	cout << vector2;
//
//
//	//new arr
//	myVector vector4(10);
//	123 + vector4;
//	567 + vector4;
//	910 + vector4;
//	cout << "Vector 4 Capacity : " << vector4.GetCapacity() << endl;
//
//	cout << "Vector 4 Current Size : " << vector4.GetCurrentSize() << endl;
//	cout << "Vector 4 values : ";
//	cout << vector4;
//	int* mergedarr = vector2 + vector4;
//	cout << "merged arrray: ";
//	for (int i = 0; i < (vector2.GetCurrentSize() + vector4.GetCurrentSize()); i++)
//	{
//		cout << mergedarr[i] << "\t";
//	}
//	cout << endl;
//
//	myVector vector5(10);
//	
//	char choice = 'y';
//
//	while (choice !='n'&&choice=='y')
//	{
//
//
//		cout << "Enter Element : ";
//		cin >> vector5 ;
//
//		cout << "Continue? (y/n): ";
//		cin >> choice;
//		if (choice == 'n')
//		{
//			break;
//		}
//	}
//
//	cout << "Vector 5 Capacity : " << vector5.GetCapacity() << endl;
//
//	cout << "Vector 5 Current Size : " << vector5.GetCurrentSize() << endl;
//	cout << "Vector 5 values : ";
//	cout << vector5;
//
//
//	return 0;
//}
