//#include<cstring>
//#include <cstdlib>
//#include <list>
//#include <iostream>
//using namespace std;
//
//
//template <typename T>
//class Stack
//{
//private:
//	int capacity, size; // physical and logical size of stack
//	int top; // index of top
//	T* arr;
//
//public:
//
//	//Parametrised Constructor
//	Stack(int isize = 0) //isize is the initial size
//	{
//		// check
//		if (size >= 0)
//		{
//			arr = new T[isize];
//			size = 0;
//			top = -1; // as top point to the index of latest element and stack is empty here
//					  // top+1 =size
//			capacity = isize;
//		}
//		else
//		{
//			//initialisation 
//			arr = nullptr;
//			top = -1;
//			size = 0;
//			capacity = 0;
//		}
//	}
//	// Copy Constructor
//	Stack(const Stack& obj)
//	{
//		top = obj.top;
//		size = obj.size;
//		capacity = obj.capacity;
//		arr = new T[capacity];
//
//		for (int i = 0; i < capacity; i++)
//		{
//			arr = obj.arr[i];
//		}
//
//	}
//	bool Isempty()
//	{
//		// returns true if size 0 i.e stack is empty
//		return (size == 0); // size is the logical size of stack i.e number of elements in stack
//	}
//	bool Isfull()
//	{
//		// returns true if stack is not empty
//		return (size != 0);
//	}
//	~Stack()
//	{
//		delete[] arr;
//	}
//	void push(const T& obj)
//	{
//		if (size < capacity) // when there is space in stack
//		{
//			arr[++top] = obj; //top incremented then allocated.
//			size++; // as one element is added size of capacity is unchanged
//		}
//		else if (capacity == 0) // when capacity is zero stack is created
//		{
//			arr = new T[1];
//			arr[0] = obj;
//			top = 0;
//			size = 1;
//			capacity = 1;
//		}
//		else //when size is equal to capacity i.e is stack is full. 
//		{
//			
//			if (top + 1 == capacity)
//			{
//				top = -1;
//			}
//			arr[++top] = obj;
//			
//		}
//	}
//	const T& Top() //It is the peek function. It reads (and returns) the value at top.
//	{
//		return arr[top]; // returns the element at top
//	}
//	void pop()
//	{
//		if (Isempty())
//		{
//			return;
//		}
//		else 
//		{
//			
//			arr[top] = NULL;
//			top--;
//			size--;
//		}
//
//
//
//		//simple case
//		//else if (size > capacity / 2) //i.e if stack is more than half full
//		//{
//		//	//removes the value at top without printing or reading it
//		//	// reading the value at top is done by top/peek function
//		//	top--;
//		//	size--;
//		//}
//		//Shrinking case
//		//else //when stack is less than half full i.e more than half empty.
//		//{
//		//	//Shrinking the stack in half
//		//	T* temp = new T[capacity / 2];
//		//	for (int i = 0; i < size; i++)
//		//	{
//		//		temp[i] = arr[i];
//		//	}
//
//		//	capacity = capacity / 2; // stack is halved
//		//	size--; //as one new element is added
//		//	top--;
//		//	arr = temp; //arr points to temp now
//		//}
//	}
//	// Display the elements in the stack
//	void Display()
//	{
//		cout << " The stack has the values: ";
//
//		for (int i = 0; i < capacity; i++)
//		{
//			cout << arr[i]<<" ";
//		}
//		cout << endl;
//	}
//	Stack& operator = (const Stack& S)
//	{
//		top = S.top;
//		size = S.size;
//		capacity = S.capacity;
//		arr = new T[capacity];
//
//		for (int i = 0; i < capacity; i++)
//		{
//			arr = S.arr[i];
//		}
//	}
//};
//
//
//
//int main()
//{
//	Stack<int> S1(5);
//	cout << "Pushing 5 elements : \n";
//	S1.push(5);
//	S1.push(6);
//	S1.push(7);
//	S1.push(8);
//	S1.push(9);
//	S1.Display();
//	cout << "Pushing elements after full capacity: \n";
//	S1.push(10);
//	S1.push(11);
//	S1.push(12);
//	S1.Display();
//	cout << "Popping elements after Pushing elements whilst full capacity: \n";
//	S1.pop();
//	S1.Display();
//	cout << "Pushing elements after Popping: \n";
//	S1.push(13);
//	S1.Display();
//	S1.push(14);
//	S1.Display();
//	S1.push(15);
//	S1.Display();
//	S1.push(16);
//	S1.Display();
//}