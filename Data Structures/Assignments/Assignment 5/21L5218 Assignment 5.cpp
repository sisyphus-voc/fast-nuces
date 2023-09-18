#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

class IntervalHeap
{
private:
	int minCount, maxCount;
	bool minFilled;
	const int minHeap = 0;
	const int maxHeap = 1;
public:
	int** h;
	int hsize;
	int maxsize;

	IntervalHeap(int s = 100)
	{
		maxsize = s;
		hsize = minCount = maxCount = 0;
		h = new int* [2];
		h[0] = new int[maxsize];
		h[1] = new int[maxsize];
		minFilled = false;
	}

	bool isFull()
	{
		return (hsize == maxsize);
	}

	bool isEmpty()
	{
		return (hsize == 0);
	}

	int getParent(int idx)
	{
		return ((idx - 1) / 2);
	}

	int getLeftChild(int idx)
	{
		return ((2 * idx) + 1);
	}

	int getRightChild(int idx)
	{
		return ((2 * idx) + 2);
	}

	void reheapUpForMin(int parent, int idx)
	{
		while (idx != 0 && h[minHeap][parent] > h[minHeap][idx])
		{
			swap(h[minHeap][parent], h[minHeap][idx]);
			idx = parent;
			parent = getParent(parent);
		}
	}

	void reheapUpForMax(int parent, int idx)
	{
		while (idx != 0 && h[maxHeap][parent] < h[maxHeap][idx])
		{
			swap(h[maxHeap][parent], h[maxHeap][idx]);
			idx = parent;
			parent = getParent(parent);
		}
	}

	void reheapDownForMin(int idx, int finidx)
	{
		int minChild, leftChild = getLeftChild(idx), rightChild = getRightChild(idx);

		while (leftChild <= finidx)
		{
			if (leftChild == finidx)
				minChild = leftChild;
			else
				minChild = (h[minHeap][leftChild] < h[minHeap][rightChild]) ? leftChild : rightChild;

			if (h[minHeap][minChild] < h[minHeap][idx])
			{
				swap(&h[minHeap][minChild], &h[minHeap][idx]);
				idx = minChild;
			}

			else break;

			leftChild = getLeftChild(idx);
			rightChild = getRightChild(idx);
		}
	}

	void reheapDownForMax(int idx, int finidx)
	{
		int maxChild, leftChild = getLeftChild(idx), rightChild = getRightChild(idx);

		while (leftChild <= finidx)
		{
			if (leftChild == finidx)
				maxChild = leftChild;
			else
				maxChild = (h[maxHeap][leftChild] > h[maxHeap][rightChild]) ? leftChild : rightChild;

			if (h[maxHeap][maxChild] > h[maxHeap][idx])
			{
				swap(&h[maxHeap][maxChild], &h[maxHeap][idx]);
				idx = maxChild;
			}

			else break;

			leftChild = getLeftChild(idx);
			rightChild = getRightChild(idx);
		}
	}

	void insert(int val)
	{
		if (isFull())
		{
			cout << "\nOverflow: Cannot insert a new element\n";
			return;
		}

		if (hsize == 0)
		{
			h[minHeap][0] = val;

			minFilled = true;
			minCount += 1;
			hsize += 1;
			return;
		}

		if (hsize == 1)
		{
			h[maxHeap][0] = val;
			if (h[maxHeap][0] < h[minHeap][0])
				swap(h[maxHeap][0], h[minHeap][0]);

			minFilled = false;
			maxCount += 1;
			hsize += 1;
			return;
		}

		int idx = static_cast<int>(hsize / 2);
		int parent = getParent(idx);

		if (h[minHeap][parent] <= val && val <= h[maxHeap][parent])
		{
			if (hsize % 2 == 0)
			{
				h[minHeap][idx] = val;

				minCount += 1;
				minFilled = true;
			}

			if (hsize % 2 == 1)
			{
				h[minFilled][idx] = val;
				if (h[maxHeap][idx] < h[minHeap][idx])
					swap(&h[maxHeap][idx], &h[minHeap][idx]);

				if (minFilled) maxCount += 1;
				if (!minFilled) minCount += 1;
				minFilled = false;
			}
		}

		else if (val < h[minHeap][parent])
		{
			if (hsize % 2 == 1)
			{
				h[minFilled][idx] = val;
				if (h[maxHeap][idx] < h[minHeap][idx])
					swap(&h[maxHeap][idx], &h[minHeap][idx]);

				reheapUpForMin(parent, idx);

				if (minFilled) maxCount += 1;
				if (!minFilled) minCount += 1;
				minFilled = false;
			}

			else
			{
				h[minHeap][idx] = val;

				reheapUpForMin(parent, idx);

				minCount += 1;
				minFilled = true;
			}
		}

		else if (val > h[maxHeap][parent])
		{
			if (hsize % 2 == 1)
			{
				h[minFilled][idx] = val;
				if (h[maxHeap][idx] < h[minHeap][idx])
					swap(&h[maxHeap][idx], &h[minHeap][idx]);

				reheapUpForMax(parent, idx);

				if (minFilled) maxCount += 1;
				if (!minFilled) minCount += 1;
				minFilled = false;
			}

			else
			{
				h[maxHeap][idx] = val;
				reheapUpForMax(parent, idx);

				maxCount += 1;
				minFilled = false;
			}
		}

		hsize += 1;
	}

