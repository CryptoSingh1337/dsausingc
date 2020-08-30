/*
 * Stack Implementation using Arrays
 */

#include<stdio.h>

int top = -1;
int capacity = 5;
int stack[5];
int size = 0;

void push(int element) {
    if(top == capacity-1) {
        printf("Stack Overflow!\n");
        return;
    }
    top += 1;
    stack[top] = element;
    size++;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int element = stack[top];
    top -= 1;
    size--;
    return element;
}

int peek() {
    return stack[top];
}

void print() {
    if(size == 0) {
        printf("Stack is empty!");
        return;
    }
    for(int i = 0;i < size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    print();
    pop();
    print();
    printf("%d\n", peek());
    return 0;
}



