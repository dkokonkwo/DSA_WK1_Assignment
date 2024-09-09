#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main() {
    // Arrays to be converted to linked list
    int *names[8] = {3, 2, 7, 5, 9, 6, 4, 8};
    char *num[8] = {};
    
    char *new_contact[2] = {"Jack Reacher", "23436078956"};

    // Convert array to linked list
    struct Node* head = arrayToLinkedList(names, num, 8);

    //Print the linked list
    printLinkedList(head);

    addContact(head, new_contact[0], new_contact[1]);

    // Print the linked list
    printLinkedList(head);

    // name in linked list
    searchContact("Jon Jones");

    //name not in linked list
    searchContact("Emma Watson");

    //delete contact
    deleteContact(new_contact[0]);

    //Print linked list
    printLinkedList(head);

    return(0);
}
