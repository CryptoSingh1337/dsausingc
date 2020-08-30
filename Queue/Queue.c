#include<stdio.h>

int queue[5];
int capacity = 5;
int top = -1, rear = -1;

int isFull() {
    if(rear == capacity-1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(top == -1 && rear == -1) {
        return 1;
    }
    return 0;
}

void enQueue(int element) {
    if(isFull()) {
        printf("Queue is Full!\n");
        return;
    }
    if(isEmpty()) {
        top = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = element;
}

int deQueue() {
    int element;
    if(isEmpty()) {
        printf("Queue is Empty!\n");
        return -1;
    }
    element = queue[top];
    if(top == rear) {
        top = -1;
        rear = -1;
    } else {
        top++;
    }
    return element;
}

void print() {
    if(isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("[");
    for(int i = top; i <= rear; i++) {
        if(i == rear)
            printf("%d]\n", queue[i]);
        else
            printf("%d,", queue[i]);
    }
}

int main() {
    deQueue();
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);     //Queue Overflow!
    print();
    printf("Element deleted: %d\n", deQueue());
    printf("Element deleted: %d\n", deQueue());
    printf("Element deleted: %d\n", deQueue());
    printf("Element deleted: %d\n", deQueue());
    printf("Element deleted: %d\n", deQueue());
    deQueue();
    print();
    return 0;
}

