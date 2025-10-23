#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// bool isPalindrome(const char *str) { //через два указателя
//     int left = 0;
//     int right = strlen(str) - 1;

//     while (left < right) {
//         if (str[left] == str[right]) {
//             left++; right--;
//         }
//         else
//             return false;
//     }
//     return true;
// }

typedef struct Stack {
    char *data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int capacity) {
    s->data = malloc(capacity);
    s->top = -1;
    s->capacity = capacity;
}

void push(Stack *s, char c) {
    if (s->top < s->capacity - 1)
        s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (s->top >= 0)
        return s->data[s->top--];
    return '\0';
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void freeStack(Stack *s) {
    free(s->data);
}

bool isPalindrome(const char *str) {
    int len = strlen(str);
    Stack s;
    initStack(&s, len);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        char ch = pop(&s);
        if (str[i] != ch) {
            freeStack(&s);
            return false;
        }
    }

    freeStack(&s);
    return true;
}

int main() {
    char str[105];
    scanf("%104s", str);

    if (isPalindrome(str))
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}

