#include<stdio.h>
#include<stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int counter = 0;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*root = NULL;

static int count = -1;

void insertTree(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
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

void inOrderTraversal(struct Node* temp) {
    if(temp == NULL)
        return;
    inOrderTraversal(temp->left);
    printf("%d ", temp->data);
    inOrderTraversal(temp->right);
}

void searchTree(int element) {
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

void minTree() {
    struct Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    printf("Minimum Element: %d\n", temp->data);
}

void maxTree() {
    struct Node* temp= root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    printf("Maximum Element: %d\n", temp->data);
}


void heightTree(struct Node* temp) {
    
    if(temp == NULL) {
        if(counter > count) {
            count = counter;
        }
        return;
    }
    counter++;
    heightTree(temp->left);
    counter--;
    heightTree(temp->right);
}

int main() {
    int choice=-1,data;
    do{
        printf("----MENU for BINARY SEARCH TREE-----");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Search an element");
        printf("\n4. Find the minimum element");
        printf("\n5. Find the maximum element");
        printf("\n6. Find the height of the tree");
        printf("\n7. In Order traversal");
        printf("\n8. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 :
            printf("\nEnter the value to insert: ");
            scanf("%d", &data);
            insertTree(data);
            break;
        case 2 :
            printf("\nEnter the value to delete: ");
            scanf("%d", &data);
            // delete(data);
            break;
        case 3 :
            printf("\nEnter the value to search: ");
            scanf("%d", &data);
            searchTree(data);
            break;
        case 4 :
            minTree();
            break;
        case 5:
            maxTree();
            break;
        case 6:
            heightTree(root);
            printf("\nHeight of tree is: %d",count);
            break;
        case 7:
            inOrderTraversal(root);
            break;
        case 8:
            break;
        default:
            break;
        }
    } while(choice!=8);
    
    return 0;
}
