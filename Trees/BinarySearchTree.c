#include<stdio.h>
#include<stdlib.h>
#define max(A,B) (A > B)?A:B

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*root = NULL;

void insert(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    if(root == NULL) {
        root = node;
        printf("%d is the root node\n", data);
        return;
    }
    struct Node* temp = root;
    while(1) {
        if(temp->data > data) {
            if(temp->left == NULL) {
                temp->left = node;
                printf("%d is the left child of %d\n", data, temp->data);
                return;
            }
            temp = temp->left;
        } else {
            if(temp->right == NULL) {
                temp->right = node;
                printf("%d is the right child of %d\n", data, temp->data);
                return;
            }
            temp = temp->right;
        }
    }
}

void contains(int element) {
    int level = 0;
    if(root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    struct Node* temp = root;
    while(temp != NULL) {
        if(temp->data == element) {
            printf("Element is present at level: %d\n", level);
            return;
        } else if(temp->data > element) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        level++;
    }
    printf("Element is not present!\n");
}

int getHeight(struct Node* temp) {
    if(temp == NULL) {
        return 0;
    }
    int left = getHeight(temp->left);
    int right = getHeight(temp->right);
    return max(left, right)+1;
}

void display(struct Node* temp) {
    if(temp == NULL)
        return;
    display(temp->left);
    printf("%d ", temp->data);
    display(temp->right);
}

int main() {
    insert(10);
    insert(8);
    insert(9);
    insert(6);
    insert(14);
    insert(16);
    insert(11);
    printf("BST: ");
    display(root);
    printf("\n");
    contains(6);
    contains(5);
    printf("Height of the tree: %d\n", getHeight(root));
    return 0;
}
