//Program for Stack Primitive Operations using linked list
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 5
#include <stdio.h>
#include <stdlib.h>
/****Structure of Node**********/
struct node
{
	int info;
	struct node *next;
};
/**********Get Node function creates node when called*********/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/******Inserts Elements in Beginning of LL*************/
void PUSH(struct node **Top,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=*Top;
	*Top=p;
}
/***************Delete's Elements in Beginning of LL************/
int POP(struct node **Top){
	if(*Top!=NULL){
	struct node *p;
	int c;
	p=*Top;
	*Top=p->next;
	c=p->info;
	free(p);
	return c;
	}
	else{
		printf("\nVoid Deletion\n");
	}
	return 0;
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *Top){
	struct node *p;
	p=Top;
	while(p!=NULL){
		printf("%d\t",p->info);
		p=p->next;
	}
}
/*********Main Method*************/
int main(void){
		struct node *Top1;
		Top1=NULL;
		PUSH(&Top1,1);
		PUSH(&Top1,2);
		PUSH(&Top1,3);
		PUSH(&Top1,4);
		PUSH(&Top1,5);
        PUSH(&Top1,6);
		PUSH(&Top1,7);
	    PUSH(&Top1,8);
		PUSH(&Top1,0);
		POP(&Top1);
		Traverse(Top1);
		printf("\n");
	    
}
/**********************************************************************/
/*********************************************************************/
/*****This way it can also be done************************************/
//Program for Stack Primitive Operations using linked list
#include <stdio.h>
#include <stdlib.h>
/****Structure of Node**********/
struct node
{
	int info;
	struct node *next;
};
/**********Get Node function creates node when called*********/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/**delete end*************************************/
int DelBeg(struct node **Top){
if(*Top!=NULL){
	struct node *p;
	int c;
	p=*Top;
	*Top=p->next;
	c=p->info;
	free(p);
	return c;
	}
	else{
		printf("Underflow Condition");
	}
	return 0;
}
/****Insert Beginning**********************/
void InsBeg(struct node **Top,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=*Top;
	*Top=p;
}
/******Inserts Elements in Beginning of LL*************/
void PUSH(struct node **Top,int x){
InsBeg(&(*Top),x);
}
/***************Delete's Elements in Beginning of LL************/
int POP(struct node **Top){
	return DelBeg(&(*Top));
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *Top){
	struct node *p;
	p=Top;
	while(p!=NULL){
		printf("%d\t",p->info);
		p=p->next;
	}
}
/*********Main Method*************/
int main(void){
		struct node *Top1;
		Top1=NULL;
		PUSH(&Top1,1);
		PUSH(&Top1,2);
		PUSH(&Top1,3);
		PUSH(&Top1,4);
		PUSH(&Top1,5);
        PUSH(&Top1,6);
		PUSH(&Top1,7);
	    PUSH(&Top1,8);
		PUSH(&Top1,0);
		POP(&Top1);
		Traverse(Top1);
		printf("\n");
	    
}
/********************************************************************/
