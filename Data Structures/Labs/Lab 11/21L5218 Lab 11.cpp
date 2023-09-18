#include<iostream>
#include<cassert>
#include<fstream>
#include<string>

using namespace std;

template <class v>
struct HashItem
{
	int key;
	v value;
	short int status;
};

template <class v>
class HashMap
{
public:
	HashItem<v>* hashArray;
	int capacity;
	int currentElements;

	void doubleCapacity()
	{
		int oldcap = capacity;
		capacity = capacity * 2;
		HashItem<v>* tmparr = new HashItem<v>[capacity];


		for (int i = 0; i < oldcap; i++)
		{
			if (hashArray[i].status == 2)
			{
				int id = hashArray[i].key % capacity;

				for (int j = 1; tmparr[id].status == 2; j++)
				{
					id = getNextCandidateIndex(hashArray[i].key, j);
				}

				tmparr[id].value = hashArray[i].value;
				tmparr[id].status = 2;
				tmparr[id].key = hashArray[i].key;
			}
		}
		
		hashArray = tmparr;
		tmparr = nullptr;
	}
	virtual int getNextCandidateIndex(int key, int i)
	{
		return ((key % this->capacity) + i);
	}

public:
	HashMap()
	{
		currentElements = 0;
		capacity = 10;

		hashArray = new HashItem<v>[capacity];
	}

	HashMap(int const _capacity)
	{
		assert(_capacity > 1);

		currentElements = 0;
		capacity = _capacity;

		hashArray = new HashItem<v>[capacity]();
	}

	bool deleteKey(int const key)
	{
		int id = key % capacity;

		for (int i = 1; hashArray[id].status == 2; i++)
		{
			if (hashArray[id].key == key)
			{
				hashArray[id].status = 1;
				return true;
			}

			id = getNextCandidateIndex(hashArray[key % capacity].key, i);
		}

		return false;
	}

	void insert(int const key, v const value)
	{
		if ((((float)(currentElements)) / ((float)(capacity))) >= 0.75)
		{
			doubleCapacity();
		}

		int id = key % capacity;

		for (int i = 1; hashArray[id].status == 2; i++)
		{
			id = getNextCandidateIndex(hashArray[key % capacity].key, i);
		}

		hashArray[id].value = value;
		hashArray[id].status = 2;
		hashArray[id].key = key;

		currentElements++;
	}

	v* get(int const key)
	{
		int id = key % capacity;

		for (int i = 1; hashArray[id].status == 2; i++)
		{
			if (hashArray[id].key == key)
			{
				return (&hashArray[id].value);
			}

			id = getNextCandidateIndex(hashArray[key % capacity].key, i);
		}

		return nullptr;
	}
	~HashMap()
	{
		delete[]hashArray;
	}
};

template<class v>
class QHashMap : public HashMap<v>
{
public:
	int getNextCandidateIndex(int key, int i)
	{
		return ((key % this->capacity) + (i * i));
	}
};

template<class v>
class DHashMap : public HashMap<v>
{
public:
	int getNextCandidateIndex(int key, int i)
	{
		int first_value = key % this->capacity;
		int second_value = 23 - (key % 23);
		int candidate_index = (first_value + (i * second_value)) % this->capacity;

		return candidate_index;
	}
};

void populateHash(string filename, HashMap<string>* hash)
{
	ifstream fin;
	fin.open(filename);

	int garbage;
	fin >> garbage;
	fin.ignore();

	while (fin.peek() != EOF)
	{
		int key;
		string firstname;

		fin >> key;
		fin >> firstname;

		hash->insert(key, firstname);
	}

	fin.close();
}

int main()
{

	HashMap<string>* map;
	map = new HashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(9);
	map->deleteKey(9);
	assert((map->get(9) == nullptr));
	delete map;


	map = new QHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(98);
	map->deleteKey(98);
	assert(map->get(98) == nullptr);
	delete map;


	map = new DHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(101);
	map->deleteKey(101);
	assert(map->get(101) == nullptr);
	delete map;

	system("pause");
	return 0;
}