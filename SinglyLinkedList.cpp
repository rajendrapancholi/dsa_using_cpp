#include <iostream>
using namespace std;

// Creating a node class.
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }
    ~SinglyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // insert element at begin
    void insertAtBegin(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // insert element at end of the list.
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        // if list is empty
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // insert at specific index of the list.
    void insertAtSpecific(int index, int data)
    {
        if (index == 0)
        {
            insertAtBegin(data);
            return;
        }
        Node *temp = head;
        Node *newNode = new Node(data);
        int currentIndex = 0;
        while (currentIndex != index - 1)
        {
            temp = temp->next;
            currentIndex++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at begin of the list.
    void deleteAtBegin()
    {
        // 13.07.24
    }

    // Delete at end of the list.

    // Delete at specific of the list.

    // display list of elements
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertAtBegin(13);
    list.insertAtBegin(12);
    list.insertAtBegin(11);
    list.insertAtEnd(14);
    list.display();
    list.insertAtSpecific(2, 20);
    list.display();
    return 0;
}