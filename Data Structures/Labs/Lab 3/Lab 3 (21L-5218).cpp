#include <iostream>

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
	
};

template<typename T>
class linkedlist
{
private:
	node<T>* head;
public:
	linkedlist()
	{
		head = nullptr;
	}
	void InsertAtStart(T const element)
	{
		node<T>* n = new node<T>;
		n->data = element;


		if (head == nullptr)
		{
			head = n;
			return;
		}
		else
		{
			n->next = head;
			head = n;
			return;
		}
	}
	void insertAtEnd(T const element)
	{
		node<T>* n = new node<T>;
		n->data = element;
		n->next = nullptr;
		node<T>* current = head;

		while (current->next != nullptr)
		{

			current = current->next;
		}
		current->next = n;
		return;
	}
	bool search(T const& element)
	{

		node<T>* n = new node<T>;
		n->data = element;
		n->next = nullptr;
		node<T>* current = head;

		while (current != nullptr)
		{
			if (current->data == n->data)
			{
				return true;

			}
			current = current->next;
		}

		return false;
	}



	bool isEmpty()
	{
		if (head == nullptr)
		{
			
			return true;
		}
		return false;
	}

	bool insertBefore(T const v1, T const v2)
	{
		node<T>* current = head;
		node<T>* n = new node<T>;
		n->data = v1;
		if (head->data == v2)
		{
			InsertAtStart(v1);
			cout << "Element Inserted\n";
			return true;
		}
		while (current->next != nullptr)
		{
			if (current->next->data == v2)
			{
				n->next = current->next;
				current->next = n;
				cout << "Element Inserted\n";
				return true;
			}
			current = current->next;
		}
		cout << "Element doesn't exist\n";
		return false;
	}

	void DeleteAtStart()
	{
		node<T>*n = new node<T>;
		n = head;
		if (head->next != nullptr)
		{

			head = head->next;
		}
		else if (head ->next== nullptr)
		{
			head = nullptr;
		}
			
		delete n;
	}
	void deleteAll(T const value)
	{
		node<T>* n = new node<T>;
		n -> data = value;
		

		node<T>* current = head;
		while (current->next != nullptr)
		{
			
			if (head->data == value)
			{
				node<T>*n = new node<T>;
				n=head ;
				head = head->next;
				delete n;
				current = head;
				cout << "\nElement deleted\n";
			}

			if (current->next->data == value)
			{
				node<T>*n = new node<T>;
				n->data = value;
				current->next = current->next->next;
				delete n;
				current = head;
				cout << "\nElement deleted\n";
			}
			current = current->next;
		}
		return;

	}

	void print()
	{
		node<T>* current;
		current = head;
		cout << "[ ";
		while (current != nullptr)
		{
			cout  <<current->data<<" ";
			current = current->next;
		}
		cout << "]\n";
	}
	~linkedlist()
	{
		cout << "\nDestructor Called\n";
		while (head != nullptr)
		{
			
			DeleteAtStart();
		}
	}
	void Union(linkedlist<T> a, linkedlist<T> b)
	{
		linkedlist C;
		
		node<T>* current;
		
		C.InsertAtStart(a.head->data);
		current = a.head->next;
		while (current != nullptr)
		{
			C.insertAtEnd(current->data);
			current = current->next;
		}

		current = b.head;

		while (current != nullptr)
		{
			if (!C.search(current->data))
			{
				C.insertAtEnd(current->data);
			}
			current = current->next;
		}
		cout << "C: \n";
		C.print();
	
	}

};



int main()
{
	//Question 1
	linkedlist<int>l1;

	l1.InsertAtStart(2);
	l1.InsertAtStart(6);
	l1.InsertAtStart(7);
	l1.insertAtEnd(9);
	l1.InsertAtStart(7);
	l1.InsertAtStart(8);
	l1.InsertAtStart(9);
	l1.print();
	cout<<endl<<"Search: "<<l1.search(5)<<endl;
	l1.deleteAll(7);


	l1.insertBefore(10, 9);
	l1.print();
	cout << endl << "Search 2: " << l1.search(2) << endl;
	cout << endl << "Search 9: " << l1.search(9) << endl;
	cout << endl << "Search 10: " << l1.search(10) << endl;

	l1.DeleteAtStart();
	l1.print();
	
	//Question 2

	linkedlist<int>A;
	linkedlist<int>B;
	
	A.InsertAtStart(4);
	A.insertAtEnd(1);
	A.insertAtEnd(5);
	A.insertAtEnd(8);
	A.insertAtEnd(3);
	
	B.InsertAtStart(4);
	B.insertAtEnd(6);
	B.insertAtEnd(1);
	B.insertAtEnd(8);
	B.insertAtEnd(5);
	B.insertAtEnd(10);
	B.insertAtEnd(2);
	B.insertAtEnd(7);
	B.insertAtEnd(3);
	B.insertAtEnd(9);

	linkedlist<int> C;
	C.Union(A, B);
	
	system("pause");
	return 0;
}