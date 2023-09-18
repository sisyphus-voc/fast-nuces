//Abdul Raheem
//21L-5218
//BCS-3H


#include <iostream>
using namespace std;


template <class T >
class node
{
public:
	node* next;
	T data;
	node()
	{
		//data = NULL;
		next = NULL;
	}
	node(T d)
	{
		next = NULL;
		data = d;

	}
};


template <class T >
class SortedSet
{
private:
	node<T> *head,*tail;
public:

	SortedSet()
	{
	
		head = NULL;
		tail = NULL;
	}
	void InsertAtHead(T const element)
	{
		node<T>* n = new node<T>;
		n->data = element;

		if (head == nullptr)
		{
			head = n;
			tail = n;
			return;
		}
		else 
		{
			n->next = head;
			head = n;
			return;
		}
	}
	void InsertAtEnd(T const element)
	{
		node<T>* n = new node<T>;
		n->data = element;
		n->next = nullptr;
		if (n->data > tail->data)
		{
			tail->next = n;
			tail = n;

		}


		return;
	}
	


	void Insert(T const data)
	{

		node<T>* n = new node<T>(data);
		if (head == nullptr || n->data < head->data)
		{
			InsertAtHead(data);
		}
		else if (n->data > tail->data)
		{
			InsertAtEnd(data);
			
		}
		else
		{
			node<T>* current = head;
			while (current != nullptr)
			{
				if (data > current->data && data < current->next->data)
				{

					n->next = current->next;
					current->next = n;
					
				}
				current = current->next;
			}
			
		}
		

		return;
	}


		
	
	void Delete(T const index)
	{
		node<T>* n = new node<T>;
		n->data = index;


		node<T>* current = head;
		if (head == nullptr)
		{
			cout << "Invalid Delete. The linked list is empty\n";
			return;
		}

		else if (tail->data == index && head->data !=index)
		{
			current = head;
			while (current->next != tail)
			{
				current = current->next;
			}
			node<T>* n = new node<T>;
			n = tail;
			tail = current;
			tail->next = nullptr;
			delete n;
			return;
		}
		else
		{
			

			while (current != nullptr)
			{

				if (head->data == index)
				{
					node<T>* n = new node<T>;
					n = head;
					head = head->next;
					delete n;
					return;


				}
				
				else if (current->next->data == index)
				{
					node<T>* n = new node<T>;
					n->data = index;
					current->next = current->next->next;
					delete n;
					return;


				}
				current = current->next;
			}
		}
		return;
	}
	void print() const
	{
		cout << "[ ";
		node<T>* current = head;

		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;

		}
		cout << "]\n";
	}
	void Union(SortedSet<T> const& otherSet)
	{
		node<T>* other_current = otherSet.head;

		while (other_current != nullptr)
		{
			node<T>* n = new node<T>(other_current->data);
			if (head == nullptr || n->data < head->data)
			{
				InsertAtHead(other_current->data);
			}
			else if (n->data > tail->data)
			{
				InsertAtEnd(other_current->data);

			}

			other_current = other_current->next;

		}


		node<T>* current = head;
		other_current = otherSet.head;

		node<T>* prev = head;
		current=head->next;
		node<T>* next = head->next->next;
		while (next->next != nullptr && other_current != nullptr)
		{
			node<T>* n = new node<T>(other_current->data);
			if (n->data == prev->data || n->data == current->data || n->data == next->data)
			{
				other_current = other_current->next;
				continue;
			}

			else 
			{
				if (n->data > prev->data && n->data < current->data)
				{
					n->next = current;
					prev->next = n;

				}
				else if (n->data > current->data && n->data < next->data)
				{
					n->next = next;
					current->next = n;
					prev = current;
					current = current->next;
					other_current = other_current->next;
					continue;
				}
				else if (n->data >= next->data && next->next != nullptr)
				{
					prev = current;
					current = next;
					next = next->next;
					continue;
				}
				if (!(n->data > next->data))
				{
					other_current = other_current->next;
				}


			}
			
			
		}


	}
	void Rotate(int const k)
	{
		int count = 0;
		while (count < k)
		{
			
			tail->next = head;
			tail = tail->next;
			head = head->next;
			tail->next = NULL;
			count++;
		}
		return;
	}

	void DeleteAtStart()
	{
		node<T>* n = new node<T>;
		n = head;
		if (head->next != nullptr)
		{
			head = head->next;
		}
		else if (head->next == nullptr)
		{
			head = nullptr;
		}

		delete n;
	}
	void Reverse()
	{
	
		node<T>* prev, *current, *next;
		prev = nullptr;
		current = head;
		next = head;
		while (next != nullptr)
		{
			next = next->next;
			current->next = prev;
			prev = current;
			current = next;

		}
		tail = head;
		head = prev;

	}
	~SortedSet()
	{
		cout << "\nDestructor Called\n";
		while (head != nullptr)
		{

			DeleteAtStart();
		}
	}

};

