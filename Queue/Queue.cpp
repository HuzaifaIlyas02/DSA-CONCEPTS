//-------------------------- Queue -----------------------------

#include <iostream>
#include <conio.h>
#include <ctime> // for random values

using namespace std;

template <typename Itemtype> // using templates

class Queue
{ // class Queue

public:                      // Public Data members
    Queue();                 // default constructor
    Queue(int max);          // parameterized constructor
    ~Queue();                // destructor
    int IsFull() const;      // to check the queue is full or not
    int IsEmpty() const;     // to check if queue is empty or not
    void Insert(Itemtype);   // to insert into queue
    void Remove(Itemtype &); // to remove from the queue

private:                          // Private data members
    int front, rear, count, size; // data members
    Itemtype *items;              // pointer of itemtype (template)
};

//--------------- Function Definitions ---------------

// Default constructor of Queue
template <typename Itemtype>
Queue<Itemtype>::Queue() : front(0), rear(0), count(0), size(0), items(new Itemtype[size])
{
}

// Parameterized constructor of Queue
template <typename Itemtype>
Queue<Itemtype>::Queue(int max) : front(0), rear(0), count(0), size(max + 1), items(new Itemtype[size])
{
}

// Destructor of Queue
template <typename Itemtype>
Queue<Itemtype>::~Queue()
{
    /*	delete[]items;*/
}

// Function to check is queue is empty or not
template <typename Itemtype>
int Queue<Itemtype>::IsEmpty() const
{
    return (count == 0); // if the count is 0 return true
}

// Function to check is queue is full or not
template <typename Itemtype>
int Queue<Itemtype>::IsFull() const
{
    return (count == size); // if the count is equal to size return true
}

// Function of to insert new item into the queue
template <typename Itemtype>
void Queue<Itemtype>::Insert(Itemtype newitem)
{
    if (IsFull())
    {
        // print message
        cout << "Queue is overflow" << endl;
        exit(1);
    }
    else
    {
        items[rear] = newitem;    // inputing in queues index
        rear = (rear + 1) % size; // updating rear after inserting
        ++count;                  // increament to track record of queue size
    }
}

// Function of to remove item from the queue
template <typename Itemtype>
void Queue<Itemtype>::Remove(Itemtype &Removal)
{
    if (IsEmpty())
    {
        // print message
        cout << "Queue is underflow" << endl;
        exit(1);
    }
    else
    {
        Removal = items[front];     // removing from queue
        front = (front + 1) % size; // updating front after removing
        --count;                    // decrement count to track recor of queue size
    }
}

//--------------------------- MAIN DRIVER --------------------
int main()
{
    int size;
    cout << "Enter Size Of Queue : ";
    cin >> size;          // user input size
    Queue<int> Obj(size); // Object of Queue

    int randVal; // random values
    for (int i = 0; i < size; i++)
    {
        randVal = 10 + rand() % 89; // Getting new value in each interation
        Obj.Insert(randVal);
    }

    int get; // this variable remove from elements from queue
    for (int i = 0; i < size; i++)
    {
        Obj.Remove(get); // removing from queue
        cout << "Queue Element " << i + 1 << " is = " << get << endl;
    }

    system("Pause");
}
