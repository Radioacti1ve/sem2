#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    printf("Element '%c' inserted successfully.\n", value);
}

void removeElement(char value) {
    Node* currentNode = head;
    Node* prevNode = NULL;

    while (currentNode != NULL && currentNode->data != value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Element '%c' not found in the list.\n", value);
        return;
    }

    if (prevNode == NULL) {
        head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    free(currentNode);
    printf("Element '%c' removed successfully.\n", value);
}

void printList() {
    printf("List: ");

    Node* currentNode = head;

    while (currentNode != NULL) {
        printf("%c ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

int countLength() {
    int length = 0;
    Node* currentNode = head;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

void removeMiddleElements(int k) {
    int length = countLength();

    if (length <= 2 * k) {
        printf("Insufficient elements in the list for removal.\n");
        return;
    }

    Node* currentNode = head;
    Node* prevNode = NULL;

    for (int i = 0; i < length / 2; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    for (int i = 0; i < k; i++) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    prevNode->next = currentNode;

    printf("%d elements removed from the middle of the list.\n", k);
}

int main() {
    int choice;
    char value;
    int k;

    do {
        printf("\nMenu:\n");
        printf("1. Print the list\n");
        printf("2. Insert a new element into the list\n");
        printf("3. Remove an element from the list\n");
        printf("4. Count the length of the list\n");
        printf("5. Remove k elements from the middle of the list\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program.\n");
                break;
            case 1:
                printList();
                break;
            case 2:
                printf("Enter the value of the element to insert: ");
                scanf(" %c", &value);
                insert(value);
                break;
            case 3:
                printf("Enter the value of the element to remove: ");
                scanf(" %c", &value);
                removeElement(value);
                break;
            case 4:
                printf("Length of the list: %d\n", countLength());
                break;
            case 5:
                printf("Enter the number of elements to remove from the middle: ");
                scanf("%d", &k);
                removeMiddleElements(k);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Free memory before exiting
    Node* currentNode = head;
    while (currentNode != NULL) {
        Node* tempNode = currentNode->next;
        free(currentNode);
        currentNode = tempNode;
    }

    return 0;
}
