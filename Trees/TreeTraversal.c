#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*root;

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrderTraversal(struct Node* temp) {
    if(temp == NULL)
        return;
    printf("%d ", temp->data);
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
}

void inOrderTraversal(struct Node* temp) {
    if(temp == NULL)
        return;
    inOrderTraversal(temp->left);
    printf("%d ", temp->data);
    inOrderTraversal(temp->right);
}

void postOrderTraversal(struct Node* temp) {
    if(temp == NULL)
        return;
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    printf("%d ", temp->data);
}

int main() {
    root = createNode(10);
    root->left = createNode(8);
    root->left->left = createNode(6);
    root->left->right = createNode(9);
    root->right = createNode(14);
    root->right->left = createNode(11);
    root->right->right = createNode(16);
    printf("InOrder Traversal: ");
    inOrderTraversal(root);
    printf("\n");
    printf("PreOrder Traversal: ");
    preOrderTraversal(root);
    printf("\n");
    printf("PostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}
