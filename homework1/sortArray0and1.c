#include <stdio.h>
#include <stdlib.h>

void sort_binary_array (int *arr, int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        if (arr[left] == 0) {
            left++;
        } else if (arr[right] == 1) {
            right--;
        } else {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        arr = realloc(arr, (size + 1) * sizeof(int));
        arr[size++] = value; 

        int ch = getchar();
        if (ch == '\n' || ch == EOF) 
            break;
    }
    
    sort_binary_array(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");

    free(arr);

    return 0;
}
