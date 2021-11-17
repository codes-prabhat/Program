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
/************Delete After******************************************/
void DelAft(struct node **last,struct node *p){
	struct node *q;
	if(p->next==*last){
		q=*last;
		p->next=(*last)->next;
		free(q);
		*last=p;
		return;
		}
	
	q=p->next;
	p->next=q->next;
	free(q);
}
/*************Josephus Problem*********************/
int JosephusProblem(struct node **last,int k){
	struct node *p,*q;
	p=(*last)->next;
	int c=1;
	while(p->next!=p){
		while(c<k){
			q=p;
			c=c+1;
			p=p->next;
		}
		p=p->next;
		c=1;
		DelAft(&(*last),q);
	}
	return p->info;
}
/*********Main Method*************/
int main(void){
		struct node *last1;
		last1=NULL;
		int n=40;
		int k=7;
for(int i=0;i<n;i++)
	InsEnd(&last1,i+1);
//Traverse(last1);
JosephusProblem(&last1,k);
Traverse(last1);	    
}
	
