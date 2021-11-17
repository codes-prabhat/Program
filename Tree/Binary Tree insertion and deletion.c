#include <stdlib.h>
#include <stdio.h>
/*********Structure for binary Tree***********/
struct btree {
int data;
struct btree * right, * left;
};
/******defining node*************/
typedef struct btree node;
/*******Insert Function for binary tree***************/
void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
/************Preorder Traversal***********************/
void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\t",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}
/***********inorder Traversal******************************/
void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\t",tree->data);
        print_inorder(tree->right);
    }
}
/***********post order traversal*******************************/
void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\t",tree->data);
    }
}
/*****************deleteting from tree*****************/
/*void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}*/
/************searching in tree*********************/
node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
    return 0;
}
/************Minimum*****************/
node* BMin(node **tree){
	while((*tree)->left!=NULL){
		(*tree)=(*tree)->left;
	}
	return *tree;
}
/**********Maximum******************/
node* BMax(node **tree){
	while((*tree)->right!=NULL){
		(*tree)=(*tree)->right;
	}
	return *tree;
}

/**********main function***********/
int main(void)
{
    node *root;
    node *tmp;
    

    root = NULL;
    /* Inserting nodes into tree */
    int arr[]={3,5,6,8,19,45,23,89};
    int l=sizeof(arr)/sizeof(arr[0]);
    /*insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);*/
    for(int i=0;i<l;i++){
		insert(&root,arr[i]);
	}

    /* Printing nodes of tree */
   /* printf("Pre Order Display\n");
    print_preorder(root);*/

    printf("\nIn Order \n");
    print_inorder(root);

    /*printf("\nPost Order Display\n");
    print_postorder(root);*/

    /* Search node into tree */
    tmp = search(&root,3);
    if (tmp)
    {
        printf("\nSearched node=%d", tmp->data);
    }
    else
    {
        printf("\nData Not found in tree.");
    }
    tmp=BMin(&root);
    printf("\nMinimum Element is : %d",tmp->data);
    tmp=BMax(&root);
    printf("\nMaximum Element is : %d",tmp->data);
    /* Deleting all nodes of tree
    deltree(root);*/
    return 0;
}
/*****************End of code**************************/
