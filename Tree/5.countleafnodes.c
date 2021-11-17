#include <stdio.h>
#include <stdlib.h>
/**********Structure for tree******************/
struct node
{
	char data;
	struct node *Left;
	struct node *Right;
};
/********Make Node*************/
struct node *MakeNode(char x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}
/**************PreOrderTraversal DLR**************/
void PreOrderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		printf("\t%c",root->data);
		PreOrderTraversal(root->Left);
		PreOrderTraversal(root->Right);
	}
}
/***************In Order LDR****************/
void InOrderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		InOrderTraversal(root->Left);
		printf("\t%c",root->data);
		InOrderTraversal(root->Right);
	}
}
/***************Post Order LRD****************/
void  PostOrderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		PostOrderTraversal(root->Left);
		PostOrderTraversal(root->Right);
		printf("\t%c",root->data);
	}
}
/*******Count********/
int CountOfLeaf(struct node *t){
	if(t==NULL)
	return 0;
	else{
		if(t->Left==NULL&&t->Right==NULL)
			return 1;
	    else{
			return (CountOfLeaf(t->Left)+CountOfLeaf(t->Right));
		}
}
}
/**************Main function***********************/
int main()
{
	struct node *Tree=NULL;
	int count;
	Tree=MakeNode('A');
	Tree->Left=MakeNode('B');
	Tree->Left->Left=MakeNode('D');
	Tree->Right=MakeNode('C');
	Tree->Right->Left=MakeNode('E');
	Tree->Right->Right=MakeNode('F');
	/*printf("Pre Order Traversal : ");
	PreOrderTraversal(Tree);
	printf("\nIn Order Traversal : ");
	InOrderTraversal(Tree);
	printf("\nPost Order Traversal : ");
	PostOrderTraversal(Tree);*/
	count=CountOfLeaf(Tree);
	printf("\nCount of leaf node is: %d",count);
}
/************End Of code***********************************/	

