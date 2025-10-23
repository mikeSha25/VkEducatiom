#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// bool isSubsequence(const char *a, const char *b) { // через два указателя
//     int i = 0, j = 0;
//     while (a[i] != '\0' && b[j] != '\0') {
//         if (a[i] == b[j])
//             i++;
//         j++;
//     }

//     return a[i] == '\0';
// }

typedef struct Queue {
    char *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->data = malloc(capacity);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}

void enqueue(Queue *q, char c) {
    if (q->size < q->capacity) {
        q->rear++;
        q->data[q->rear] = c;
        q->size++;
    }
}

void dequeue(Queue *q) {
    if (q->size > 0) {
        q->front++;
        q->size--;
    }
}

char front(const Queue *q) {
    if (q->size > 0)
        return q->data[q->front];
    return '\0';
}

bool isEmpty(const Queue *q) {
    return q->size == 0;
}

void freeQueue(Queue *q) {
    free(q->data);
}

bool isSubsequence(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    Queue q;
    initQueue(&q, lenA);

    for (int i = 0; i < lenA; i++) {
        enqueue(&q, a[i]);
    }

    for (int j = 0; j < lenB && !isEmpty(&q); j++) {
        if (b[j] == front(&q)) {
            dequeue(&q);
        }
    }

    bool result = isEmpty(&q);
    freeQueue(&q);
    return result;
}

int main() {
    char a[105], b[105];

    if (scanf("%104s %104s", a, b) != 2)
        return 1;

    if(isSubsequence(a, b))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}