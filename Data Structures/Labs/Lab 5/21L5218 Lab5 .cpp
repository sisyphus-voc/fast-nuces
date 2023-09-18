//21L-5218

#include <iostream>
#include <string>

using namespace std;



//Q 1
template <typename T>
class node
{
public:
	T data;
	node<T>* next;
	node()
	{
		next = NULL;
	}
};


template <typename T>
class stack
{
private:
	int size;
	node<T>* top;
public:
	stack()
	{
		top = nullptr;
		size = 0;

	}

	int Size() //O(1)
	{
		return size;
	}


	bool isEmpty()//O(1)
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	bool Top(T& val)//O(1)
	{
		if (isEmpty())
		{
			return false;
		}
		val = top->data;
		return true;
	}
	void push(T const& e)//O(1)
	{
		node<T>* n = new node<T>;
		n->data = e;
		if (top == nullptr)
		{
			
			top = n;
			top->next = NULL;
			size++;
			return;
		}
		n->next = top;
		top = n;
		size++;
		return;
	}
	void pop()//O(1)
	{
		node<T>* n = new node<T>;
		
		if (isEmpty())
		{
			cout << "The stack is empty\n";
			
		}
		else
		{
			n = top;
			top = top->next;
			size--;
			delete n;
			
		}
	}

	

	

	void print()//O(n)
	{
		node<T>* curr = new node<T>;
		curr = top;

		for (int i = 0; i < size ; i++)
		{
			cout << curr->data<<" ";
			curr = curr->next;
		}
		cout << endl;
	}

};


//Q 2

//Time complexity O(n)
void RemoveTripleAdjacent(string& sen)
{

	stack<char> temp;
	char topChar;

	if (sen!="\0")
	{
		int count = 0;
		temp.push(sen[0]);


		for (int i = 1; sen[i] != '\0'; i++)
		{
			temp.Top(topChar);

		
			if (sen[i] != topChar)
			{
				temp.push(sen[i]);
			}
			else if (sen[i] ==topChar)
			{
				temp.push(sen[i]);
				count++;
			}
			if (count == 2)
			{
				temp.pop();
				temp.pop();
				temp.pop();
				count = 0;
			}

		}
		
		stack<char> temp2;
		
		while (!(temp.isEmpty()))
		{
			temp.Top(topChar);
			temp2.push(topChar);
			temp.pop();
		}
	
		int i = 0;
		while (!(temp2.isEmpty()))
		{
			temp2.Top(topChar);
			sen[i] = topChar;
			temp2.pop();
			i++;
		}
		sen[i] = '\0';

	sen.resize(i);
	}
	else
		cout << "stack is empty\n";
}

//Q 3 
//Time complexity O(n)
bool isBalanced(string exp)
{
	stack<char> temp;
	char topChar;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{')
		{
			temp.push(exp[i]);
		}
		else
		{
			temp.Top(topChar);
			if (topChar == '{' && exp[i] == '}')
			{
				temp.pop();
			}
			else if (topChar == '[' && exp[i] == ']')
			{
				temp.pop();
			}
			else if (topChar == '(' && exp[i] == ')')
			{
				temp.pop();
			}
			
		}
	}
	if (temp.isEmpty())
	{
		return true;
	}
	else
		return false;
}

int main()
{
	stack<int> S1;
	S1.push(5);

	S1.push(6);
	S1.push(7);
	S1.push(8);
	S1.push(9);
	S1.print();
	S1.pop();
	S1.print();
	string s;
	
	s = "azxxxy";
	cout << s << endl;
	RemoveTripleAdjacent(s);
	cout << s<<endl;
	s = "azxxxxxxy";
	cout << s << endl;
	RemoveTripleAdjacent(s);
	cout << s << endl;

	string bracket1, bracket2,bracket3,bracket4,bracket5;
	bracket1 = "{[{}{}]}[()]";
	bracket2 = "{{}{}}";
	bracket3 = "{}[]()";
	bracket4 = "{()}[)";
	bracket5 = "{(})";
	
	cout << isBalanced(bracket1)<<endl;
	cout << isBalanced(bracket2)<<endl;
	cout << isBalanced(bracket3) << endl;
	cout << isBalanced(bracket4) << endl;
	cout << isBalanced(bracket5) << endl;
	

}
