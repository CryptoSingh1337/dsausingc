#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*front = NULL, *rear = NULL;

int length = 0;

//Insertion at the rear position
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    length++;
} 


void delete() {
    if(front== NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    int element = front->data;
    front = front->next;
    length--;
    printf("%d - Deleted!\n", element);
}

void display() {
    struct Node* temp = front;
    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    delete();
    insert(3);
    insert(5);
    insert(6);
    display();
    insert(52);
    delete();
    display();
    return 0;
}