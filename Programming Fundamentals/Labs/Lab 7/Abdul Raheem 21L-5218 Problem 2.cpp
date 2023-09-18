#include <iostream>
using namespace std;
bool IsPrime(int num);

int main()
{
    int num1 = 0, num2 = 0,count=0;
    cout << "Enter two numbers : " << endl;
    cin >> num1 >> num2;
    while(count <= num2)
    {
        if(IsPrime(count))
        {
            cout << count << " "; 
        }
        count++;
    }
    
   
  
    
}
bool IsPrime (int num)
{
    bool Isprime=true;
    if (num == 0 || num == 1)
    {
        Isprime = false;
    }
    for (int c = 2; c<=num/2; c++)
    {
        if (num%c== 0)
        {
            Isprime = false;
        }


    }
    return Isprime;

}
