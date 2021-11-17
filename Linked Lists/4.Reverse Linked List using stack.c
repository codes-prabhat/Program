#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
/************************************************************************Linked List data structure****************************************************************************************/
/****Structure of Node**********/
struct node
{
	char info;
	struct node *next;
};
struct node *start;
/*********Free Node******/
void FreeNode(struct node *p){
	free(p);
}
/**********Get Node function creates node when called*********/
struct node *GetNode(){
	struct node *P;
	P=(struct node *) malloc(sizeof(struct node));
	return P;
}
/******Inserts Elements in Beginning of LL*************/
void InsBeg(char x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=start;
	start=p;
}
/********Inserts Elements in End of linked list**********/
void InsEnd(char x){
	struct node *p,*temp;
	p=GetNode();
	temp=start;
	if(temp==NULL){
		InsBeg(x);
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
/*********Inserts Elemets After specific Node*******************/
void InsAft(char c,char x){
	struct node *temp,*p;
	temp=start;
	while(temp!=NULL){
		if(temp->info==c){
		break;
		}
		else{
		temp=temp->next;
		}
	}
	if(temp!=NULL){
		p=GetNode();
		p->info=x;
		p->next=temp->next;
		temp->next=p;
	}
	else{
		printf("Void Insertion");
	}
}
/***************Delete's Elements in Beginning of LL************/
char DelBeg(){
	if(start!=NULL){
	struct node *p;
	char c;
	p=start;
	start=p->next;
	c=p->info;
	FreeNode(p);
	return c;
	}
	else{
		printf("\nVoid Deletion\n");
	}
	return 0;
}
/********Delete After a node******************/
char DelEnd(){
	if(start!=NULL){
		struct node *p,*q;
		char c;
		p=start;
		q=NULL;
		while(p->next!=NULL){
			q=p;
			p=p->next;
		}
		if(q!=NULL){
		q->next=NULL;
		c=p->info;
		FreeNode(p);
		return c;
		}//if only one element in linked list
		else{
			c=p->info;
			start=NULL;
			FreeNode(p);
			return c;
		}
	}
	else{
		printf("\nVoid Deletion\n");
	}
	return 0;
}
/************Delete After a Node [do not use not written correctly]***/
char DelAft(char c){
	char x;
	struct node *p,*q;
	p=start;
	while(p->next!=NULL){
		if(p->info==c){
			break;
		}
		else{
			p=p->next;
		}
	}
	q=p->next;
	p=q->next;
	x=q->info;
	FreeNode(q);
	return x;
}
/********Prints all elements in Linked List**************/
void Traverse(){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%c\t",p->info);
		p=p->next;
	}
}
/********************************************************************************Stack data structure****************************************************************************************/
struct stack{
	int top;
	char arr[SIZE];
};
struct stack s;
void initialize(){
	s.top=-1;
}
int isEmpty(){
	return (s.top==-1);
}
int isFull(){
	return (s.top==SIZE-1);
}
char push(char x){
	if(isFull()){
	printf("Overflow Condition can't push '%c'",x);
	exit(1);
    }
	s.top++;
	s.arr[s.top]=x;
	return x;
}
char pop(){
	int x;
	if(isEmpty()){
		printf("Underflow Condition");
		exit(1);
	}
	x=s.arr[s.top];
	s.top--;
	return x;
}
char stacktop(){
	int x;
	if(isEmpty()){
		printf("Stack is Empty");
		exit(1);
	}
	x=s.arr[s.top];
	return x;
}
void display(){
	if(isEmpty()){
		printf("Stack is Empty");
		exit(1);
	}
	for(int i=s.top;i>=0;i--){
		printf("%c\n",s.arr[i]);
	}
}
/****************Reverse LL*********************************************************/
void ReverseLL(){
	initialize();
	struct node *p;
	p=GetNode();
	p=start;
	while(p!=NULL){
		push(p->info);
		p=p->next;
	}
	p=start;
	while(!isEmpty()){
		p->info=pop();
		p=p->next;
	}
}
/********************************************************************************************Driver Code*****************************************************************************************/
int main(void){
	InsEnd('A');
	InsEnd('B');
	InsEnd('C');
	InsEnd('D');
	printf("Before Reversing\n");
	Traverse();
	printf("\nAfter Reversing\n");
	ReverseLL();
	Traverse();
	return 0;
}
