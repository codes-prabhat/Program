#include <stdio.h>
#include <stdlib.h>
/*Structure of Node***/
struct node
{
	int info;
	struct node *next;
};
/****Free Node***/
void FreeNode(struct node *p){
	free(p);
}
/***Get Node function creates node when called****/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/***Inserts Elements in Beginning of LL****/
void InsBeg(struct node **start,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=*start;
	*start=p;
}
/***Inserts Elements in End of linked list***/
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
/******Delete's Elements in Beginning of LL*****/
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
/********Delete After a node********/
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
/***Prints all elements in Linked List*********/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d  ",p->info);
		p=p->next;
	}
}
/*****CCount of node*********/
int CountNodeLL(struct node *start){
	struct node *p;
	int count=0;
	p=start;
	while(p!=NULL){
		count=count+1;
		p=p->next;
	}
	return count;
 }
/****Detect Loop in linked list************/
void DetectLoop(struct node * start){
	struct node *slow,*fast;
	slow=start;
	fast=start;
	int c=0;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		
		if(slow==fast){
			
			slow=slow->next;
			c+=1;
			while(slow!=fast){
				c+=1;
				slow=slow->next;
			}

			fast=start;
			while(fast!=slow){
				fast=fast->next;
				slow=slow->next;
				if(slow==fast){
					printf("Starting Point : %d \n",slow->info);
				}
			
			}
			printf("Loop Detected , Length is : %d",c);
			return;
		}
	}
	printf("No Loop");
}
/****find the merge point in linked list******/
void MergePoint(struct node *start1,struct node *start2){
	struct node *p,*q;
	p=start1;
	q=start2;
	int c1,c2,diff;
	c1=CountNodeLL(start1);
	c2=CountNodeLL(start2);
	if(c1<c2){
		diff=c2-c1;
		while((diff--)&&q!=NULL)
			q=q->next;
	}
	if(c1>c2){
		diff=c1-c2;
		while((diff--)&&p!=NULL)
			p=p->next;
	}
	while(p!=NULL&&q!=NULL){
		if(p==q){
			printf("Merge point is : %d",p->info);
			return;
		}
		p=p->next;
		q=q->next;
	}
	printf("No Merge Point");
}
/****Main Method****/
int main(void){
		struct node *start1,*start2,*p;
		start1=NULL;
		start2=NULL;
		InsEnd(&start1,1);
		InsEnd(&start1,2);
		InsEnd(&start1,3);
		InsEnd(&start1,4);
		InsEnd(&start1,5);
        InsEnd(&start1,6);
		InsEnd(&start1,7);

		InsEnd(&start2,10);
		InsEnd(&start2,20);
		InsEnd(&start2,30);

		Traverse(start1);
		printf("\n");
		Traverse(start2);
		
		
		
		//creating loop
		/*p=start1;
		while(p->next!=NULL)
			p=p->next;
		printf("\n%d\n",start1->next->next->info);
		p->next=start1->next->next;
		DetectLoop(start1);*/
		
		//Creating merge point
		/*p=start2;
		while(p->next!=NULL)
			p=p->next;
		p->next=start1->next->next->next;//30->4
		printf("\n");*/
		MergePoint(start1,start2);
	
}
