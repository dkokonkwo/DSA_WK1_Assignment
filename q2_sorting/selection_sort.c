#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 100

void exch(char *arr[], int a, int b);
void sort(char *arr[], int size);

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

// Selection Sort Function
void sort(char *arr[], int size) {
    int i, j, min;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (strcasecmp(arr[j], arr[min]) == -1) {
                min = j;
            }
        }
        exch(arr, i, min);
    }

}

// Exchange Function
void exch(char *arr[], int a, int b) {
    char *swap = arr[a];
    arr[a] = arr[b];
    arr[b] = swap;
}
