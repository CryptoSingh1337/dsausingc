#include<stdio.h>
#include<stdlib.h>
#define capacity 5

//LIFO

struct Node {
    int data;
    struct Node* next;
}*head = NULL, *top = NULL;

int length = 0;

void insert(int element) {
    if(length == capacity) {
        printf("Stack Overflow!\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        length++;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    top = temp;
    length++;
}

int remove1() {

    if(head == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    // struct Node* temp = head;
    // int i =1;
    // while(i < length) {
    //     temp = temp->next;
	//     i++;
    // }
    // while(temp->next->next != NULL) {
    //     temp = temp->next;
    // }
    // int element = temp->next->data;
    int element = top->next->data;
	top->next = NULL;
    return element;
}

void display() {
    struct Node* temp = head;
    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main() {
    remove1();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    printf("%d\n", remove1());
    display();
}