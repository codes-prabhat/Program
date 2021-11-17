#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node
{
	char info;
	struct node *next;
};
struct node *REAR,*FRONT;
void Initialize(){
	REAR=NULL;
	FRONT=NULL;
}
struct node* GetNode(){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	return p;
}
int Empty(){
	if(FRONT==NULL)
	return TRUE;
	else
	return FALSE;
}
char EnQueue(char x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=NULL;
	if(REAR==NULL)
	{
		REAR=p;
		REAR=p;
	}
	return x;
}
char DeQueue(){
	char x;
	struct node *p;
	if(Empty())
	{
		printf("Queue underflow");
		exit(1);
	}
	p=FRONT;
	FRONT=FRONT->next;
	x=p->info;
	free(p);
	if(FRONT==NULL)
	REAR =NULL;
	return x;
}
int main(){
	char x;
	Initialize();
	EnQueue('A');
	EnQueue('B');
	EnQueue('C');
	printf("%c",EnQueue('D'));
	EnQueue('E');
	EnQueue('F');
	x=DeQueue();
	printf("%c",x);
	return 0;
	
}
