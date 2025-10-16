#include <stdio.h>
#include <stdlib.h>

void evensFirst(int *arr, int size) {
    int evenIndex = 0;
    for (int i = 0; i < size; i++) {
        if ((arr[i] & 1) == 0) {
            int t = arr[i];
            arr[i] = arr[evenIndex];
            arr[evenIndex] = t;
            evenIndex++;
        }
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        int *tmp = realloc(arr, (size + 1) * sizeof(int));
        if (!tmp) { free(arr); return 1; }
        arr = tmp;
        arr[size++] = value;

        int ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    evensFirst(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");

    free(arr);
    return 0;
}
