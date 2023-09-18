#include <iostream>

using namespace std;

template <typename T>
class node
{
public:
	T data;
	node<T>* prev;
	node<T>* next;
	node()
	{
		prev=nullptr;
		next=nullptr;
	}
};
template <typename T>
class doublyLinkedList
{
	node<T>* head,*tail;
public:
	doublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	void Insert(T d)
	{
		if (head == nullptr)
		{
			node<T>* n = new node<T>;
			n->data = d;
			head = n;
			tail = n;
			return;
		}
		else if( head != nullptr)
		{
			node<T>* n = new node<T>;
			n->data = d;
		
			tail->next = n;
			n->prev = tail;
			tail = n;
			
			Sort();
			
			return;
		}

	}
	
	void insertAtStart(T d)
	{
		node<T>* n = new node<T>;
		n->data = d;

		if (head == nullptr)
		{
			head = n;
			return;
		}
		else if (head != nullptr && n->data < head->data)
		{
			
			head->prev = n;
			n->next = head;
			head = n;
			return;
		}
	}
	void InsertSorted(T d)
	{
		node<T>* n = new node<T>;
		n->data = d;
		if (head == nullptr || n->data < head->data)
		{
			insertAtStart(d);
			return;
		}
		else if (n->data > tail->data)
		{
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		else
		{
			node<T>* current = head;
			while (current != nullptr)
			{
				if (d > current->data && d < current->next->data)
				{
					n->next = current->next;
					n->prev = current;
					n->next->prev = n;
					n->prev->next = n;

				}
				current = current->next;
			}

		}


	}
	bool Search(T d)
	{
		node<T>* n = new node<T>;
		n->data = d;
		node<T>* start,*end= new node<T>;
		start = head;
		end = tail;

		while (start != nullptr)
		{
			if (n->data == start->data || n->data==end->data)
			{
				return true;
			}
			end = end->prev;
			start= start->next;
		}
		return false;
	}

	void Update(T toFind, T toReplace)
	{
		node<T>* curr = new node<T>;
		curr = head;
	
		if (!(Search(toFind)))
		{
			cout<<"The number doesn't exit.\n";
				return;
		}
		else
		{
			while (curr != nullptr)
			{
				if (curr->data == toFind)
				{
					curr->data = toReplace;
					return;
				}
				curr = curr->next;
			}
		}
		

	}

	void Sort()
	{
		for (node<T>* i = head; i!= tail; i=i->next)
		{
			for (node<T>* j = tail; j!=i; j=j->prev)
			{
				if (i->data > j->data)
				{
					swap(i, j);
				}
				
			}
		}
	}
	void swap(node<T>* a, node<T>* b)
	{
		T temp;
		temp = a->data;
		a->data = b->data;
		b->data = temp;
	}
	void print()
	{
		node<T>* curr = new node<T>;
		curr = head;
		cout << "\n[ ";
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
	doublyLinkedList<int> dll1;
	dll1.Insert(5);
	dll1.print();
	dll1.Insert(7);
	dll1.print();
	dll1.Insert(3);
	dll1.print();
	cout << "Searching # 5: " << dll1.Search(5)<<endl;
	cout << "Searching # 2: " << dll1.Search(2)<<endl;
	cout << "\nUpdate in between: \n";
	dll1.Update(7, 9);
	dll1.print();
	cout << "\nUpdate at head: \n";
	dll1.Update(5, 8);
	dll1.print();
	cout << "\nUpdate at tail: \n";
	dll1.Update(3, 2);
	dll1.print();
	dll1.InsertSorted(1);
	dll1.print();
	dll1.InsertSorted(10);
	dll1.print();
	dll1.InsertSorted(3);
	dll1.print();
	
	return 0;



}