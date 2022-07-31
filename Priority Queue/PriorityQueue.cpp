//-------------------------- Queue -----------------------------

#include <iostream>
#include <conio.h>
#include <ctime>   // for random values
#include <iomanip> // for formatting

using namespace std;

template <typename Itemtype> // using templates

class Queue
{ // class Queue

public:                      // Public Data members
    Queue();                 // default constructor
    Queue(int max);          // parameterized constructor
    bool IsFull() const;     // to check the queue is full or not
    bool IsEmpty() const;    // to check if queue is empty or not
    void Insert(Itemtype);   // to insert into queue
    void Remove(Itemtype &); // to remove from the queue
    void Display();

private:                          // Private data members
    int front, rear, count, size; // data members
    Itemtype *items;              // pointer of itemtype (template)
};

//--------------- Function Definitions ---------------

// Default constructor of Queue
template <typename Itemtype>
Queue<Itemtype>::Queue()
{
    front = rear = count = 0;
    size = 5;
    items = new Itemtype[size];
    for (int i = 0; i < size; i++)
    {
        items[i] = 0;
    }
}

// Parameterized constructor of Queue
template <typename Itemtype>
Queue<Itemtype>::Queue(int max)
{
    front = rear = count = 0;
    size = max;
    items = new Itemtype[size];
    for (int i = 0; i < size; i++)
    {
        items[i] = 0;
    }
}

// Function to check is queue is empty or not
template <typename Itemtype>
bool Queue<Itemtype>::IsEmpty() const
{
    return (count == 0); // if the count is 0 return true
}

// Function to check is queue is full or not
template <typename Itemtype>
bool Queue<Itemtype>::IsFull() const
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

// Display FUnction
template <typename Itemtype>
void Queue<Itemtype>::Display()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(2) << setfill('0') << items[i] << endl;
    }
}

// Template used
template <class ItemType>
class PriorityQueue // Priority Queue class
{
    // Public data members
public:
    PriorityQueue();                 // Defaulr constructor of Pqueue
    PriorityQueue(int);              // Parameterized constructor of pqueue
    int PQ_Isfull(int) const;        // Function to check for full queue at that priority level
    int PQ_IsEmpty(int) const;       // Function to check for empty at that priority level
    void PQ_Insert(ItemType, int);   // Insertion function with priority level and newitemx
    void PQ_Remove(ItemType &, int); // To remove from the queue
    void PQ_Display();

    // Private data members
private:
    Queue<ItemType> *PQ_Obj; // Pointer object of Queue
    int Priority_level;      // Priority levels
};

//------------------- FUNCTION DEFINITIONS ----------------------

// Default constructor definition
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
    PQ_Obj = new Queue<ItemType>[10]; // initialize the array of itemtype
}

// Paramerterized constructor definition
template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(int max)
{
    Priority_level = max;                            // Initializing
    PQ_Obj == new Queue<ItemType>[ Priority_level ]; // making array
}

// Priority Queue empty check at every level
template <class ItemType>
int PriorityQueue<ItemType>::PQ_IsEmpty(int priorityLvl) const
{
    PQ_Obj[priorityLvl].IsEmpty(); // check for the Empty
}

// Priority Queue full check at every level
template <class ItemType>
int PriorityQueue<ItemType>::PQ_Isfull(int priorityLvl) const
{
    PQ_Obj[priorityLvl].IsFull(); // check for the availability
}

// To insert new item at user input level
template <class ItemType>
void PriorityQueue<ItemType>::PQ_Insert(ItemType newItem, int priorityLvl)
{
    PQ_Obj[priorityLvl].Insert(newItem); // insert the item at the given priority level
}

//---------------------------------
template <class ItemType>
void PriorityQueue<ItemType>::PQ_Remove(ItemType &removal, int level)
{

    PQ_Obj[level].Remove(removal);
}

template <class ItemType>
void PriorityQueue<ItemType>::PQ_Display()
{
    for (int i = 0; i < Priority_level; i++)
    {
        PQ_Obj[i].Display(); // calling Queue display function
    }
}

//--------------------------- MAIN DRIVER --------------------
int main()
{
    int levels, choice, item, priority;
    cout << "Enter Levels : ";
    cin >> levels;                 // user input levels
    PriorityQueue<int> PQ(levels); // Object of priority queue

    cout << "1- Insert Item\n2- Remove item\n3- Display" << endl;
    cout << "Choice : ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter new item to insert : ";
        cin >> item;
        cout << "Priority level : ";
        cin >> priority;
        PQ.PQ_Insert(item, priority);
    }
    else if (choice == 2)
    {
        cout << "Priority level tO remove : ";
        cin >> priority;
        PQ.PQ_Remove(item, priority);
    }
    else if (choice == 3)
    {
        PQ.PQ_Display();
    }
    system("Pause");
}
