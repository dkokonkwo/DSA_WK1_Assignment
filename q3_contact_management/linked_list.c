#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Function to create a new node
struct Node* createNode(char *name, char *num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->name = strdup(name);
    newNode->num = strdup(num);
    newNode->next = NULL;
    return newNode;
}

// Function to convert an array to a linked list
struct Node* arrayToLinkedList(char *name[], char *num[], int size) {
    if (size == 0) return NULL;

    // Create the head of the linked list
    struct Node* head = createNode(name[0], num[0]);

    // Iterate through the arrays and create linked list nodes
    for (int i = 1; i < size; i++) {
        head = addContact(head, name[i], num[i]);
    }

    return head;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("[%s, %s] -> ", current->name, current->num);
        current = current->next;
    }
    printf("NULL\n");
}

//Function to add contact in sorted order
struct Node* addContact(struct Node* head, char *name, char *num) {
    struct Node* newNode = createNode(name, num);
    if (strcasecmp(newNode->name, head->name) < 0) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL && strcasecmp(current->name, newNode->name) < 0) {
        previous = current;
        current = current->next;
    }
    previous->next = newNode;
    newNode->next = current;
    return head;
}

// Function to search for contact
void searchContact(struct Node* head, char *name) {
    //linear search
    struct Node* current = head;
    int count = 0;
    while (current != NULL && strcasecmp(current->name, name) <= 0) {
        if (strcasecmp(current->name, name) == 0) {
            printf("%s was found at node %d\n", name, count);
            return;
        }
        current = current->next;
        count++;
    }
    printf("%s was not found\n", name);
}

// Delete contact
struct Node* deleteContact(struct Node* head, char *name) {
    //search and delete
    struct Node* current = head;
    if (strcasecmp(head->name, name) == 0) {
        head = head->next;
        free(current->name);
        free(current->num);
        free(current);
        printf("contact deleted\n");
        return head;
    }
    struct Node* previous = NULL;
    while (current != NULL && strcasecmp(current->name, name) <= 0) {
        if (strcasecmp(current->name, name) == 0) {
            previous->next = current->next;
            free(current->name);
            free(current->num);
            free(current);
            printf("Contact deleted\n");
            return head;
        }
        previous = current;
        current = current->next;
    }

    printf("Contact not found");
    return head;
}
