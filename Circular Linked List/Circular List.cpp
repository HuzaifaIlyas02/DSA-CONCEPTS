//----------------- CIRCULAR LINKED LIST ---------------------------
#include <iostream>
#include <string>
using namespace std;

template <typename ItemType>
class List
{ // class list

    // Public data members
public:
    List();                      // Default constructor
    void insert_Start(int);      // insert at the start of list
    void insert_After(int, int); // insert after a node
    void insert_End(int);        // insert at the end of list
    void delete_Start();         // delete a node from start
    void delete_After(int);      // insert after a node
    void delete_End();           // delete a node from start
    void Display();

    // Private data members
private:
    struct node
    { // struct node
        ItemType info;
        struct node *next;
    };
    typedef struct node *NODEPTR;
    node *head; // Head node
};

// ------------------------ Function Definitions ------------------------------

// CLASS TEMPLATE IMPLEMENTATION

// Constructor
template <typename ItemType>
List<ItemType>::List()
{
    head = NULL; // intialize with NULL
}

//-------------------------------------------------------------
//              Inserting At the start of linked list

template <typename ItemType>
void List<ItemType>::insert_Start(int Value) // Inserting at the start of linked list
{
    NODEPTR ptr = new node; // new pointer node
    ptr->info = Value;      // assigning value to info part
    ptr->next = head;       // assigning the next part to head
    NODEPTR temp = head;
    if (head != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    else
    {
        ptr->next = ptr;
    }
    head = ptr;
}

//-------------------------------------------------------------
//              Inserting After a Node

template <typename ItemType>
void List<ItemType>::insert_After(int prev, int Value)
{
    // prev (is the previos node value)
    // value (is the new node value)

    NODEPTR ptr = new node;  // new pointer node
    NODEPTR temp = new node; // new pointer node
    ptr->info = Value;
    temp = head;
    while (temp->info != prev) // traverse till the value founds
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

//-------------------------------------------------------------
//              Inserting Node at the end of linked list

template <typename ItemType>
void List<ItemType>::insert_End(int Value)
{
    NODEPTR New = new node;  // new pointer node
    NODEPTR temp = new node; // new pointer node
    New->info = Value;
    if (head == NULL) // if only one node in the linked list
    {
        head = New;       // assign head to the node
        New->next = temp; // and assign next to head for circular list
    }
    else
    {
        temp = head;               // if more than one nodes
        while (temp->next != head) // traverse to end
        {
            temp = temp->next;
        }
        New->next = head; // assign the next of node to head to circulate
        temp->next = New; // and the end node with new node
    }
}

//-------------------------------------------------------------
//              Deleting Node from the start of linked list

template <typename ItemType>
void List<ItemType>::delete_Start()
{
    NODEPTR temp = new node; // new pointer node
    temp = head;             // assign to head node
    NODEPTR ptr;
    while (temp->next != head) // traverse till the last node
    {
        temp = temp->next;
    }
    ptr = head;
    head = temp->next;
    ptr->next = head; // to circulate the list
    delete temp;
}

//-------------------------------------------------------------
//              Deleting Node After a node

template <typename ItemType>
void List<ItemType>::delete_After(int Value)
{
    NODEPTR ptr, preptr;       // two pointer nodes
    ptr = head;                // assign ptr to head node
    preptr = NULL;             // to NULL
    while (ptr->info != Value) // traverse till the value found
    {
        preptr = ptr; // to track record of prvious node
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    delete ptr;
}

//-------------------------------------------------------------
//              Deleting Node At the end of linked list

template <typename ItemType>
void List<ItemType>::delete_End()
{
    NODEPTR ptr = new node;
    NODEPTR preptr = new node; // two pointer nodes
    preptr = head;             // to track the record of previous node
    ptr = head->next;
    while (ptr->next != head) // traverse till the end node
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = head;
    delete ptr;
}

//-------------------------------------------------------------
//              Display the nodes of linked list

template <typename ItemType>
void List<ItemType>::Display()
{
    NODEPTR ptr = head; // new pointer node assigned to head
    system("CLS");
    cout << "Linked List : " << endl;
    while (ptr->next != head) // traverse till end
    {
        cout << ptr->info << " -> ";
        ptr = ptr->next;
    }
    cout << ptr->info;
}

//------------------ MAIN DRIVER -----------------------------

int main()
{
    List<int> Obj;
    int choice, Value;
    char Again;
    do
    {
        system("CLS");
        cout << "1- Insert\n2- Delete\n3- Display" << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "1- Insert Start\n2- Insert After\n3- Insert End" << endl;
            cout << "choice : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the value to insert : ";
                cin >> Value;
                Obj.insert_Start(Value);
            }
            else if (choice == 2)
            {
                int prevVal;
                cout << "Insert the previous value : ";
                cin >> prevVal;
                cout << "Enter new Value : ";
                cin >> Value;
                Obj.insert_After(prevVal, Value);
            }
            else if (choice == 3)
            {
                cout << "Enter the Value to insert : ";
                cin >> Value;
                Obj.insert_End(Value);
            }
            break;

        case 2:
            system("CLS");
            cout << "1- Delete Start\n2- Delete After\n3- Delete End" << endl;
            cout << "choice : ";
            cin >> choice;
            if (choice == 1)
            {
                Obj.delete_Start();
            }
            else if (choice == 2)
            {
                cout << "Enter the Value to delete After : ";
                cin >> Value;
                Obj.delete_After(Value);
            }
            else if (choice == 3)
            {
                Obj.delete_End();
            }
            break;

        case 3:
            Obj.Display();
            break;

        default:
            cout << "ERROR! Wrong Input " << endl;
            break;
        }
        cout << "\nDO YOU Want to Continue (Y/N) : ";
        cin >> Again;

    } while (Again == 'Y' || Again == 'y');

    system("Pause");
}
