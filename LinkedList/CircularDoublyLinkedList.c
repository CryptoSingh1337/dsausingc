#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}*head = NULL, *tail = NULL;

int length = 0;
void display(int);

void prepend(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        head = tail = node;
        node->next = head;
        node->prev = tail;
        length++;
        return;
    }
    node->next = head;
    node->prev = tail;
    head->prev = node;
    head = node;
    tail->next = head;
    length++;
}

void append(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        head = tail = node;
        node->prev = tail;
        node->next = head;
        length++;
        return;
    }
    node->prev = tail;
    node->next = head;
    tail->next = node;
    tail = node;
    length++;
}

void insertBefore(int index, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(index == 0) {
        prepend(data);
        return;
    }
    if(index == length-1) {
        append(data);
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    node->prev = temp->prev;
    node->next = temp;
    temp->prev->next = node;
    temp->prev = node;
    length++;
}

void insertAfter(int index, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    int i = 1;
    struct Node* temp = head;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    node->prev = temp;
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
    length++;
}

void removeBeg() {
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    printf("Deleted Element : %d\n", head->data);
    head = head->next;
    head->prev = tail;
    tail->next = head;
    length--;
    printf("\t");
    display(0);
}

void removeLast() {
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    printf("Deleted Element: %d\n", tail->data);
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    length--;
    printf("\t");
    display(0);

}

void removeIndex(int index) {
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    if(index == 0) {
        removeBeg();
        return;
    }
    if(index == length-1) {
        removeLast();
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    printf("Deleted Element : %d\n", temp->data);
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    length--;
    printf("\t");
    display(0);
}

void display(int reverse) {
    if(reverse) {
        struct Node* temp = tail;
        while(temp->prev != tail) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("%d\n", temp->data);
    } else {
        struct Node* temp = head;
        while(temp->next != head) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void search(int element) {
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(temp->next != head) {
        if(temp->data == element) {
            printf("Element is present at position %d\n", i);
            return;
        }
        temp = temp->next;
        i++;
    }
    if(temp->data == element) {
        printf("Element is present at position %d\n", i);
    } else {
        printf("Element is not present!\n");
    }
}

int main() {
    removeBeg();
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    display(0);
    prepend(0);
    display(0);
    insertBefore(2, 6);
    display(0);
    insertAfter(2, 7);
    display(0);
    printf("Reverse order traversal:\n");
    printf("\t");
    display(1);
    removeBeg();
    removeLast();
    removeIndex(3);
    search(4);
    search(2);
    return 0;
}
