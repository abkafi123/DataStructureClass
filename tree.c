#include <stdio.h>
#include <stdlib.h>
 
// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 

void printInorder(struct node* node)
{
    // left -> root -> right
    if (node == NULL)
        return;
 
    printInorder(node->left);
 
    printf("%d ", node->data);

    printInorder(node->right);
}

 void printPreorder(struct node* node)
{
    // root -> left-> right
    if (node == NULL)
        return;
 

    printf("%d ", node->data);

    printPreorder(node->left);
 
    printPreorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    //left -> right-> root
    printPostorder(node->left);
 
    printPostorder(node->right);
 
    printf("%d ", node->data);
}


int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    // Function call
    printf("Inorder traversal of binary tree is \n");
    printInorder(root);
 
    getchar();
    return 0;
}