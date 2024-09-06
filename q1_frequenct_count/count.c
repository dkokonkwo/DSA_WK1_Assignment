#include <stdio.h>
#include <stdlib.h>

void frequency(int arr[], int size);

int main() {
    int arr[] = {5, 2, 2, 8, 5, 6, 8, 8, 6, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    frequency(arr, size);
    return (0);
}

void frequency(int arr[], int size) {
    int counted[size];
    int i, j, count;
    for (i = 0; i < size; i++) {
        counted[i] = 0;
    }
    
    for (i = 0; i < size; i++) {
        if (!counted[i]) {
            count = 1;
            for (j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    counted[j] = 1;
                }
            }
            printf("Element %d occurs %d time(s)\n", arr[i], count);
        }
    }
}
