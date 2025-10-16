#include <stdio.h>
#include <stdlib.h>

static void sortColors(int *nums, int size) {
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            int t = nums[low]; 
            nums[low] = nums[mid]; 
            nums[mid] = t;
            low++; 
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int t = nums[mid]; 
            nums[mid] = nums[high]; 
            nums[high] = t;
            high--;
        }
    }
}

int main() {
    int *nums = NULL;
    int size = 0, value;

    while (scanf("%d", &value) == 1) {
        int *tmp = realloc(nums, (size + 1) * sizeof(int));
        if (!tmp) { free(nums); return 1; }
        nums = tmp;
        nums[size++] = value;

        int ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    sortColors(nums, size);

    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");

    free(nums);
    return 0;
}
