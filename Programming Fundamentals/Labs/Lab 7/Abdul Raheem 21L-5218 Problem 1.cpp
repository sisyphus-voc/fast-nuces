
#include <iostream>
using namespace std;
void PrintMax(int a, int b, int c);
void PrintMin(int x, int y, int z);

int main()
{
    int num1 = 0, num2 = 0, num3 = 0,max=0,min=0;
    cout << "Enter 3 numbers :";
    cin >> num1 >> num2 >> num3;
    PrintMax(num1, num2, num3);
    PrintMin(num1, num2, num3);

    return 0;

    
}
void PrintMax(int a, int b, int c)
{
    int max = 0;

    if (a == b&&b == c)
    {
    max = a;
    }

    else if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= c && b >= a)
    {
        max = b;


    }
    else if (c >= a && c >= b)
    {
        max = c;
    }
   
    cout << "The maximum number is :" << max << endl;
    
}

void PrintMin(int x, int y, int z)
{

    int min = 0;

    if (x == y&&y == z)
    {
        min = x;
    }

    else if (x <= y && x <= z)
    {
        min = x;
    }
    else if (y <= z && y <= x)
    {
        min = y;
    }
    else if (z <= x && z <= y)
    {
        min = z;
    }
   

    cout << "The minimum number is :" << min << endl;


}