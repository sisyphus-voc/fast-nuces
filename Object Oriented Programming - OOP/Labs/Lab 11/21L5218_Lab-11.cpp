#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;

class Animal
{
public:
	virtual char* speak()
	{
		char* s = new char[20];
		strcpy(s, "speak() called\n");
		return s;

	}
	virtual	 ~Animal()
	{
		cout << "~animal called\n";
	}
};

class Dog:public Animal
{

public:

	 char* speak()
	 {
		 char* s = new char[20];
		 strcpy(s, "woof!!!\n");
		 return s;

	 }
	 ~Dog()
	 {
		 cout << "~dog called\n";
	 }
};
class Cat :public Animal
{

public:

	char* speak()
	{
		char* s = new char[20];
		strcpy(s, "meow!!!\n");
		return s;

	}
	~Cat()
	{
		cout << "~cat called\n";
	}
};
class Sheep :public Animal
{

public:

	char* speak()
	{
		char* s = new char[20];
		strcpy(s, "bleat!!!\n");
		return s;

	}
	~Sheep()
	{
		cout << "~sheep called\n";
	}
};
class Cow :public Animal
{

public:

	char* speak()
	{
		char* s = new char[20];
		strcpy(s, "moo!!!\n");
		return s;

	}
	~Cow()
	{
		cout << "~cow called\n";
	}
};
class Horse :public Animal
{

public:

	char* speak()
	{
		char* s = new char[20];
		strcpy(s, "neigh!!!\n");
		return s;

	}
	~Horse()
	{
		cout << "~horse called\n";
	}
};


int main()
{
	Animal objAnimal;
	Dog  objDog;
	Animal* ptrAnimal = &objAnimal;
	Dog* ptrDog = &objDog;

	cout << objAnimal.speak() << endl;
	cout << objDog.speak() << endl;
	cout << ptrAnimal->speak() << endl;
	cout << ptrDog->speak() << endl;

	//output 
	// Speak() called

	//Woof!!!

	//	Speak() called

	//	Woof!!!

	cout << ptrDog->Animal::speak() << endl;

	ptrAnimal = &objDog;
	cout << ptrAnimal->speak() << endl;
	//before virtual
	//speak() called
		//after virtual
	//woof!!!

	Dog lassie;
	Animal* mypet = &lassie;
	cout << mypet->speak() << endl;
	//before virtual
		//speak() called
	//after virtual
	//woof!!!

	//const int size = 2;
	//Animal* mypets[size];
	//Cat whiskers;
	//Dog mutley;
	//mypets[0] = &whiskers;
	//mypets[1] = &mutley;

	//for (int i = 0; i < size; i++)
	//{
	//	cout << mypets[i]->speak() << endl;
	//}
	//meow!!!

	//woof!!!

	const int size = 5;
	Animal* mypets[size];
	int i = 0;
	while (i < size)
	{

		cout << "Enter your option:\n1.Dog \n2.Cat \n3.Sheep \n4.Cow \n5.Horse \n->";
		switch (_getch())
		{
			
		case '1':
			mypets[i] = new Dog;
			cout << "Dog added at position " << i << endl;
			i++;
			break;
		case '2':
			mypets[i] = new Cat;
			cout << "Cat added at position " << i << endl;
			i++;
			break;
		case '3':
			mypets[i] = new Sheep;
			cout << "Sheep added at position " << i << endl;
			i++;
			break;
		case '4':
			mypets[i] = new Cow;
			cout << "Cow added at position " << i << endl;
			i++;
			break;
		case '5':
			mypets[i] = new Horse;
			cout << "Horse added at position " << i << endl;
			i++;
			break;
		default:
			cout << "Invalid Imput enter again\n\n";
			break;

		}

	

	}
	for (int i = 0; i < size; i++)
	{
		cout << mypets[i]->speak() << endl;
		delete mypets[i];
	}
	return 0;
	//before virtual destructor
	/*woof!!!

		~animal called
		meow!!!

		~animal called
		bleat!!!

		~animal called
		moo!!!

		~animal called
		neigh!!!

		~animal called*/


	//after virtual destructor
	/*neigh!!!

~horse called
~animal called
moo!!!

~cow called
~animal called
bleat!!!

~sheep called
~animal called
meow!!!

~cat called
~animal called
woof!!!

~dog called
~animal called*/

}