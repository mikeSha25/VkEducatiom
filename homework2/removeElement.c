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

Node* removeElement(Node* head, int value) {
    Node* dummy = malloc(sizeof(Node));
    dummy->next = head;

    Node* prev = dummy;
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    Node* node = dummy->next;
    free(dummy);
    return node;
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

    int value = 3;
    Node* node = removeElement(n1, 3);

    printf("Removed: ");
    printList(node);

    freeList(node);

    return 0;
}