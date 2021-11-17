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
void InsAft(struct node **start,int c,int x){
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
		printf("Void Deletion");
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
		printf("Void Deletion");
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
		printf("Void Deletion");
		return 0;
	}
	return 0;
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d  ",p->info);
		p=p->next;
	}
}
/**************Delete specific node**********************************/
int DelSpecific(struct node **start,int x){
	struct node *c,*p;
	int n;
	c=*start;
	if(c->info!=x){
	while(c->next!=NULL){
		p=c;
		c=c->next;
		if(c->info==x){
			break;
		}
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
/**************Merge Linked list************************************/
struct node *Merge(struct node *list1,struct node *list2){
	struct node *list3,*p,*q;
	p=list1;
	q=list2;
	list3=NULL;
	while(p!=NULL && q!=NULL){
		if(p->info<q->info){
			InsEnd(&list3,p->info);
			p=p->next;
		}
		else{
			InsEnd(&list3,q->info);
			q=q->next;
		}
	}
	while(p!=NULL){
		InsEnd(&list3,p->info);
		p=p->next;
	}
	while(q!=NULL){
		InsEnd(&list3,q->info);
		q=q->next;
	}
	return list3;
}
/**************************Union***************************************/
struct node *Union(struct node *list1,struct node *list2){
	struct node *list3,*p,*q;
	p=list1;
	q=list2;
	list3=NULL;
	while(p!=NULL && q!=NULL){
		if(p->info<q->info){
			InsEnd(&list3,p->info);
			p=p->next;
		}
		else{
			if(q->info<p->info){
				InsEnd(&list3,q->info);
				q=q->next;}
			else{
				InsEnd(&list3,q->info);
				p=p->next;
				q=q->next;
			}
		}
	}
	while(p!=NULL){
		InsEnd(&list3,p->info);
		p=p->next;
	}
	while(q!=NULL){
		InsEnd(&list3,q->info);
		q=q->next;
	}
	return list3;
}
/*********************Intersection*************************************/
struct node *Intersection(struct node *list1,struct node *list2){
	struct node *list3,*p,*q;
	p=list1;
	q=list2;
	list3=NULL;
	while(p!=NULL && q!=NULL){
		if(p->info==q->info){
			InsEnd(&list3,p->info);
			p=p->next;
			q=q->next;
		}
		else{
			if(q->info<p->info){
				q=q->next;}
			else{
				p=p->next;
			}
		}
	}
	return list3;
}
/*********************Difference A-B*************************************/
struct node *ADifferenceB(struct node *list1,struct node *list2){
	struct node *list3,*p,*q;
	p=list1;
	q=list2;
	list3=NULL;
	while(p!=NULL && q!=NULL){
		if(p->info<q->info){
			InsEnd(&list3,p->info);
			p=p->next;
		}
		else{
			if(q->info<p->info){
				q=q->next;}
			else{
				p=p->next;
				q=q->next;
			}
		}
	}
	while(p!=NULL){
		InsEnd(&list3,p->info);
		p=p->next;
	}
	return list3;
}
/*********************Difference B-A*************************************/
struct node *BDifferenceA(struct node *list1,struct node *list2){
	struct node *list3,*p,*q;
	p=list2;
	q=list1;
	list3=NULL;
	while(p!=NULL && q!=NULL){
		if(p->info<q->info){
			InsEnd(&list3,p->info);
			p=p->next;
		}
		else{
			if(q->info<p->info){
				q=q->next;}
			else{
				p=p->next;
				q=q->next;
			}
		}
	}
	while(p!=NULL){
		InsEnd(&list3,p->info);
		p=p->next;
	}
	return list3;
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
		InsBeg(&start2,0);
		Traverse(start1);
		printf("\n");
	    Traverse(start2);
	    start3=Merge(start1,start2);
	    printf("\nMerge : \n");Traverse(start3);
		start3=Union(start1,start2);
	    printf("\nUnion : \n");Traverse(start3);
	    start3=Intersection(start1,start2);
	    printf("\nIntersection : \n");Traverse(start3);
	    start3=ADifferenceB(start1,start2);
	    printf("\nDifference A-B : \n");Traverse(start3);
		start3=BDifferenceA(start1,start2);
	    printf("\nDifference B-A : \n");Traverse(start3);
}
	