	void remove()
	{
		maxCount -= 1;
		minCount -= 1;
		hsize -= 2;

		h[minHeap][0] = h[minHeap][minCount];
		reheapDownForMin(0, minCount);

		h[maxHeap][0] = h[maxHeap][maxCount];
		reheapDownForMax(0, maxCount);
	}

	void update(int idx, int minVal, int maxVal)
	{
		if (idx > static_cast<int>(hsize / 2))
		{
			cout << "\nExceeds bounds: Cannot update node\n";
			return;
		}

		if (minVal < h[minHeap][idx])
		{
			h[minHeap][idx] = minVal;
			reheapUpForMin(getParent(idx), idx);
		}

		else if (minVal > h[minHeap][idx])
		{
			h[minHeap][idx] = minVal;
			reheapDownForMin(idx, minCount - 1);
		}

		if (maxVal > h[maxHeap][idx])
		{
			h[maxHeap][idx] = maxVal;
			reheapUpForMax(getParent(idx), idx);
		}

		else if (maxVal < h[maxHeap][idx])
		{
			h[maxHeap][idx] = maxVal;
			reheapDownForMax(idx, maxCount - 1);
		}
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "\nNull: Heap is empty\n";
			return;
		}

		int totalItems = 0;

		if (hsize >= 2)
			totalItems = hsize / 2;
		else
			totalItems = hsize;

		if (hsize % 2)
		{
			totalItems += 1;
		}


		cout << "minFilled : " << minFilled << endl;
		cout << "Total elements : " << hsize << endl << "[ ";

		for (int i = 0; i < totalItems; i++)
		{
			cout << "[" << h[minHeap][i] << ", " << h[maxHeap][i] << "]";
			if (i + 1 != totalItems)
				cout << ", ";
		}

		cout << " ]" << endl;

		cout << "Max Heap : " << maxCount << endl << "[ ";

		for (int i = 0; i < maxCount; i++)
		{
			cout << h[maxHeap][i];
			if (i + 1 != maxCount)
				cout << ", ";
		}

		cout << " ]" << endl;

		cout << "Min Heap : " << minCount << endl << "[ ";
		for (int i = 0; i < minCount; i++)
		{
			cout << h[minHeap][i];
			if (i + 1 != minCount)
				cout << ", ";
		}

		cout << " ]" << endl;
	}
};

template <typename T>
struct HashItem
{
	int key;
	T value;
	short status;
};

template <class T>
class HashMap
{
private:

	HashItem<T>* hashArray;
	int capacity;
	int currentElements;

	virtual int getNextCandidateIndex(int key, int i)
	{
		if (((key % capacity) + i) > (capacity - 1))
			return ((key % capacity) + i) % capacity;
		else
			return (key % capacity) + i;
	}

	void doubleCapacity()
	{
		HashItem<T>* tempHashArray = new HashItem<T>[capacity * 2];

		for (int i = 0; i < capacity; i++)
		{
			if (hashArray[i].status == 2)
			{
				int myIndex = hashArray[i].key % capacity;
				int j = 1;

				while (tempHashArray[myIndex].status == 2)
				{
					myIndex = getNextCandidateIndex(hashArray[i].key, j);
					j += 1;
				}

				tempHashArray[myIndex].key = hashArray[i].key;
				tempHashArray[myIndex].value = hashArray[i].value;
				tempHashArray[myIndex].status = 2;
			}
		}

		delete[] hashArray;
		capacity *= 2;
		hashArray = tempHashArray;
		tempHashArray = nullptr;
	}

public:

	HashMap()
	{
		hashArray = new HashItem<T>[10];
		capacity = 10;
		currentElements = 0;

		for (int i = 0; i < capacity; i++)
			hashArray[i].status = 0;
	}

