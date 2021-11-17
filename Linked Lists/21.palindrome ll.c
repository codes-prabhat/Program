#include <stdio.h>
#include <stdlib.h>
/***Structure of Node**/
struct node
{
	int info;
	struct node *next;
};
/*Free Node**/
void FreeNode(struct node *p){
	free(p);
}
/**Get Node function creates node when called*/
struct node *GetNode(){
	struct node *P;
	P=(struct node *)malloc(sizeof(struct node));
	return P;
}
/**Inserts Elements in Beginning of LL*/
void InsBeg(struct node **start,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=*start;
	*start=p;
}
/**Inserts Elements in End of linked list**/
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
/**Prints all elements in Linked List****/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d  ",p->info);
		p=p->next;
	}
}
/**CCount of node****/
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
 /**Middle Elements********/
 struct node *MiddleElement(struct node * root){
	struct node *p,*q;
	q=root;
	if(q==NULL)
		return NULL;
	p=root->next;
	while(p!=NULL&&p->next!=NULL){
		p=p->next->next;
		q=q->next;
	}
	return q;
}
 /***Reverse*********/
 void ReverseLL(struct node **start){
	struct node *p,*c,*n;
	 p=NULL;
	 c=*start;
	 n=(*start)->next;
	 while(c!=NULL){
		 c->next=p;
		 p=c;
		 c=n;
		 if(n!=NULL)
		 n=n->next;
	 }
	 *start=p;
 }
/*Palindrome check***/
void palindromeLL(struct node *start){
	struct node *mid,*list2;
	mid=MiddleElement(start);
	list2=mid->next;
	mid->next=NULL;
	ReverseLL(&list2);
	while(start!=NULL&&list2!=NULL){
		if(start->info!=list2->info){
			printf("\nNot Palindrome");
			return;
		}
		list2=list2->next;
		start=start->next;
	}
		if(start==NULL&&list2==NULL)
			printf("\nPalindrome");
}
/*Main Method*/
int main(void){
		struct node *start1;
		start1=NULL;
		InsEnd(&start1,1);
		InsEnd(&start1,2);
		InsEnd(&start1,3);

		InsEnd(&start1,3);
		InsEnd(&start1,2);
		InsEnd(&start1,1);
		//InsEnd(&start1,1);

		Traverse(start1);
		printf("\n");
		/*ReverseLL(&start1);
		Traverse(start1);*/
		palindromeLL(start1);
		

	
}
