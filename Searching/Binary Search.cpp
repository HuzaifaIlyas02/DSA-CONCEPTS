//----------------- BINARY SEQUENTIAL SEARCH -------------------

#include <iostream>
#include <ctime> // For random values

using namespace std;

int BinarySearch(int Arr[], int size, int key)
{
    /* Function with parameter
    Arr : Array
    size: size of Array
    key : VAlue to find   */

    int first = 0, last = size - 1; // initialize first to 0 and last to size
    while (first <= last)
    {
        int mid = (first + last) / 2; // find mid
        if (key == Arr[mid])          // if matches with mid index
        {
            return mid; // return mid
        }
        else if (key < Arr[mid]) // else if less than mid
        {
            last = mid - 1; // update the last and decrease to mid - 1
        }
        else if (key > Arr[mid]) // if greater than mid
        {
            first = mid + 1; // update the first and increase to mid + 1
        }
    }
    return -1; // if not found return -1
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
    int index = BinarySearch(Array, size, key); // function call
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