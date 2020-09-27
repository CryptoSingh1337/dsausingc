#include<stdio.h>
#include<stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

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
        return;
    }
    struct Node* temp = root;
    while(1) {
        if(temp->data > data) {
            if(temp->left == NULL) {
                temp->left = node;
                return;
            }
            temp = temp->left;
        } else {
            if(temp->right == NULL) {
                temp->right = node;
                return;
            }
            temp = temp->right;
        }
    }
}

void getMin() {
    struct Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    printf("Minimum Element: %d\n", temp->data);
}

void getMax() {
    struct Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    printf("Minimum Element: %d\n", temp->data);
}

void lookup(int element) {
    if(root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    struct Node* temp = root;
    while(temp != NULL) {
        if(temp->data == element) {
            printf("Element is present!\n");
            return;
        } else if(temp->data > element) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    printf("Element is not present!\n");
}

int getHeight(struct Node* temp) {
    int height = 0;
    if(temp == NULL) {
        return 0;
    }
    int lHeight = getHeight(temp->left);
    int rHeight = getHeight(temp->right);
    if(lHeight > rHeight)
        return lHeight+1;
    return rHeight+1;
}

void inOrderTraverse(struct Node* temp) {
    if(temp == NULL) {
        return;
    }
    inOrderTraverse(temp->left);
    printf("%d ", temp->data);
    inOrderTraverse(temp->right);
}

void preOrderTraverse(struct Node* temp) {
    if(temp == NULL) {
        return;
    }
    printf("%d ", temp->data);
    preOrderTraverse(temp->left);
    preOrderTraverse(temp->right);
}

void postOrderTraverse(struct Node* temp) {
    if(temp == NULL) {
        return;
    }
    postOrderTraverse(temp->left);
    postOrderTraverse(temp->right);
    printf("%d ", temp->data);
}

int main() {
    insert(3);
    insert(1);
    insert(4);
    insert(0);
    insert(5);
    insert(2);
    insert(6);
    inOrderTraverse(root);
    printf("\n");
    preOrderTraverse(root);
    printf("\n");
    postOrderTraverse(root);
    printf("\n");
    lookup(10);
    printf("Height : %d", getHeight(root));
    return 0;
}
