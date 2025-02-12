/**********************
Program Name        : Solve problems on singly linked list.
Author              : Rajendra Pancholi
Date of creation    : 08/02/2025
Organization        : NIT Patna
***********************/
/***********************
Check list is equal or not and also check the same order of the elements present in list.
***********************/
#include <iostream>
using namespace std;
// Creating a Node
class Node
{
public:
    int value;
    Node *next;
    // Use nullptr instead of NULL in modern C++
    Node(int data) : value(data), next(nullptr) {} // Direct Initialization
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {} // Initialize head to nullptr

    // Inserting not at the end of the list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data); // creating a new node.
        if (head == nullptr)            // if list is empty.
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) // second last node of the list (convenience for insertion)
            temp = temp->next;

        // temp point to the second last of the list.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Displaying  elements of the list.
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty...!\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// check whether lists is eual or not
bool isEqualList(Node *head1, Node *head2)
{
    Node *temp1 = head1; // for store and traversing the first list.
    Node *temp2 = head2; // for store and traversing the second list.
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->value != temp2->value)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return (temp1 == nullptr && temp2 == nullptr);
}

int main()
{
    // Creating fist list
    LinkedList sll1;
    sll1.insertAtEnd(1);
    sll1.insertAtEnd(2);
    sll1.insertAtEnd(3);
    sll1.insertAtEnd(4);
    sll1.insertAtEnd(5);
    sll1.display();
    // Creating second list
    LinkedList sll2;
    sll2.insertAtEnd(1);
    sll2.insertAtEnd(2);
    sll2.insertAtEnd(3);
    sll2.insertAtEnd(4);
    sll2.insertAtEnd(5);
    sll2.insertAtEnd(6);
    sll2.display();
    cout << (isEqualList(sll1.head, sll2.head) ? "True" : "False") << endl;
    return 0;
}
