#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename T>
class node
{
public:
	T data;
	node<T>* next;
	node()
	{
		next = nullptr;
	}
	node(T val)
	{
		data = val;
	}
};

template <typename T>
class queue
{
private:
	node<T>* front, * rear;
	int size;
public:
	queue()	//O(1)
	{
		front = nullptr;
		rear = nullptr;

	}
	void enqueue(T val)	//O(1)
	{
		node<T>* n = new node<T>;
		n->data = val;
		if (isEmpty())
		{
			rear = n;
			front = n;
			size++;
		}
		else
		{
			rear->next = n;
			rear = n;
			size++;
		}

	}
	void dequeue()	//O(N)
	{
		node<T>* n = new node<T>;

		if (isEmpty())
		{
			return;
		}
		else
		{
			if (front->next == nullptr)
			{
				n = front;
				front = nullptr;
				rear = nullptr;
				delete n;
				size--;
			}
			else
			{
				n = front;
				front = front->next;
				delete n;
				size--;
			}
		}

	}
	bool isEmpty()	//O(1)
	{
		if (front == nullptr && rear == nullptr)
		{
			return true;
		}
		return false;
	}
	int Size()	//O(1)
	{
		return size;
	}
	T Front()	//O(1)
	{
		if (!isEmpty())
			return front->data;
	}
	node<T>* FrontPointer()
	{
		return front;
	}

	int Rear()	//O(1)
	{
		if (!isEmpty())
			return rear->data;
	}
	node<T>* RearPointer()
	{
		return rear;
	}
	void dequeueAll()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	void print()	//O(N)
	{
		node<T>* curr = new node<T>;
		curr = front;
		cout << "[ ";
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "]\n";
	}
};

template <typename T=int>
void RadixSort(queue<T>& q1, int m, int n, int k)
{

	queue<T>* bucketarr = new queue<T>[m];


	for (int i = 0; i < k; i++)///for no of passes based on digits
	{
		int div = pow(10, i);//getting to the power of number of digits - 1 to use for mod
		int mod = pow(10, i + 1);
		int remainder = 0;
		node<T>* curr = new node<T>;
		curr = q1.FrontPointer();
		for (; curr != nullptr; curr = curr->next)//pushing data into buckets
		{

			remainder = (curr->data % mod) / div;//getting remainder right->left
			bucketarr[remainder].enqueue(curr->data);
		}


		q1.dequeueAll();//emptying original queue

		for (int j = 0; j < m; j++)//loading data from buckets into original queue
		{
			while (!(bucketarr[j].isEmpty()))
			{
				q1.enqueue(bucketarr[j].Front());
				bucketarr[j].dequeue();
			}

		}


		//	q1.print(); uncomment to check it sorts digit by digit (r->l)


	}




}
template <typename T>
void RadixSortString(queue<T>& q1, int m, int n, int k)
{

	queue<T>* bucketarr = new queue<T>[m];



	for (int i =k-1; i >=0; i--)///for no of passes based on digits
	{
	
		int asciiValue = 0;

		node<T>* curr = new node<T>;
		curr = q1.FrontPointer();
		for (; curr != nullptr; curr = curr->next)//pushing data into buckets
		{
			asciiValue = static_cast<int>(curr->data[i]);


			bucketarr[asciiValue].enqueue(curr->data);
			//bucketarr[asciiValue].print();
		}


		q1.dequeueAll();//emptying original queue
		
		for (int j = 0; j < m; j++)//loading data from buckets into original queue
		{
			
			while (!(bucketarr[j].isEmpty()))
			{
				

			
				q1.enqueue(bucketarr[j].Front());
				bucketarr[j].dequeue();
			}
			
		}
	

		//	q1.print(); uncomment to check it sorts digit by digit (r->l)


	}




}


int main()
{
	queue<int> q1;
	q1.enqueue(329);
	q1.enqueue(457);
	q1.enqueue(657);
	q1.enqueue(839);
	q1.enqueue(436);
	q1.enqueue(720);
	q1.enqueue(355);
	q1.print();

	cout << "After Sort:\n";
	RadixSort(q1, 10, q1.Size(), 3);
	q1.print();


	queue<string> q2;
	q2.enqueue("Bed");
	q2.enqueue("Ali");
	q2.enqueue("Zen");
	q2.enqueue("Cow");
	q2.enqueue("Dan");
	q2.enqueue("Fre");
	q2.enqueue("Ani");
	q2.enqueue("Bin");
	q2.enqueue("bin");
	q2.print();
	RadixSortString(q2, 256, q2.Size(), 3);
	cout << "After Sort:\n";
	q2.print();




}
