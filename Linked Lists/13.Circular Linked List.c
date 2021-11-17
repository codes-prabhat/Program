#include <stdio.h>
#include <stdlib.h>
/****Structure of Node**********/
struct node
{
	int info;
	struct node *next;
};
/*********Free Node******/
void FreeNode(struct node *p){
	free(p);
}
/**********Get Node function creates node when called*********/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/******Inserts Elements in Beginning of LL*************/
struct node* InsBeg(struct node **last,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	if(*last==NULL){
		*last=p;
		(*last)->next=*last;
	}
	else{
	 p->next=(*last)->next;
	 (*last)->next=p;
 }
 return p;
}
/********Inserts Elements in End of linked list**********/
struct node* InsEnd(struct node **last,int x){
	struct node *p,*temp;
	p=GetNode();
	temp=*last;
	if(temp==NULL){
		return InsBeg(last,x);
	}
	else{
	p->info=x;
	p->next=temp->next;
	temp->next=p;
	*last=p;
}
return *last;
}
/****Insert After a Node***********/
struct node* InsAft(struct node **last,struct node**p,int x){
	struct node *q;
	if((*p)==NULL){
		return InsBeg(last,x);
	}
	if((*p)->next==*p){
		return InsEnd(last,x);
	}
	q=GetNode();
	q->info=x;
	q->next=(*p)->next;
	(*p)->next=q;
	return q;
}
/***************Delete's Elements in Beginning of LL************/
int DelBeg(struct node **last){
	if(*last!=NULL){
		if((*last)->next==*last){
			struct node *temp;
			temp=*last;
			free(temp);
			*last=NULL;
			return 0;
					
		}
	struct node *p;
	int c;
	p=(*last)->next;
	(*last)->next=p->next;
	c=p->info;
	FreeNode(p);
	return c;
	}
	else{
		printf("\nVoid Deletion\n");
	}
	return 0;
}
/***********Delete End***************************/
int DelEnd(struct node **last){
	struct node *p,*q;
	p=*last;
	if((*last)->next==*last)
		return DelBeg(last);
	while(p->next!=*last){
		p=p->next;
	}
	p->next=(*last)->next;
	q=*last;
	int x=q->info;
	*last=p;
	free(q);
	return x;
}
/**************************print Linked List**************************/
void Traverse(struct node *last){
	if(last==NULL)
		return;
	struct node *p;
	p=last->next;
	do{
		printf("%d\t",p->info);
		p=p->next;
	}while(p!=last->next);
}
/*********Main Method*************/
int main(void){
		struct node *last1,*p;
		last1=NULL;
		p=last1;
		InsBeg(&last1,1);
		InsBeg(&last1,10);
		InsBeg(&last1,20);
		InsBeg(&last1,30);
		p=InsEnd(&last1,2);
		InsEnd(&last1,3);
		InsEnd(&last1,4);
		InsEnd(&last1,5);
		InsAft(&last1,&p,22);
		Traverse(last1);
		printf("\n");
		DelBeg(&last1);
		Traverse(last1);
				printf("\n");
		DelBeg(&last1);
		Traverse(last1);
				printf("\n");
		DelEnd(&last1);
		Traverse(last1);
				printf("\n");
		
	
	    
}
	
