/**********************
Program Name        : Segregate even and odd nodes in a singly linked list.
Author              : Rajendra Pancholi
Date of creation    : 12/02/2025
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

// Function for creating a node and initialize the memory at run time.
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

// Add elements of a list at the beginning
void insertAtBegin(int data, Node **head)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void segregateEvenAndOdd(Node **head)
{
    Node *evenHead = NULL;
    Node *oddHead = NULL;
    Node *evenCurr = NULL;
    Node *oddCurr = NULL;
    Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->value % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenCurr = evenHead;
            }
            else
            {
                evenCurr->next = temp;
                evenCurr = evenCurr->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddCurr = oddHead;
            }
            else
            {
                oddCurr->next = temp;
                oddCurr = oddCurr->next;
            }
        }
        temp = temp->next;
    }

    if (evenCurr != NULL)
        evenCurr->next = oddHead;
    if (oddCurr != NULL)
        oddCurr->next = NULL;
    *head = evenHead ? evenHead : oddHead;
}

// Display the list
void display(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
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
    Node *head = NULL;
    insertAtBegin(8, &head);
    insertAtBegin(7, &head);
    insertAtBegin(6, &head);
    insertAtBegin(5, &head);
    insertAtBegin(4, &head);
    insertAtBegin(6, &head);
    insertAtBegin(3, &head);
    insertAtBegin(2, &head);
    insertAtBegin(4, &head);

    printf("Original list:\n");
    display(&head);
    printf("segregate Even And Odd nodes list:\n");
    segregateEvenAndOdd(&head);
    display(&head);

    return 0;
}