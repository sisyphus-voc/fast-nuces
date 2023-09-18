//21L5218


#include <iostream>

using namespace std;

template <typename T>
class node
{
public:
	T data;
	node<T>* next;
	node()	//O(1)
	{
		next = nullptr;
	}
	node(T d)	//O(1)
	{
		data = d;
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
			n = front;
			front = front->next;
			delete n;
			size--;
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
	int Front()	//O(1)
	{
		if (!isEmpty())
		return front->data;
	}
	int Rear()	//O(1)
	{
		if(!isEmpty())
		return rear->data;
	}
	void AlternateElements()
	{
		node<T>* curr1, * curr2 = new node<T>;
		curr1 = curr2 = front;

		for (int i = 0; i < (size / 2)-1 && size>2; i++)
		{
			curr1 = curr1->next;
			
		}
		node<T>* mid=curr1;
		curr1 = curr1->next;
		

		queue<T> tempQ;
		while (curr1 != nullptr)
		{
			node<T>* n = new node<T>;
			n = curr1;
			tempQ.enqueue(curr1->data);
			curr1 = curr1->next;
			delete n;
		}
		mid->next = nullptr;
		
		
		node<T>* curr3 = new node<T>;
		curr1 = tempQ.front;
		while (curr1 != nullptr)
		{
			curr3 = curr1->next;
			curr1->next = curr2->next;
			curr2->next = curr1;
			curr1 = curr3;
			curr2 = curr2->next->next;

		}
	}
	//is full is not possible since a list can not be full
	void print()	//O(N)
	{
		node<T>* curr=new node<T>;
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




int main()
{
	//Q1
	queue<int> Q1,Q2;
	Q1.enqueue(5);
	Q1.enqueue(6);
	Q1.enqueue(7);
	Q1.enqueue(8);
	Q1.print();
	Q1.dequeue();
	Q1.dequeue();
	Q1.print();


	//Q2
	Q2.enqueue(3);
	Q2.enqueue(2);
	Q2.enqueue(5);
	Q2.enqueue(6);
	Q2.enqueue(7);
	Q2.enqueue(9);
	Q2.enqueue(8);
	Q2.enqueue(4);
	cout << "Input: ";
	Q2.print();
	Q2.AlternateElements();
	cout << "Output: ";
	Q2.print();
}