#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        arr = realloc(arr, (size + 1) * sizeof(int));
        arr[size++] = value; 
    }
    
    int left = 0, right = size - 1;

    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");

    free(arr);
    return 0;
}