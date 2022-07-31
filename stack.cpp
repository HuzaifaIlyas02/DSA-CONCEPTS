//------------------- Stack ------------------------

#include <iostream> //Including Libraries
#include <stdlib.h>
#include <cstring>
#include <conio.h>

using namespace std;

template <typename ItemType> // using Templates for user flexiblity

class Stack
{ // Stack Class
public:
    // Public data members Of class stack
    Stack();                     // Default constructor
    Stack(int max);              // parameterized constructor with integer parameter
    ~Stack();                    // destructor
    int IsEmpty() const;         // function to check for empty stack
    int IsFull() const;          // function to check for full stack
    void Push(ItemType newitem); // function to insert new item in the stack
    void Pop(ItemType &newitem); // function to remove item from the stack
private:
    int top;         // variable top to track record of stack
    int maxStack;    // max number of index in stack
    ItemType *items; // dynamic array implementation
};

//------------------- FUNCTION DEFINTIONS --------------------

// Stack constructor defintion

template <typename ItemType>
Stack<ItemType>::Stack() : maxStack(500), top(-1), items(new ItemType[maxStack]) // default constructor defintion
{
}

// Stack pararmeterized constructor defintion

template <typename ItemType>
Stack<ItemType>::Stack(int max) : maxStack(max), top(-1), items(new ItemType[maxStack]) // parameterized constructor
{
}

// Stack destructor defintion

template <typename ItemType>
Stack<ItemType>::~Stack() // destructor definition
{
    delete[] items;
}

/* Function IsEmpty to check whether the
stack is empty for removal or not */

template <typename ItemType>
int Stack<ItemType>::IsEmpty() const // empty function defintion
{
    return (top == -1); // if the top is -1 then it is empty
}

/* Function IsEmpty to check whether the
stack is full for insertion or not */

template <typename ItemType>
int Stack<ItemType>::IsFull() const // Full function defintion
{
    return (top == maxStack - 1); // is the top is equal to (max_size - 1)
}

// Function to insert new item into the stack
template <typename ItemType>
void Stack<ItemType>::Push(ItemType newItem) // Push function defintion
{
    // First check for the availability of stack if not full
    if (IsFull())
    {
        // print message
        cout << "Stack Overflow " << endl;
        exit(1); // exit program
    }
    top++;                // increment top
    items[top] = newItem; // and new item in stack
}
template <typename ItemType>
void Stack<ItemType>::Pop(ItemType &item) // Pop function defintion
{
    // First check for the Empty of stack if not empty then remove
    if (IsEmpty())
    {
        // print message
        cout << "Stack underflow" << endl;
        exit(1);
    }
    item = items[top]; // remove from stack
    top--;             // and decrement top
}

//----------------- MAIN DRIVER PROGRAM ---------------------

int main()
{
    int size;
    cout << "Enter Size of Stack : ";
    cin >> size;
    Stack<int> Obj(size); // Stack of size 10

    // Inserting Elements into the stack
    for (int i = 0; i < size; i++)
    {
        Obj.Push(i); // Push into the stack every index
    }

    // Removing Every Element from the stack
    int element = 0;
    for (int i = 0; i < size; i++)
    {
        Obj.Pop(element);                              // Saving elements into variable
        cout << "Stack Element " << i + 1 << " is = "; // conveing message
        cout << element << endl;                       // printing each and every element
    }
    system("Pause");
}