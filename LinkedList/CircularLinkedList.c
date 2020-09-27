#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head = NULL;

int length = 0;

void prepend(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        head = node;
        node->next = head;
        length++;
        return;
    }
    node->next = head;
    struct Node *temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    head = node;
    temp->next = head;
    length++;
}

void append(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        head = node;
        node->next = head;
        length++;
        return;
    }
    struct Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    node->next = head;
    temp->next = node;
    length++;
}

void insert(int index, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        head = node;
        node->next = head;
        length++;
        return;
    }
    if(index == 0) {
        prepend(data);
        return;
    }
    if(index >= length-1) {
        append(data);
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(i < index) {
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;
    length++;
}

void display() {
    struct Node* temp = head;
    while(temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

int main() {
    append(0);
    append(1);
    append(2);
    append(3);
    append(4);
    display();
    prepend(5);
    display();
    insert(3, 6);
    display();
    return 0;
}
