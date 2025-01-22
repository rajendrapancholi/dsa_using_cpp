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

    // Reverse the linked list
    void reverseLst()
    {
        // if list is empty.
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *prev = NULL; // points to null value
        Node *curr = head; // points to first node of the list
        Node *nxt = NULL;  // points to second node of the list
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // End of the loop prev points to the last element of the list
        head = prev;
    }

    // Reverse the linked list using recursion
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
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
    ll.insertAtTail(6);
    ll.display();
    ll.head = ll.reverse(ll.head);
    // ll.deleteAlter();
    // ll.display();
    // ll.printReverse(ll.head);
    // ll.reverseLst();
    ll.display();
    return 0;
}