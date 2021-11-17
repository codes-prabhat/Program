#include <stdio.h>
#include <stdlib.h>
/****Structure of Node**********/
struct node
{
	int Coeff;
	int Exp;
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
void InsBeg(struct node **start,int Coeff,int Exp){
	struct node *p;
	p=GetNode();
	p->Coeff=Coeff;
	p->Exp=Exp;
	p->next=*start;
	*start=p;
}
/********Inserts Elements in End of linked list**********/
void InsEnd(struct node **start,int Coeff,int Exp){
	struct node *p,*temp;
	p=GetNode();
	temp=*start;
	if(temp==NULL){
		InsBeg(start,Coeff,Exp);
	}
	else{
	while(temp->next!=NULL){
		temp=temp->next;
	}
	p->Coeff=Coeff;
	p->Exp=Exp;
	p->next=NULL;
	temp->next=p;
}
}
/********Polynomial Addition Function********************************/
struct node *PolyAdd(struct node *poly1,struct node *poly2){
	struct node *p,*q,*poly3=NULL;
	p=poly1;
	q=poly2;
	while(p!=NULL&&q!=NULL){
		if(p->Exp==q->Exp){
			InsEnd(&poly3,p->Coeff+q->Coeff,p->Exp);
			p=p->next;
			q=q->next;
		}
		else if(p->Exp>q->Exp){
			InsEnd(&poly3,p->Coeff,p->Exp);
		    p=p->next;
		}
		else{
			InsEnd(&poly3,q->Coeff,q->Exp);
			q=q->next;
		}
	}
	while(p!=NULL){
		InsEnd(&poly3,p->Coeff,p->Exp);
		p=p->next;
	}
	while(q!=NULL){
		InsEnd(&poly3,q->Coeff,q->Exp);
		q=q->next;
	}
	return poly3;
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%dX^%d ",p->Coeff,p->Exp);
		p=p->next;
		if(p!=NULL&&p->Coeff>0)
			printf("+ ");
	}
	printf("\n");
}
/*Driver code*/
int main(){
	struct node *poly1=NULL,*poly2=NULL,*poly3=NULL;
	InsEnd(&poly1,4,7);
	InsEnd(&poly1,-2,5);
	InsEnd(&poly1,1,4);
	InsEnd(&poly1,5,2);
	InsEnd(&poly1,2,0);
	
	Traverse(poly1);
	
	InsEnd(&poly2,8,6);
	InsEnd(&poly2,4,5);
	InsEnd(&poly2,-3,3);
	InsEnd(&poly2,2,2);
	InsEnd(&poly2,7,1);
	InsEnd(&poly2,-7,0);
	
	Traverse(poly2);
	
    poly3=PolyAdd(poly1,poly2);
    Traverse(poly3);
    
    return 0;
}
    
	
	
	
	
	
	
    
