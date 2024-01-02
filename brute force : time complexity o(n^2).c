#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (*(nums+i) + *(nums+j) == target) {
                *result = i;
                *(result + 1) = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Correct array initialization syntax

    int target = 7;
    int returnSize;
    int* indices = twoSum(arr, sizeof(arr) / sizeof(arr[0]), target, &returnSize);

    if (indices != NULL) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
        free(indices); // Free memory allocated by malloc
    } else {
        printf("No matching indices found.\n");
    }

    return 0;
}
