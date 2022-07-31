//----------------- SEQUENTIAL SEARCH -------------------

#include <iostream>
#include <ctime> // For random values

using namespace std;

int SequentialSearch(int Arr[], int size, int key)
{
    /* Function with parameter
    Arr : Array
    size: size of Array
    key : VAlue to find   */

    for (int i = 0; i < size; i++) // loop till the size
    {
        if (key == Arr[i]) // if  found
        {
            return i; // return the index
        }
    }
    return -1; // else return -1
}

int main()
{
    int size, key;
    int *Array;
    cout << "Enter size of Array : ";
    cin >> size; // size of array user type
    Array = new int[size];
    cout << "Enter the Key to find : ";
    cin >> key;
    for (int i = 0; i < size; i++)
    {
        Array[i] = 10 + rand() % 89; // randomly initializing
    }
    int index = SequentialSearch(Array, size, key); // function call
    if (index == -1)
    {
        cout << "\nKey not found" << endl;
    }
    else
    {
        cout << "The Value " << key << " is at index : " << index << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++) // to print the value of array
    {
        cout << "Array [" << i + 1 << "] = ";
        cout << Array[i];
        cout << endl;
    }
    system("PAuse");
}