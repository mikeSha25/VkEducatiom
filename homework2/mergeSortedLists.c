#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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

Node* mergeSortedLists(Node *list1, Node *list2) {
    Node* dummy = malloc(sizeof(Node));
    Node* tail = dummy;
    dummy->next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if(list1)
        tail->next = list1;
    if(list2)
        tail->next = list2;
    
    Node* node = dummy->next;
    free(dummy);
    return node;
}

int main(void) {
    Node* l1 = newNode(3);
    l1->next = newNode(6);
    l1->next->next = newNode(8);

    Node* l2 = newNode(4);
    l2->next = newNode(7);
    l2->next->next = newNode(9);
    l2->next->next->next = newNode(11);

    Node* merged = mergeSortedLists(l1, l2);

    printf("merged list: ");
    printList(merged);
    
    freeList(merged);

    return 0;
}