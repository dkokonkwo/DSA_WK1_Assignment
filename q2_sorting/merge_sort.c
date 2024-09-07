#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 100

int less(char *a, char *b);
void exch(char *arr[], int a, int b);
void sort(char *arr[], int size);
void merge(char *arr[], char *aux[], int lo, int mid, int hi);
void merge_sort(char *arr[], char *aux[], int lo, int hi);

int main(int argc, char *argv[]) {
    int algo, i;
    char *names[MAX_NAMES];
    FILE *file;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (-1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return (-1);
    }

    int count = 0;
    char buffer[MAX_NAME_LENGTH];
    while (fgets(buffer, MAX_NAME_LENGTH, file) && count < MAX_NAMES)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        names[count] = malloc(strlen(buffer) + 1);
        if (names[count] == NULL)
        {
            perror("Error allocating memory");
            fclose(file);
            return (-1);
        }
        strcpy(names[count], buffer);
        count++;
    }

    fclose(file);

    sort(names, count);

    file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return (-1);
    }
    for (i = 0; i < count; i++) {
        fprintf(file, "%s\n", names[i]);
    }

    fclose(file);

    for (i = 0; i < count; i++) {
        free(names[i]);
    }

    return (0);
}

void merge(char *arr[], char *aux[], int lo, int mid, int hi) {
    int k, i, j;
    for (k = lo; k <= hi; k++) {
        aux[k] = arr[k];
    }

    i = lo;
    j = mid + 1;
    for (k = lo; k <= hi; k++) {
        if (i > mid) {
            arr[k] = aux[j++];
        }
        else if (j > hi) {
            arr[k] = aux[i++];
        }
        else if (less(aux[j], aux[i])) {
            arr[k] = aux[j++];
        }
        else {
            arr[k] = aux[i++];
        }
    }
}

// Main sort function for merge sort
void sort(char *arr[], int size) {
    //Allocate memory with the same size as arr[]
    char **aux = malloc(size * sizeof(char *));
    if (aux == NULL) {
        perror("Error allocating auxiliary memory");
        return;
    }
    merge_sort(arr, aux, 0, size - 1);

    free(aux);
}

// Recursive merge sort
void merge_sort(char *arr[], char *aux[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;

    // sort first half
    merge_sort(arr, aux, lo, mid);

    //sort second half
    merge_sort(arr, aux, mid+1, hi);

    //Merge the two halves
    merge(arr, aux, lo, mid, hi);
}

//Comparison function for case-insensitive string
int less(char *a, char *b) {
    return(strcasecmp(a, b) < 0);
}
