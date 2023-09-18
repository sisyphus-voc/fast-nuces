#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename k, typename v>
class HeapItem
{
public:
	k key;
	v value;

	HeapItem()
	{
		key = k{};
		value = v{};
	}
};

template <typename k, typename v>
class MinHeap
{
	HeapItem<k,v>* arr;
	int capacity;
	int totalItems;

public:

	MinHeap()
	{
		capacity = 0;
		totalItems = 0;
		arr = nullptr;
	}

	MinHeap(int c)
	{
		capacity = c;
		totalItems = 0;
		arr = new HeapItem<k,v>[c];
	}

	int parent(int idx)
	{
		return (idx - 1) / 2;
	}

	int left(int idx)
	{
		return (idx * 2) + 1;
	}

	int right(int idx)
	{
		return (idx * 2) + 2;
	}

	void inserKey(k key, v val)
	{
		if (arr == nullptr)
		{
			capacity = 10;
			totalItems = 1;

			arr = new HeapItem<k, v>[capacity];

			arr[0].key = key;
			arr[0].value = val;

			return;
		}
		if (totalItems == capacity)
		{
			int newcap = capacity * 2;
			HeapItem<k, v>* temp = new HeapItem<k, v>[newcap];

			for (int i = 0; i < capacity; i++)
			{
				temp[i].key = arr[i].key;
				temp[i].value = arr[i].value;
			}

			arr = temp;

			temp = nullptr;
			capacity = capacity * 2;
		}

		totalItems++;

		int itemidx = totalItems - 1;
		arr[itemidx].key = key;
		arr[itemidx].value = val;

		while (itemidx != 0 && arr[parent(itemidx)].key > arr[itemidx].key)
		{
			HeapItem<k, v> temp = arr[parent(itemidx)];
			arr[parent(itemidx)] = arr[itemidx];
			arr[itemidx] = temp;

			itemidx = parent(itemidx);
		}
	}

	void getMin(v& val)
	{
		if (totalItems == 0)
		{
			cout << "Heap is empty  !" << endl;
			return;
		}
		val = arr[0].value;
	}

	void deleteMin()
	{
		if (totalItems == 0)
		{
			cout << "Heap is empty !" << endl;
			return;
		}

		if (totalItems == 1)
		{
			arr[0].key = k{};
			arr[0].value = v{};
			totalItems--;
			return;
		}

		arr[0].key = arr[totalItems - 1].key;
		arr[0].value = arr[totalItems - 1].value;
		totalItems--;

		HeapDown(0);
	}

	void HeapDown(int idx)
	{
		int l = left(idx);
		int r = right(idx);

		int smallest = idx;

		if (l < totalItems && arr[l].key < arr[smallest].key)
		{
			smallest = l;
		}
		if (r < totalItems && arr[r].key < arr[smallest].key)
		{
			smallest = r;
		}

		if (smallest != idx)
		{
			HeapItem<k, v> temp = arr[idx];
			arr[idx] = arr[smallest];
			arr[smallest] = temp;

			HeapDown(smallest);
		}
	}

	void setCapacity(int cap)
	{
		if (!isEmpty())
		{
			cout << "Memory will be deleted";
			return;
		}
		capacity = cap;

		arr = new HeapItem<k, v>[capacity];
	}

	bool isEmpty()
	{
		if (totalItems == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	~MinHeap()
	{
		if (!arr)
		{
			delete[] arr;
		}
	}
};

class student
{
	int roll_no;
	string name;
	float cgpa;

public:
	student()
	{
		roll_no = 0;
		name = "  ";
		cgpa = 0;
	}

	student(int r, string n, float cg)
	{
		roll_no = r;
		name = n;
		cgpa = cg;
	}

	friend ostream& operator<<(ostream& cout, const student& std)
	{
		cout << "\nRoll No: " << std.roll_no << endl << "Name: " << std.name << endl << "CGPA: " << std.cgpa << endl;

		return cout;
	}

};

void BuildStudentHeap(string fileName, MinHeap<int, student> &stdHeap)
{
	ifstream fin;

	fin.open(fileName);

	int capacity = 0;
	fin >> capacity;
	stdHeap.setCapacity(capacity);

	int roll = 0;
	string name = " ";
	float cgpa = 0.0;

	while (fin.peek() != EOF)
	{
		fin >> roll;
		fin >> name;
		fin >> cgpa;

		stdHeap.inserKey(roll, student(roll, name, cgpa));
	}

	fin.close();
}

int main()
{
	MinHeap <int, student> stdHeap;

	BuildStudentHeap("students.txt" , stdHeap);
	while (!stdHeap.isEmpty())
	{
		student s;
		stdHeap.getMin(s);
		cout << s << endl << endl;
		stdHeap.deleteMin();
	}
	system("pause");
	return 0;
}