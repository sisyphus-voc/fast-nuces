#include <iostream>
using namespace std;

int StringLength(char* str)
{
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}
int GetCharacterCount(char* myString,char c)
{
	int count = 0;
	for (int i = 0; myString[i] != '\0'; i++)
	{
		if (myString[i] == c)
		{
			count++;
		}
	}
	return count;
}

int GetCharacterCountInSentence(char* myString, char c)
{
	int count = 0;
	for (int i = 0; myString[i] != '\0'; i++)
	{
		if (myString[i] == c)
		{
			count++;
		}
	}
	return count;
}


void ModifyString(char* myStr, char chartofind,char chartoreplace)

{
	for (int i = 0; myStr[i] != '\0'; i++)
	{
		if (myStr[i] == chartofind)
		{
			myStr[i] = chartoreplace;
		}
	}

}
void RemoveCharacter(char* myStr, char toremove)

{
	for (int i = 0; myStr[i] != '\0'; i++)
	{
		if (myStr[i] == toremove)
		{
			myStr[i] = ' ';
		}
	}

}
void TrimStart(char* myStr)
{
	int c = 0;
	
		while (myStr[c] == ' ')
		{
			c++;
		}
		for (int i = 0; myStr[i] != '\0'; i++)
		{
			myStr[i] = myStr[c];
			c++;
		}
		
}
void TrimEnd(char* myStr)
{
	
	int c = 0;
	c=strlen(myStr);

	while (myStr[c] == ' ')
	{
		c--;
	}
	for (int i = strlen(myStr); i>=0; i--)
	{
		myStr[i] = myStr[c];
		c--;
	}
}
int main()
{
	///////Exercise 1 i
	/*char charArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };
	cout << charArray << endl;*/
	// Output : Hello World╠╠╠╠╠ÿ≈♥¬@·/☺c-

	///////////Exercise 1 ii

	/*char myStr1[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
	cout << myStr1 << endl;*/
	// Output : Hello World

	//difference between 3 arrays: str1 is c-string as it has null character

	////////////Exercise 1 iii
	/*int length = StringLength(myStr1);
	cout << "mystr1 length : " << length << endl;*/

	/////////////////Exercise 1 iv
	/*char myStr1[] = "Hello World";
	cout << myStr1 << endl;*/

	///////////////Exercise 1 v
	/*char myStr1[20] = "Hello World";
	cout << myStr1 << endl;*/


	///////////////Exercise 1 vi

	/*char myStr1[5] = "Helo";
	cout << "Initial String:\t" << myStr1 << endl;
	int len = 0;
	for (; myStr1[len] != '\0'; len++);
	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
	cout << "Enter another string of size 4 :";
	cin >> myStr1;
	cout << "String entered by the user is:" << myStr1 << endl;
	for (len = 0; myStr1[len] != '\0'; len++);
	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
	cout << "Enter another string of size 5 or Greater :";
	cin >> myStr1;
	cout << "String entered by the user is:" << myStr1 << endl;
	for (len = 0; myStr1[len] != '\0'; len++);
	cout << "Lenght of myStr1:\t" << len << endl << endl << endl;
	cout << "Program is going to terminate.\n";*/

	//The program crashed because a string of size 5 or greater can't accomodate null character



	/////////////////////Exercise 2
	
	char* myString = new char[80];
	char ch;
	cout << "myString : "<<endl;

	cin >> myString;
	cout << "ch : " << endl;
	cin >> ch;

	int totalOccurrences = 0;
	totalOccurrences=GetCharacterCount(myString, ch);
	cout << "myString : " << myString << endl;
	cout << "ch : " << ch<< endl;
	cout << "Total No of Occurences : " << totalOccurrences<< endl;


	////////////////////Exercise 3

	cout << "myString : " << endl;
	cin.ignore();
	cin.getline(myString,50);
	cout << "ch : " << endl;
	cin >> ch;

	totalOccurrences = 0;
	totalOccurrences = GetCharacterCountInSentence(myString, ch);
	cout << "myString : " << myString << endl;
	cout << "ch : " << ch << endl;
	cout << "Total No of Occurences : " << totalOccurrences << endl;

	////////Practice Problems

	char charToFind;
	char charToReplace;
	char* myStr = new char[50];
	cout << "Input String : " << endl;
	cin.ignore();
	cin.getline(myStr, 50);
	cout << "charToFind : " << endl;
	cin >> charToFind;
	cout << "charToReplace : " << endl;
	cin >> charToReplace;
	
	ModifyString(myStr, charToFind, charToReplace);
	cout << "Modified String : " << myStr << endl;

	char charToRemove;
	cout << "character to remove : " << endl;
	cin >> charToRemove;
	RemoveCharacter(myStr, charToRemove);
	cout << "Modified String with removed char : " << myStr << endl;

	cout << "Before Trim Start : " << endl;
	cin.ignore();
	cin.getline(myStr, 50);
	TrimStart(myStr);
	cout << "After Trim Start : " << myStr << endl<<endl;

	cout << "Before Trim End : " << endl;
	cin.ignore();
	cin.getline(myStr, 50);
	TrimEnd(myStr);
	cout << "After Trim End: " << myStr << endl << endl;

	return 0;
}