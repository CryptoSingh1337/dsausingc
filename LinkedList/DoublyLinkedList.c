#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}*head = NULL, *tail = NULL;

int length = 0;

void insertBeg(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    if(head == NULL && tail == NULL) {
        head = tail = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    length++;
}

void insertLast(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL && tail == NULL) {
        head = tail = newNode;
        newNode->prev = NULL;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    length++;
}

void deleteBeg() {
    if(head == NULL) {
        printf("LinkedList Underflow!\n");
        return;
    }
    int element = head->data;
    head=head->next;
    head->prev = NULL;
    printf("\n%d - DELETED!\n", element);
    length--;
}

void deleteLast()
{
    if (tail == NULL)                 //    12   23  5   46  45
        {
        printf("LinkedList Underflow!\n");
        return;
    }
    int element = tail->data;
    tail=tail->prev;
    tail->next = NULL;
    printf("\n%d - DELETED!\n", element);
    length--;
}

void displayBeg() {
    if(head==NULL && tail == NULL) {
        printf("LinkedList Underflow!\n");
        return;
    }
    struct Node *temp = head;
    printf("\n-----DISPLAY FROM BEGINNING-----\n");
    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

}
void displayLast() {
    if (tail == NULL && head == NULL)
    {
        printf("\nQueue Underflow!\n");
        return;
    }
    struct Node *temp = tail;
    printf("\n-----DISPLAY FROM LAST-----\n");
    while (temp->prev != NULL)
    {
        printf("%d ", temp->data);
        temp= temp->prev;
    }
    printf("%d ", temp->data);
}

int main() {
    insertBeg(34);
    insertLast(54);
    insertLast(10);
    insertLast(12);
    displayBeg();
    printf("\n");
    deleteBeg();
    displayBeg();
    deleteLast();
    printf("\n");
    displayLast();
}