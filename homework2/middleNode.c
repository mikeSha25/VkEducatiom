#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

Node* middleNode(Node* head) {
    if (head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    Node* n1 = newNode(3);
    Node* n2 = newNode(8);
    Node* n3 = newNode(9);
    Node* n4 = newNode(6);
    Node* n5 = newNode(11);
    Node* n6 = newNode(16);
    Node* n7 = newNode(17);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Node* mid = middleNode(n1);

    if (mid != NULL)
        printf("middleNode: %d\n", mid->data);
    else
        printf("Empty list\n");

    freeList(n1);
    return 0;
}

