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
/*********Inserts Elemets After specific Node*******************/
void InsAft(struct node **start,char c,char x){
	struct node *temp,*p;
	temp=*start;
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
/**************Insert at Specific Position*****************************/ 
void InsAt(struct node **start,int position,int x){
	struct node *temp,*newnode;
	temp=*start;
	if(x==0){
		InsBeg(start,x);
		return;
	}
	for(int i=0;i<position-1;i++){
		temp=temp->next;
	}
	newnode=GetNode();
	newnode->info=x;
	newnode->next=temp->next;
	temp->next=newnode;
}
/***************Delete's Elements in Beginning of LL************/
int DelBeg(struct node **start){
	if(*start!=NULL){
	struct node *p;
	int c;
	p=*start;
	*start=p->next;
	c=p->info;
	FreeNode(p);
	return c;
	}
	else{
		printf("\nVoid Deletion\n");
	}
	return 0;
}
/*************************Delete After a node*************************/
int DelEnd(struct node **start){
	if(*start!=NULL){
		struct node *p,*q;
		int c;
		p=*start;
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
/******************Delete After a Node*********************************/
int DelAft(struct node **start,int c){
	int x;
	struct node *p,*q;
	p=*start;
	while(p->next!=NULL){
		if(p->info==c){
			break;
		}
		else{
			p=p->next;
		}
	}
	if(p->next!=NULL){
	q=p->next;
	p->next=q->next;
	x=q->info;
	FreeNode(q);
	return x;
	}
	else{
		printf("\nVoid Deletion\n");
		return 0;
	}
	return 0;
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d\t",p->info);
		p=p->next;
	}
}
/*****************Concatenate******************************************/
struct node *ConcatenationLL(struct node *start1,struct node *start2){
	struct node *p;
	p=start1;
	if(start1!=NULL){
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=start2;
		return start1;
	}
	else{
		if(start2==NULL){
			return NULL;
		}
		else{
			return start2;
		}
	}
	
}
/**************Delete specific node**********************************/
int DelSpecific(struct node **start,int x){
	struct node *c,*p;
	int n;
	c=*start;
	if(c->info!=x){
	while(c->next!=NULL){
		if(c->info==x){
			break;
		}
		p=c;
		c=c->next;
	}
	if(c->info==x){
	p->next=c->next;
	n=c->info;
	FreeNode(c);
   }
   }
   else{
	   n=DelBeg(start);
   }
	return n;
}
/*********Main Method*************/
int main(void){
		struct node *start1,*start2,*start3;
		start1=NULL;
		start2=NULL;
		start3=NULL;
		InsEnd(&start1,1);
		InsEnd(&start1,2);
		InsEnd(&start1,3);
		InsEnd(&start1,4);
		InsEnd(&start1,5);
        InsEnd(&start2,6);
		InsEnd(&start2,7);
	    InsEnd(&start2,8);
		InsEnd(&start2,9);
		InsBeg(&start2,0);
		DelAft(&start2,8);
		DelSpecific(&start1,10);
		DelBeg(&start2);
		InsAt(&start1,2,111);
		DelEnd(&start1);
		Traverse(start1);
		printf("\n");
	    Traverse(start2);
	    start3=ConcatenationLL(start1,start2);
	    printf("\nConcatenation : \n");
	    Traverse(start3);
	    
}
	
