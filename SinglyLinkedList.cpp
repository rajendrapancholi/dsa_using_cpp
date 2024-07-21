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

    // Update at specific index of the list.
    void updateAtSpecific(int index, int data)
    {
        Node *temp = head;
        int currPos = 0;
        while (currPos != index)
        {
            temp = temp->next;
            currPos++;
        }
        temp->data = data;
    }

    // Delete at begin of the list.
    void deleteAtBegin()
    {
        Node *temp = head;
        head = temp->next;
        free(temp);
    }

    // Delete at end of the list.
    void deleteAtEnd()
    {
        Node *secondLast = head;
        while (secondLast->next->next != nullptr)
        {
            secondLast = secondLast->next;
        }
        Node *temp = secondLast->next;
        secondLast->next = nullptr;
        free(temp);
    }

    // Delete at specific of the list.
    void deleteAtSpecific(int index)
    {
        if (index == 0)
        {
            deleteAtBegin();
            return;
        }
        Node *prev = head;
        int currPos = 0;
        while (currPos != index - 1)
        {
            prev = prev->next;
            currPos++;
        }
        Node *temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }

    // Delete alternate node of the list.
    void deleteAlternate()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *prev = head;
        Node *curr = head->next;
        while (prev != nullptr && curr != nullptr)
        {
            prev->next = curr->next;
            delete curr;
            prev = prev->next;

            if (prev != nullptr)
            {
                curr = prev->next;
            }
        }
    }

    // Delete duplicate node of the list.
    void deleteDuplicate()
    {
        Node *curr = head;
        while (curr)
        {
            while (curr->next && curr->data == curr->next->data)
            {
                // delete curr node
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            curr = curr->next;
        }
    }

    // Display reverse of the linked list. whithout reverse list.
    void displayReverse(Node *head)
    {
        // only one node in a list.
        if (head == nullptr)
        {
            cout << "Only one element of the list." << endl;
            return;
        }
        // recursive case
        displayReverse(head->next);
        cout << head->data << " ";
    }
    void printR()
    {
        displayReverse(head);
    }

    // Reverse all nodes in a linked list.
    void reverseSLL()
    {
        Node *prevptr = nullptr;
        Node *currptr = head;
        while (currptr)
        {
            Node *nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        // When the loops ends my prevptr points to be last node, which is a new head of the list.
        head = prevptr;
    }

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
    list.insertAtBegin(12);
    list.insertAtBegin(11);
    list.insertAtEnd(14);
    list.insertAtEnd(14);
    list.display();
    list.insertAtSpecific(2, 20);
    list.display();
    list.updateAtSpecific(4, 25);
    list.display();
    // list.deleteAtBegin();
    // list.display();
    // list.deleteAtEnd();
    // list.deleteAtSpecific(2);
    // list.display();
    // list.deleteAlternate();
    // list.display();
    // list.deleteDuplicate();
    // list.display();
    // list.printR();
    list.reverseSLL();
    list.display();

    return 0;
}