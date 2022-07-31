//-------------------------- DeQueue -----------------------------

#include <iostream>
#include <conio.h>

using namespace std;

template <typename Itemtype> // using templates

class Queue
{ // class Queue

public:                            // Public Data members
    Queue();                       // default constructor
    Queue(int max);                // parameterized constructor
    ~Queue();                      // destructor
    int IsFull() const;            // to check the queue is full or not
    int IsEmpty() const;           // to check if queue is empty or not
    void Rear_Insert(Itemtype);    // to insert into queue
    void Front_Insert(Itemtype);   // to insert into queue
    void Rear_Remove(Itemtype &);  // to remove from the queue
    void Front_Remove(Itemtype &); // to remove from the queue
    void Display();                // to Display Queue Elements

private:                          // Private data members
    int front, rear, count, size; // data members
    Itemtype *items;              // pointer of itemtype (template)
};

//--------------- Function Definitions ---------------

// Default constructor of Queue
template <typename Itemtype>
Queue<Itemtype>::Queue()
{
    front = rear = count = size = 0;
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
    size = max;
    front = rear = count = 0;
    items = new Itemtype[size];
    for (int i = 0; i < size; i++)
    {
        items[i] = 0;
    }
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

// Function of to insert new item from rear into the queue
template <typename Itemtype>
void Queue<Itemtype>::Rear_Insert(Itemtype newitem)
{
    if (IsFull())
    {
        // print message
        cout << "Queue is overflow" << endl;
        exit(1);
    }
    else
    {
        items[rear] = newitem; // inputing in queues index
        if (rear == size - 1)
        {
            rear = 0; // circular queue
        }
        else
        {
            rear = (rear + 1) % size; // updating rear after inserting
        }
        ++count; // increament to track record of queue size
    }
}

// Function of to remove item from rear queue
template <typename Itemtype>
void Queue<Itemtype>::Rear_Remove(Itemtype &Removal)
{
    if (IsEmpty())
    {
        // print message
        cout << "Queue is underflow" << endl;
        exit(1);
    }
    else
    {
        Removal = items[rear];             // removing from queue
        items[rear] = 0;                   // setting to 0 after removing
        rear = (rear + (size - 1)) % size; // updating front after removing
        --count;                           // decrement count to track recor of queue size
        if (count == 0)
        {
            front = rear = 0;
        }
    }
}

// Function of to remove item from front queue
template <typename Itemtype>
void Queue<Itemtype>::Front_Remove(Itemtype &Removal)
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
        items[front] = 0;           // setting to 0 after removing
        front = (front + 1) % size; // updating front after removing
        --count;                    // decrement count to track recor of queue size
        if (count == 0)
        {
            front = rear = 0;
        }
    }
}

// Function of to insert new item from rear into the queue
template <typename Itemtype>
void Queue<Itemtype>::Front_Insert(Itemtype newitem)
{
    if (IsFull())
    {
        // print message
        cout << "Queue is overflow" << endl;
        exit(1);
    }
    else
    {
        front = (front + (size - 1)) % size;
        items[front] = newitem; // inputing in queues index
        ++count;                // increament to track record of queue size
    }
}

template <typename Itemtype>
void Queue<Itemtype>::Display() // Display Function
{
    for (int i = 0; i < size; i++)
    {
        cout << "Queue Element " << i + 1 << " is : " << items[i] << endl;
    }
}

//--------------------------- MAIN DRIVER --------------------
int main()
{
    int size, choice, item;
    char again = ' ';
    cout << "Enter Size Of Queue : ";
    cin >> size;          // user input size
    Queue<int> Obj(size); // Object of Queue
    do
    {
        system("ClS");
        cout << "1- Insert\n2- Remove\n3- Display\n4- Exit" << endl;
        cout << "Choice : ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "1- Front\n2- Rear" << endl;
            cout << "choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter Number to insert : ";
                cin >> item;
                Obj.Front_Insert(item);
                break;
            case 2:
                cout << "Enter Number to insert : ";
                cin >> item;
                Obj.Rear_Insert(item);
                break;
            default:
                cout << "ERROR! OOPS" << endl;
                break;
            }
        }
        else if (choice == 2)
        {
            cout << "1- Front\n2- Rear" << endl;
            cout << "choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Obj.Front_Remove(item);
                cout << "Element Poped : " << item << endl;
                break;
            case 2:
                Obj.Rear_Remove(item);
                cout << "Element Poped : " << item << endl;
                break;
            default:
                cout << "ERROR! OOPS" << endl;
                break;
            }
        }
        else if (choice == 3)
        {
            Obj.Display();
        }
        else
        {
            exit(0);
        }
        cout << "Do You Want To Continue (Y/y) " << endl;
        cin >> again;
    } while (again == 'Y' || again == 'y');
    system("Pause");
}
