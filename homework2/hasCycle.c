#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

bool hasCycle (struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;
    
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL)
            return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main () {
    struct Node* n1 = newNode(11);
    struct Node* n2 = newNode(3);
    struct Node* n3 = newNode(8);
    struct Node* n4 = newNode(17);
    struct Node* n5 = newNode(16);
    struct Node* n6 = newNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;

    if (hasCycle(n1))
        printf("Список циклический\n");
    else
        printf("Список нециклический\n");

    return 0;
}