	HashMap(const int capacity)
	{
		assert(capacity > 1 && "Size Error: Capacity should be > 1");
		hashArray = new HashItem<T>[capacity];
		capacity = capacity;
		currentElements = 0;

		for (int i = 0; i < capacity; i++)
			hashArray[i].status = 0;
	}

	void insert(int const key, T const val)
	{
		if (static_cast<double>(currentElements) / static_cast<double>(capacity) >= 0.75)
			doubleCapacity();


		int idx = key % capacity;
		int i = 1;

		while (hashArray[idx].status == 2)
		{
			idx = getNextCandidateIndex(key, i);
			i += 1;
		}

		hashArray[idx].key = key;
		hashArray[idx].value = val;
		hashArray[idx].status = 2;

		currentElements += 1;
	}

	bool deleteKey(const int key)
	{
		int idx = key % capacity;
		int i = 1;

		while (i < capacity)
		{
			if (hashArray[idx].key == key)
			{
				hashArray[idx].status = 1;
				currentElements -= 1;
				return true;
			}

			idx = getNextCandidateIndex(key, i);
			i += 1;
		}

		return false;
	}

	T* get(const int key)
	{
		int idx = key % capacity;
		int i = 1;

		while (i < capacity)
		{
			if (hashArray[idx].key == key && hashArray[idx].status == 2)
				return &hashArray[idx].value;

			idx = getNextCandidateIndex(key, i);
			i += 1;
		}

		return nullptr;
	}

	~HashMap()
	{
		delete[] hashArray;
		hashArray = nullptr;
		capacity = currentElements = 0;
	}

	int getCapacity() const
	{
		return capacity;
	}
};

template <class T>
class QHashMap : public HashMap<T>
{
private:
	virtual int getNextCandidateIndex(int key, int i)
	{
		if (((key % this->getCapacity()) + (i * i)) > (this->getCapacity() - 1))
			return ((key % this->getCapacity()) + (i * i)) % this->getCapacity();
		else
			return (key % this->getCapacity()) + (i * i);
	}
};

template <class T>
class DHashMap : public HashMap<T>
{
private:
	virtual int getNextCandidateIndex(int _key, int _i)
	{
		int first_value = _key % this->getCapacity();
		int second_value = (2 - (_key % 2));
		int index = (first_value + (_i * second_value)) % this->getCapacity();

		return index;
	}
};

void populateHash(string _filename, HashMap<string>* _myHashMap)
{
	ifstream getData;
	getData.open(_filename);

	if (!getData)
	{
		cout << "\nFile error: Could not open file\n";
		return;
	}

	while (getData.peek() != EOF)
	{
		int ID = 0;
		string fname = "", lname = "";

		getData >> ID >> fname >> lname;
		fname += " " + lname;

		_myHashMap->insert(ID, fname);
	}

	getData.close();
}

int main()
{
	// Q1 
	IntervalHeap myHeap(50);

	myHeap.insert(2);
	myHeap.insert(30);
	myHeap.insert(3);
	myHeap.insert(17);
	myHeap.insert(4);
	myHeap.insert(15);
	myHeap.insert(4);
	myHeap.insert(12);
	myHeap.insert(3);
	myHeap.insert(11);
	myHeap.insert(5);
	myHeap.insert(10);
	myHeap.insert(6);
	myHeap.insert(15);
	myHeap.insert(4);
	myHeap.insert(10);
	myHeap.insert(5);
	myHeap.insert(11);
	myHeap.insert(5);
	myHeap.insert(9);
	myHeap.insert(4);
	myHeap.insert(7);
	myHeap.insert(8);
	myHeap.insert(8);
	myHeap.insert(7);
	myHeap.insert(9);
	myHeap.insert(40);
	myHeap.insert(-1);
	myHeap.insert(63);
	myHeap.insert(64);
	myHeap.display();
	cout << endl;
	myHeap.remove();
	myHeap.remove();
	myHeap.display();
	cout << endl;
	myHeap.update(0, -2, 21);
	myHeap.display();

	// Q2

	/*HashMap<string>* map;
	map = new HashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(9) << endl;
	map->deleteKey(9);
	assert(map->get(9) == nullptr);
	delete map;

	map = new QHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(98) << endl;
	map->deleteKey(98);
	assert(map->get(98) == nullptr);
	delete map;

	map = new DHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(101) << endl;
	map->deleteKey(101);
	assert(map->get(101) == nullptr);
	delete map;*/

	return 0;
}