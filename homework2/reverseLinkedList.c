#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* reverseLinkedList (Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* n1 = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(3);
    Node* n4 = newNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printf("Initial: ");
    printList(n1);

    Node* reverse = reverseLinkedList(n1);

    printf("Reversed: ");
    printList(reverse);

    freeList(reverse);

    return 0;
}