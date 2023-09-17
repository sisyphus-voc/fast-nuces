
//********************** average of integars ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 10)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: calculates the sum and average of n positive integers(user provides n) entered
// by the user.
// INPUT: number of integers,integers
// OUTPUT: average
// OTHER:count and sum
// ALGORITHM: take inoput, sum up the integars, divide them by total number and display average.
#include <iostream>
using namespace std;

int main()
{
    //declaring and initializing variables
    int t, c = 0, n, sum=0,avg;

    //taking total amount of integers as input
    cout << "Enter total amount of numbers :";
    cin >> t;


    while (c < t)
    {
        //taking integers as input
        cout << "Enter a positive integer:";
        cin >> n;

        //calculating sum of integers
        sum = sum + n;
        c = c + 1;

    }
    //calculating average
    avg = sum / c;
    
    //displaying average
    cout << "The average is :" << avg << endl;
    return 0;




    
}