int GetNumberOfRotations()
{
	int rotations = 0;
	cout << "Enter number of rotations:\n";
	cin >> rotations;
	while (!cin.good() || rotations<0)
	{
		if (!cin.good())
		{

			cout << "Invalid Input (Wrong Data Type)\n";
			cin.clear();
			cin.ignore();
			cout << "=>";
			cin >> rotations;
		}
		else if (rotations < 0)
		{
			cout << "Invalid Input (Rotations should >= 0)\n";
			cout << "=>";
			cin >> rotations;
		}
	}
	return rotations;
}

int main()
{
	SortedSet<int> S1,S2,S3,S4,S5,S6;
	//deleting one element
	S5.Insert(5);
	cout << "\nS5: \n";
	S5.print();
	cout << "\nS5: (after deleting last element)\n";
	S5.Delete(5);
	S5.print();
	//deleting from empty linked list
	cout << "\nS5: (after deleting from empty list) \n";
	S5.Delete(5);
	S5.print();
	S5.Insert(6);
	cout << "\nS5: \n";
	S5.print();
	//Question 1
	S1.Insert(2);
	S1.Insert(5);
	S1.Insert(-1);
	S1.Insert(2);
	S1.Insert(3);
	S1.Insert(4);

	S1.Insert(12);
	S1.Insert(10);

	S1.Insert(0);
	cout << "\nS1: \n";
	S1.print();

	//deleting at end
	S1.Delete(12);
	cout << "\nS1: (after deleting at end) \n";
	S1.print();

	S2.Insert(-1);
	S2.Insert(6);
	S2.Insert(14);
	S2.Insert(11);
	S2.Insert(10);
	S2.Insert(-15);
	S2.Insert(9);
	S2.Insert(2);
	S2.Insert(-16);
	cout << "\nS2: \n";
	S2.print();

	//deleting from head
	S2.Delete(-16);
	cout << "\nS2: (after deleting from head)\n";
	S2.print();

	S1.Union(S2);
	cout << "\nS1:\t (After Union) \n";
	S1.print();

	//deleting betwee
	S1.Delete(5);
	cout << "\nS1: (after deleting between) \n";
	S1.print();

	//Question 2
	S3.Insert(10);
	S3.Insert(20);
	S3.Insert(30);
	S3.Insert(40);
	S3.Insert(50);
	S3.Insert(60);
	cout << "S3: \n";
	S3.print();

	int k;
	k=GetNumberOfRotations();
	
	S3.Rotate(k);
	cout << "\nS3:\t (After Rotation) \n";
	S3.print();

	S4.Insert(1);
	S4.Insert(2);
	S4.Insert(3);
	S4.Insert(4);
	
	

	//Question 3
	cout << "\nS4:\t (Before Reverse) \n";
	S4.print();
	S4.Reverse();
	cout << "\nS4:\t (After Reverse) \n";
	S4.print();

	
	return 0;
}