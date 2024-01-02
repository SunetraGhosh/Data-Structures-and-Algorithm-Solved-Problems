#include <stdio.h>
#include <stdlib.h>

int multiple(int n) {
    if (n % 2 == 0) {
        return n;
    } else {
        return 0;
    }
}

int recursivesum(int* arr) {
    if (arr[0] == -1) {
        return 0; // Base case: Reached the end of the sequence (sentinel value)
    }
    return multiple(arr[0]) + recursivesum(arr + 1);
}

int* fibonacci() {
    int a = 1;
    int b = 2;
    int* arr = (int*)malloc(100000 * sizeof(int));
    arr[0] = a;
    arr[1] = b;
    int count = 2;

    while (1) {
        int c = a + b;
        if (c > 4000000) {
            break;
        }
        arr[count++] = c;
        a = b;
        b = c;
    }

    arr[count] = -1; // Marking the end of the sequence with a sentinel value
    arr = (int*)realloc(arr, (count + 1) * sizeof(int));
    return arr;
}

int main() {
    int* arr = fibonacci();
    int s = recursivesum(arr);
    printf("%d\n", s);
    free(arr);
    return 0;
}
