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

template <typename T>
class CircularLinkedList
{
	node<T>* head,* tail;

public:
	CircularLinkedList()
	{
		head = tail = nullptr;
	}
	void Insert(T d)
	{
		node<T>* n = new node<T>;
		n->data = d;

		if (head == nullptr)
		{
			head = n;
			tail = head;
			n->next = tail;
			return;
		}
		else
		{
			if (head->next == head)
			{
				head->next = n;
				n->next = head;
				tail = n;
				return;
			}
			else
			{
				n->next = tail->next;
				tail->next = n;
				tail = n;

				return;
			}
		}
	}
	
	void print()
	{
		node<T>* curr = head;
		bool done = 0;
		cout << "[ ";
		while (!done)
		{
			cout << curr->data << " ";
			curr = curr->next;
			if (curr == head)
			{
				done = 1;
			}
		}
		cout << "]" << endl;
	}
	bool insertBefore(T const v1, T const v2)
	{
		node<T>* curr = head;
		node<T>* n = new node<T>;
		n->data = v1;
		if (head->data == v2)
		{
			n->next = head;
			tail->next = n;
			tail = n;
			cout << "Element Inserted\n";
			return true;
		}
		while (curr->next != tail)
		{
			if (curr->next->data == v2)
			{
				n->next = curr->next;
				curr->next = n;
				cout << "Element Inserted\n";
				return true;
			}
			curr = curr->next;
		}
		cout << "Element doesn't exist\n";
		return false;
	}
	bool Search(T d)
	{
		bool exists = 0;
		if (head->data == d)
		{
			return true;
		}
		else
		{
			node<T>* curr = head->next;
			while (curr != head)
			{
				if (curr->data == d)
					return true;
				curr = curr->next;
			}
		}
		return false;
	}
	void Update(T toFind, T toReplace)
	{
		node<T>* curr = new node<T>;
		curr = head->next;

		if (!(Search(toFind)))
		{
			cout << "The number doesn't exit.\n";
			return;
		}
		else if (head->data == toFind)
		{
			head->data = toReplace;
			return;
		}
		else
		{
			while (curr != head)
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
	bool Check()
	{
		if (tail->next == head)
		{
			return true;
		}
		else
			return false;
	}
};

int main()

{
	CircularLinkedList<int> cll1;
	cll1.Insert(5);
	cll1.print();
	cll1.Insert(7);
	cll1.print();
	cll1.Insert(4);
	cll1.print();
	cll1.Insert(1);
	cll1.print();
	cll1.insertBefore(11, 7);
	cll1.print();
	cout << "Searching # 5: " << cll1.Search(5) << endl;
	cll1.Update(7, 9);
	cll1.print();
	cout << "Is this a circular linked list: " << cll1.Check() << endl;
	return 0;

}