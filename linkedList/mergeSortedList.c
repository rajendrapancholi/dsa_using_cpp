/**********************
Program Name        : Merge two sorted linked lists into one sorted linked list.
Author              : Rajendra Pancholi
Date of creation    : 15/02/2025
Organization        : NIT Patna
***********************/

#include <stdio.h>
#include <stdlib.h>

// Creating a node
typedef struct node
{
    int value;
    struct node *next;
} Node;

// function for creating a node and initiale the memory at run time.
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

// Add elements of an list
void insertAtBegin(int data, Node **head)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = (*head);
    *head = newNode;
}

void insertAtEnd(int data, Node **head)
{
    Node *temp = *head;
    Node *newNode = createNode(data);
    if (temp == NULL)
    {
        temp = newNode;
        *head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = NULL;
}
void sortedList(Node **head1, Node **head2, Node **head3)
{
    Node *ptr1 = *head1;
    Node *ptr2 = *head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->value < ptr2->value)
        {
            insertAtEnd(ptr1->value, head3);
            ptr1 = ptr1->next;
        }
        else
        {
            insertAtEnd(ptr2->value, head3);
            ptr2 = ptr2->next;
        }
    }
    // remaining element
    if (ptr1 != NULL)
    {
        while (ptr1 != NULL)
        {
            insertAtEnd(ptr1->value, head3);
            ptr1 = ptr1->next;
        }
    }
    if (ptr2 != NULL)
    {
        while (ptr2 != NULL)
        {
            insertAtEnd(ptr2->value, head3);
            ptr2 = ptr2->next;
        }
    }
}

void display(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    // Linked list - 1
    insertAtBegin(6, &head1);
    insertAtBegin(4, &head1);
    insertAtBegin(2, &head1);
    insertAtBegin(1, &head1);
    printf("Linked list - 1\n");
    display(&head1);
    // Linked list - 2
    insertAtBegin(15, &head2);
    insertAtBegin(9, &head2);
    insertAtBegin(8, &head2);
    insertAtBegin(7, &head2);
    insertAtBegin(5, &head2);
    insertAtBegin(3, &head2);

    printf("Linked list - 2\n");
    display(&head2);
    printf("Linked list - 3\n");
    sortedList(&head1, &head2, &head3);
    display(&head3);
    printf("\n");
    return 0;
}