#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int left, int right) {
    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
};

int main() {
    int *arr = NULL;
    int size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        arr = realloc(arr, (size + 1) * sizeof(int));
        arr[size++] = value;

        int c = getchar();
        while (c == ' ' || c == '\t') c = getchar();

        if (c == '\n' || c == EOF) break;
        ungetc(c, stdin);
    }

    int k;
    scanf("%d", &k);

    reverseArray(arr, 0, size - 1);
    reverseArray(arr, 0, k % size - 1);
    reverseArray(arr, k % size, size - 1);
    
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");

    free(arr);
    return 0;
}