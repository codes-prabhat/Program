#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
/****Structure of Node**********/
struct node
{
	int info;
	int visited;
	struct node *next;
	
};
/**********Get Node function creates node when called*********/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/******Inserts Elements in Beginning of LL*************/
void InsBeg(struct node **start,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=*start;
	*start=p;
}
/********Inserts Elements in End of linked list**********/
void InsEnd(struct node **start,int x){
	struct node *p,*temp;
	p=GetNode();
	temp=*start;
	if(temp==NULL){
		InsBeg(start,x);
	}
	else{
	while(temp->next!=NULL){
		temp=temp->next;
	}
	p->info=x;
	p->next=NULL;
	temp->next=p;
}
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d",p->info);
		p=p->next;
		if(p!=NULL)
		printf("->");
	}
}
/*********************Intersection*************************************/
void FindIntersection(struct node *list1,struct node *list2){
	struct node *p,*q;
	p=list1;
	q=list2;
	while(p!=NULL){
		p->visited=TRUE;
		p=p->next;
	}
	while(q!=NULL){
		if(q->visited==TRUE){
			printf("The intersection is at node %d",q->info);
			return;
		}
		q=q->next;
	}
	printf("No intersection between given Linked lists");
}
/*********Main Method(Driver Code)*************/
int main(void){
		struct node *start1,*start2,*start3;
		start1=NULL;
		start2=NULL;
		start3=NULL;
		InsEnd(&start1,10);
		InsEnd(&start1,20);
		InsEnd(&start1,30);
		InsEnd(&start1,40);
		InsEnd(&start1,50);
		InsEnd(&start1,90);
		InsEnd(&start2,20);
		InsEnd(&start2,70);
		InsEnd(&start2,80);
		InsEnd(&start2,90);
		InsBeg(&start2,10);
		Traverse(start1);
		printf("\n");
		Traverse(start2);
		/*intersection at  30*/
		start2->next->next->next->next->next=start1->next->next;
		printf("\n");
	    FindIntersection(start1,start2);
	    Traverse(start3);
}

