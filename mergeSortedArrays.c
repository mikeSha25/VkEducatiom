#include <stdio.h>
#include <stdlib.h>

void mergeSortedArray(const int *a, int len1, const int *b, int len2, int *c) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < len1)
        c[k++] = a[i++];
    while (j < len2)
        c[k++] = b[j++];
};

int main() {
    int *a = NULL, *b = NULL, *c = NULL;
    int len1 = 0, len2 = 0;
    int value;

    while (scanf("%d", &value) == 1) {
        int *tmp = realloc(a, (len1 + 1) * sizeof(int));
        if (!tmp) { free(a); return 1; }
        a = tmp;
        a[len1++] = value;

        int ch = getchar();
        if (ch == '\n' || ch == EOF) 
            break;
    }

    while (scanf("%d", &value) == 1) {
        int *tmp = realloc(b, (len1 + 1) * sizeof(int));
        if (!tmp) { free(a); free(b); return 1; }
        b = tmp;
        b[len2++] = value;
    
        int ch = getchar();
        if (ch == '\n' || ch == EOF) 
            break;
    }

    c = malloc((len1 + len2) * sizeof(int));
    if (!c) { free(a); free(b); return 1; }

    mergeSortedArray(a, len1, b, len2, c);

    for (int i = 0; i < len1 + len2; i++) {
        printf("%d", c[i]);
        if (i < len1 + len2 - 1)
            printf(" ");
    }
    printf("\n");
    
    free(a); free(b); free(c);
    return 0;
}