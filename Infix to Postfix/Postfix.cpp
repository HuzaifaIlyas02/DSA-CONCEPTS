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

    //------------- Infix to postfix -------------------------

    Stack<char> IntStack; // Object of Stack
    char F;               // char to save while poping from the stack
    int count = 0;
    char Simple[] = "A+B*C-D/E^F-G*H"; // Expression to convert
    char posted[12];                   // Array to save the converted string
    int Size = sizeof(Simple);         // size of the string
    cout << "Simple : ";               // print the simple string
    for (int i = 0; i < Size; i++)
    {
        cout << Simple[i] << "";
    }
    cout << endl;
    cout << "Posted : ";
    for (int i = 0; i < Size; i++)
    {
        // checking for operator first
        if (Simple[i] == '+' || Simple[i] == '-' || Simple[i] == '/' || Simple[i] == '*' || Simple[i] == '^')
        {
            // increment the count one time
            count++;
            if (count == 1) // if it is the first operator
            {
                IntStack.Push(Simple[i]); // simply push into the stack
            }

            // if not the first oprator then check the precendence
            IntStack.Pop(F); // pop from the stack

            switch (F) // switch statement
            {

            case '+': // if the poped operator is +
            {
                // check for the precedence with the character read from the string
                if (Simple[i] == '/' || Simple[i] == '*' || Simple[i] == '^') // if the read characer has high precedence
                {
                    IntStack.Push(F);         // push the poped one again into the stack
                    IntStack.Push(Simple[i]); // push the read one also into the stack
                }
                else // if not from the above
                {
                    IntStack.Push(F); // push simpy into the stack
                }
                break;
            }
            case '-': // if the poped operator is -
            {
                // check for the precedence with the character read from the string
                if (Simple[i] == '/' || Simple[i] == '*' || Simple[i] == '^') // if the read characer has high precedence
                {
                    IntStack.Push(F);         // push the poped one again into the stack
                    IntStack.Push(Simple[i]); // push the read one also into the stack
                }
                else // if not from the above
                {
                    IntStack.Push(F); // push simply into the stack
                }
                break;
            }
            case '/': // if the poped operator is /
            {
                // check for the precedence with the character read from the string
                if (Simple[i] == '+' || Simple[i] == '-' || Simple[i] == '*' || Simple[i] == '^') // if the read characer has low or same precedence
                {
                    posted[i] = F;            // add the poped operator to the posted array
                    IntStack.Push(Simple[i]); // and push the operator read from the simple string
                    cout << posted[i];        // print the posted array
                }
                else // if not from the above
                {
                    IntStack.Push(Simple[i]); // push simply into the stack
                }
                break;
            }
            case '*': // if the poped operator is *
            {
                // check for the precedence with the character read from the string
                if (Simple[i] == '+' || Simple[i] == '-' || Simple[i] == '/' || Simple[i] == '^') // if the read characer has low or same precedence
                {
                    posted[i] = F;            // add the poped operator to the posted array
                    IntStack.Push(Simple[i]); // and push the operator read from the simple string
                    cout << posted[i];        // print the posted array
                }
                else // if not from the above
                {
                    IntStack.Push(Simple[i]); // push simply into the stack
                }
                break;
            }
            case '^': // if the poped operator is ^
            {
                if (Simple[i] == '+' || Simple[i] == '-' || Simple[i] == '*' || Simple[i] == '/') // if the read characer has low or same precedence
                {
                    // check for the precedence with the character read from the string
                    posted[i] = F;            // add the poped operator to the posted array
                    IntStack.Push(Simple[i]); // and push the operator read from the simple string
                    cout << posted[i];        // print the posted array
                }
                else // if not from the above
                {
                    IntStack.Push(Simple[i]); // push simply into the stack
                }
                break;
            }
            }
        }
        else // if not from the above operators
        {
            posted[i] = Simple[i]; // simply and the simple array character to post fix array
            cout << posted[i];     // and print the array
        }
    }

    for (int i = Size; i > 0; i--)
    {
        // if the expression ends check the stack
        if (IntStack.IsEmpty()) // if empty
        {
            exit(0); // simple exit
        }
        else // if not
        {
            IntStack.Pop(F);   // pop the stack untill empty
            posted[i] = F;     // and the pooped to the postfix array
            cout << posted[i]; // simple print
        }
    }

    _getch();
    return 0;
}