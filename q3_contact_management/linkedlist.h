#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node* addContact(struct Node* head, char *name, char *num);
struct Node* deleteContact(struct Node* head, char *name);
void searchContact(struct Node* head, char *name);
struct Node* createNode(char *name, char *num);
struct Node* arrayToLinkedList(char *names[], char *num[], int size);
void printLinkedList(struct Node* head);

/**
 * struct Node - Represents contact in a linked list
 *
 * @name: name of contact
 * @num: phone number of contact
 * @next: pointer to next contact in list
 */
struct Node {
    char *name;
    char *num;
    struct Node* next;
};

#endif
