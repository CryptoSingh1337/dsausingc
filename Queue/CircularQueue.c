#include<stdio.h>

int queue[5];
int front = -1, rear = -1;
int capacity = 5;
int size = 0;

int isEmpty() {
    if(front == -1 && rear == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if((rear+1)%capacity == front) {
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
        front = 0;
        rear = 0;
    } else {
        rear = (rear+1)%capacity;
    }
    queue[rear] = element;
    size++;
}

int deQueue() {
    int element;
    if(isEmpty()) {
        printf("Queue is Empty!\n");
        return -1;
    }
    element = queue[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front+1)%capacity;
    }
    size--;
    return element;
}

void print() {
    if(isEmpty()) {
        printf("Queue is Empty!");
        return;
    }
    if(rear >= front) {
        for(int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for(int i = front; i < size; i++) {
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);     //Queue Overflow
    printf("Element deleted: %d\n", deQueue());
    print();
    enQueue(6);
    print();
    printf("Element deleted: %d\n", deQueue());
    printf("Element deleted: %d\n", deQueue());
    return 0;
}
