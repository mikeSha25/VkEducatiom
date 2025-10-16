#include <stdio.h>
#include <stdlib.h>

void move_zeros(int *nums, int size) {
    int pos = 0;

    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            nums[pos++] = nums[i];
        }
    }
    while (pos < size) {
        nums[pos++] = 0;
    }
}

int main() {
    int *nums = NULL;
    int size = 0, value;

    while (scanf("%d", &value) == 1) {
        int *tmp = realloc(nums, (size + 1) * sizeof(int));
        if(!tmp) { free(nums); return 1; }

        nums = tmp;
        nums[size++] = value;

        int ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    move_zeros(nums, size);

    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");

    free(nums);
    return 0;
}
