/**********************
Program Name        : Basic operation on linked list
Author              : Rajendra Pancholi
Date of creation    : 16/01/2025
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node *next;
    // node class constructor
    Node(int data)
    {
        value = data;
        next = NULL;
    }
};

// Create linked list class to perform the operations
class LinkedList
{
public:
    //  head points to the null
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    // insert element at the end of the linked list
    void insertAtTail(int data)
    {
        // Create a new node
        Node *newNode = new Node(data);
        // check if list is empty.
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL) // points to end of the list
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete element alternatively
    void deleteAlter()
    {
        if (head == NULL)
        { // if list is empty
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;

        while (temp->next != NULL && temp != NULL)
        {
            Node *del = temp->next; // delete node
            temp->next = temp->next->next;
            free(del); // free the del node
            temp = temp->next;
        }
    }

    // Display element of the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " > ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    // Print element in reverse order
    void printReverse(Node *head)
    {

        if (!head) // head == NULL
            return;
        printReverse(head->next);
        if (!head->next)
            cout << "null > ";
        cout << head->value << " > ";
    }
    // destructor
    ~LinkedList()
    {
        cout << "\nDone" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    // ll.deleteAlter();
    // ll.display();
    ll.printReverse(ll.head);
    return 0;
}