#include <stdio.h>

void merge(int *arr1, int len1, const int *arr2, int len2) {
    int p1 = len1 - len2 - 1;
    int p2 = len2 - 1;
    int p3 = len1 - 1;

    while (p2 >= 0) {
        if (p1 >= 0 && arr1[p1] > arr2[p2]) {
            arr1[p3--] = arr1[p1--];
        } else {
            arr1[p3--] = arr2[p2--];
        }
    }
}

int main() {
    int len1 = 7;
    int len2 = 3;
    int arr1[7] = {3, 8, 10, 11, 0, 0, 0};
    int arr2[3] = {1, 7, 9};

    merge(arr1, len1, arr2, len2);

    for (int i = 0; i < len1; i++) {
        printf("%d", arr1[i]);
        if (i < len1 - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
