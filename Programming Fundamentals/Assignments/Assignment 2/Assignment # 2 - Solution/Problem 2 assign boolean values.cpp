//********************** Assign boolean values ************************
// AUTHOR: Abdul Raheem (Roll Number: L21-5218) Section 1N
// ASSIGNMENT: Assignment # 2 (Problem # 2)
// PURPOSE: Coding problem assigned by the course instructor
// COMPILER USED: visual studio 2019
// BRIEF DESCRIPTION: Identifies whether the given sides are triangle and what type. 
// INPUT: sides of a triangle
// OUTPUT: Given sides form a triangle and whether it is equilateral,isosceles or scalene.
// ALGORITHM: Take 3 sides as input from user and if those three sides are greater than zero and sum of two sides is greater
// than the third assign booleann value true  to triangle else false,
// If triangle is true and those three sides are equal assign boolean value true to equilateral else false .
// If triangle is true and  2 of three sides are equal assign boolean value true to isosceles else false.
// If triangle is true none of the 3  sides are equal assign boolean value true else false.

#include <iostream>
using namespace std;

int main()
{
    //decleration of variables
    float x, y, z;

    //taking input from user 
    cout << "Enter three numbers :" << endl;
    cin >> x >> y >> z;

     //computing whether the sides form triangle   
    if ((x > 0 && y > 0 && z > 0) && (x + y > z || y + z > x || z + x > y))
    {
      
        cout << "Triangle : " << true << endl;
        
        //computing whether sides form equilateral triangle 
        if (x == y && y == z && z == x)
        {
            cout << "equilateral : " << true << endl;
        }
        else
        {
            cout << "equilateral : " << false << endl;
        }

        //computing whether sides form isosceles triangle
        if (x == y || y == z || z == x)
        {
            cout << "isosceles : " << true << endl;
        }
        else
        {
            cout << "isosceles : " << false << endl;
        }

        //computing whether sides form scalene triangle
        if (x != y && y != z && z != x)
        {
            cout << "scalene : " << true << endl;
        }
        else
        {
            cout << "scalene : " << false << endl;
        }

    }
    //displayin output if sides dont form a triangle 
    else
    {
        cout << "Triangle : " << false << endl;
        cout << "equilateral : " << false << endl;
        cout << "isosceles : " << false << endl;
        cout << "scalene : " << false << endl;
    }

  
    return 0;



}
