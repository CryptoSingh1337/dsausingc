#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}*head = NULL;

int length = 0;

//To remove from begining of the list
int removeBegin() {
    if(head == NULL) {
        printf("Linked List is empty!");
        return -1;
    }
    int element = head->data;
    head = head->next;
    length--;
    return element;
}

//To remove from last of the list
int removeLast() {
    if(head == NULL) {
        printf("Linked List is empty!");
        return -1;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    int element = temp->next->data;
    temp->next = NULL;
    length--;
    return element;
}

//To remove form middle of the list
int removeIndex(int index) {
    if (head == NULL || index > length){
        if(index > length)
            printf("Invalid Index!");
        else
            printf("Linked List is Empty!");
        return -1;
    }
    struct Node *temp = head;
    if(index == 0) {
        head=temp->next;
        length--;
        return index;
    }
    int count = 0;
    while(count < index-1) {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
    length--;
    return index;
}

//This will insert the node at the beginning of List
void insertBeg(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL) {
        node->next = NULL;
        head = node;
        length++;
        return;
    }
    node->next = head;
    head = node;
    length++;
}

//This will insert the node at the end of List
void insertLast(int data) {                
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if(head == NULL) {
        head = node;
        length++;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    length++;
}

//This will insert in the middle of the List
void insertIndex(int data, int index) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(index == 0) {
        insertBeg(data);
        length++;
        return;
    }
    if(index > length) {
       insertLast(data);
       length++;
        return;
    }
    int i = 0;
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
    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main() {
    insertIndex(32, 0);
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    insertBeg(0);
    display();
    insertIndex(23, 3);
    printf("\n%d\n", removeIndex(1));
    display();
}
