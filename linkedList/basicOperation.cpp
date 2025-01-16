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
    // Display element of the linked list
    void display()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->value << " > ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.display();
    return 0;
}