#include <iostream>

using namespace std;

void BubbleSort(int myarr[], int size)
{


    for (int i = 1; i < size; i++)
    {

        for (int j = 0; j < size - i; j++)
        {

            if (myarr[j] > myarr[j + 1])
            {


                int temp = myarr[j];
                myarr[j] = myarr[j + 1];
                myarr[j + 1] = temp;
            }
        }
    }

}

void PrintArray(int* myarr, int size)
{
   
    for (int i = 0; i < size; ++i)
    {
        cout << myarr[i] << "\t";
    }
    cout << endl;
}


void BinarySearch(int* arr, int key, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            cout << "The searched element is Present on index " << mid << endl;
            return ;
        }
        else if (key>arr[mid])
        {
            low = ++mid;
        }
        else
            high = --mid;
    }
    cout<<"Not Present\n";
}

void InsertionSort(int array[], int size) 
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

 
void SelectionSort(int array[], int size)
{
        for (int i = 0; i < size - 1; i++) 
        {
            int minidx = i;
            for (int j = i + 1; j < size; j++) {
    
                
                if (array[j] < array[minidx])
                    minidx = j;
            }
            int temp = array[minidx];
            array[minidx] = array[i];
            array[i] = temp;
    

         
        }
    }
int main()
{

    //Question 1
    cout << "Question 1\n\n";
     int size = 0;
     int* arr;

  
     cout << "Enter Size of Array : ";
     cin >> size;

     arr = new int[size];

     cout << "Enter the elements of the Array : ";
     for (int i = 0; i < size; i++)
     {
         cin >> arr[i];

     }

     BubbleSort(arr, size);
     PrintArray(arr, size);
     int key = 0;
     cout << "Search an element : ";
     cin >> key;

     int low = 0, high = size - 1;

     BinarySearch(arr, key, low, high);

    //Question 2
     cout << "\n\nQuestion 2\n\n";
    int InsertionArr[] = { 8, 2, 10, 1, 3,15 };
    size = sizeof(InsertionArr) / sizeof(InsertionArr[0]);
    cout << "Unsorted array : ";
    PrintArray(InsertionArr, size);
    InsertionSort(InsertionArr, size);
    cout << "Sorted array : ";
    PrintArray(InsertionArr, size);

    //Question 3
    cout << "\n\nQuestion 3\n\n";
    int SelectionArr[] = { 2, 1, 10, 7, 3, 6, 5 };
    size = sizeof(SelectionArr) / sizeof(SelectionArr[0]);
    cout << "Unsorted array : ";
    PrintArray(SelectionArr, size);
    SelectionSort(SelectionArr, size);
    cout << "Sorted array : ";
    PrintArray(SelectionArr, size);

    return 0;

}


