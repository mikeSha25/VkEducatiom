#include <stdio.h>
#include <stdlib.h>

int main() {
    // int n;
    // scanf("%d", &n);

    // int nums[n];
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &nums[i]);
    // }

    int *nums = NULL;
    int size = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            nums = realloc(nums, (size + 1) * sizeof(int));
            nums[size++] = value;
            break;
        } else {
            ungetc(c, stdin);
            nums = realloc(nums, (size + 1) * sizeof(int));
            nums[size++] = value;
        }
    }

    int target;
    scanf("%d", &target);
    
    int left = 0, right = size - 1;
    int found = 0;
    
    while (left < right) {
        int summ = nums[left] + nums[right];

        if (summ == target) {
            printf("%d %d\n", left, right);
            found = 1;
            break;
        }
        if (summ < target) {
            left++;
        }
        if (summ > target) {
            right--;
        }
    }

    if (!found) { 
        printf("Not found\n");
    }

    free(nums);
    return 0;
}