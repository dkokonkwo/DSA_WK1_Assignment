#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main() {
    // Arrays to be converted to linked list
    char *names[8] = {
    "Emma Johnson",
    "Liam Smith",
    "Olivia Brown",
    "Noah Davis",
    "Jon Jones",
    "William Martinez",
    "Sophia Anderson",
    "James Taylor",
        };
    char *num[8] = {
    "123-456-7890",
    "234-567-8901",
    "345-678-9012",
    "456-789-0123",
    "567-890-1234",
    "678-901-2345",
    "789-012-3456",
    "890-123-4567",
        };
    
    char *new_contact[2] = {"Jack Reacher", "234-360-7895"};

    // Convert array to linked list
    struct Node* head = arrayToLinkedList(names, num, 8);

    //Print the linked list
    printf("Original linked list\n");
    printLinkedList(head);

    head = addContact(head, new_contact[0], new_contact[1]);

    // Print the linked list
    printf("Linked list after adding contact\n");
    printLinkedList(head);

    // name in linked list
    printf("searchiing for contact in list\n");
    searchContact(head, "Jon Jones");

    //name not in linked list
    printf("Searching for another contact\n");
    searchContact(head, "Emma Watson");

    //delete contact
    head = deleteContact(head, new_contact[0]);

    //Print linked list
    printf("Printing updated linked list\n");
    printLinkedList(head);

    return(0);
}
