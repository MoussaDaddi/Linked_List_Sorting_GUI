#ifndef NODE_H
#define NODE_H
#include"raylib.h"
#include <stdlib.h>
#include "node.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define NODE_WIDTH 50
#define NODE_HEIGHT 50
#define NODE_MARGIN 20

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Node {
    int data;
    Color fill_color ;
    Color border_color;
    Position position; // Added field for node position
    struct Node *next;
} Node;

Node *current;


Node *createNode(int data){
    Node *tmp =(Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next=NULL;
    return tmp;
}

Node* generateList(int size) {
    // Calculate spacing for center-justified distribution
    int totalNodeWidth = NODE_WIDTH + 2 * NODE_MARGIN;
    int totalNodeWidths = totalNodeWidth * size;
    int availableSpace = SCREEN_WIDTH - totalNodeWidths;
    if(size < 7)availableSpace/=4; 
    int NODE_SPACING = availableSpace / (size - 1); // Equal spacing between nodes

    Node* head = createNode(rand() % 100);

    // Calculate starting position for center justification
    int startingX = (SCREEN_WIDTH - totalNodeWidths - (NODE_SPACING * (size - 1))) / 2;

    head->position.x = startingX;
    head->position.y = (SCREEN_HEIGHT - NODE_HEIGHT) / 2;

    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(rand() % 50);
        current->next->position.x = current->position.x + totalNodeWidth + NODE_SPACING;
        current->next->position.y = (SCREEN_HEIGHT - NODE_HEIGHT) / 2;
        current->border_color = GRAY;
        current->fill_color = WHITE;
        current = current->next;
    }
    return head;
}


void swap(Node *a, Node *b) {
 
    int temp_data = a->data;
    a->data = b->data;
    b->data = temp_data;
    draw_node(a,BLACK,GREEN);
    draw_node(b,BLACK,GREEN);
    Wait(70);
    
}

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


#endif
