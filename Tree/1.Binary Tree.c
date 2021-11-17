#include <stdio.h>
#include <stdlib.h> 
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
struct node{
	char info;
	struct node* left;
	struct node* right;
};
/****************Creating TRee node with given info*******************/
struct node *CreateNode(char x){
	struct node *treenode;
	treenode=(struct node *)malloc(sizeof(struct node *));
	treenode->info=x;
	treenode->left=NULL;
	treenode->right=NULL;
	return treenode;
}
/***********Inordered Traversal****************************************/
void InTraversal(struct node *root){
	if(root==NULL)
	  return;
	InTraversal(root->left);
	printf("%c ",root->info);
	InTraversal(root->right);
}
/***********Inordered Traversal****************************************/
void PostTraversal(struct node *root){
	if(root==NULL)
	  return;
	PostTraversal(root->left);
	PostTraversal(root->right);
	printf("%c ",root->info);
}
/***********Inordered Traversal****************************************/
void PreTraversal(struct node *root){
	if(root==NULL)
	  return;
	printf("%c ",root->info);
	PreTraversal(root->left);
	PreTraversal(root->right);
}
/***********Height of Tree*********************************************/
int Height(struct node *root){
	if(root==NULL){
		return 0;
	}
	else if(root->left==NULL && root->right==NULL){
		return 0;
	}
	else{
		return MAX(Height(root->left),Height(root->right))+1;
	}
}
/**************main-Driver*********************************************/
int main(void){
	struct node *root;
	root=NULL;
	root=CreateNode('A');
	root->left=CreateNode('B');
	root->right=CreateNode('C');
	root->left->left=CreateNode('D');
	
	printf("In: ");
	InTraversal(root);
	
	printf("\nPre: ");
	PreTraversal(root);
	
	printf("\nPost: ");
	PostTraversal(root);
	
	int h=Height(root);
	
	printf("\nHeight: %d ",h);
	
	return 0;
}
