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
/*find the merge point in linked list***/
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
/*Main Method*/
int main(void){
		struct node *start1,*start2,*p,*q;
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
		
		//Creating merge point
		p=start2;
		while(p->next!=NULL)
			p=p->next;
		q=start1;
		while(q->info!=2)
			q=q->next;
		p->next=q;//30->2
		printf("\n");
		
		MergePoint(start1,start2);
	
}
