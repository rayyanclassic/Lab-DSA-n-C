#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertBeg() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
        head = tail = newnode;
    else {
        head->prev = newnode;
        head = newnode;
    }
}

void insertEnd() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = tail;

    if (tail == NULL)
        head = tail = newnode;
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteBeg() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;

    free(temp);
    printf("Node deleted from beginning\n");
}

void deleteEnd() {
    struct node *temp;

    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = tail;
    tail = tail->prev;

    if (tail == NULL)
        head = NULL;
    else
        tail->next = NULL;

    free(temp);
    printf("Node deleted from end\n");
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeg();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
