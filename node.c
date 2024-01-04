#include <stdlib.h>
#include "node.h"

// creer liste vide
Node *createLinkedList()
{
    return NULL;
}

// insere nouv node
Node *insertNode(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// donne taille node
int getLinkedListLength(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// changer val de 2 position
Node *swapNodes(Node *head, int data1, int data2)
{
    if (data1 == data2)
    {

        return head;
    }

    Node *prev1 = NULL;
    Node *curr1 = head;
    while (curr1 != NULL && curr1->data != data1)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node *prev2 = NULL;
    Node *curr2 = head;
    while (curr2 != NULL && curr2->data != data2)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL)
    {
        
        return head;
    }

    // si val tete = nil tete pointe sur node
    if (prev1 != NULL)
    {
        prev1->next = curr2;
    }
    else
    {
        head = curr2;
    }

    // si val2 n'est pas dans la tete , la tete pointe sur node 2
    if (prev2 != NULL)
    {
        prev2->next = curr1;
    }
    else
    {
        head = curr1;
    }

    // changer point suiv de node
    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

    return head;
}

// liberer node
void freeLinkedList(Node *head)
{
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
