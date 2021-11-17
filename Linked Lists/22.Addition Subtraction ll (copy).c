#include <stdio.h>
#include <stdlib.h>
/**Structure of Node**/
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
int CreatingNumber(struct node *start){
	int num=0;
	while(start!=NULL){
		num=(num*10)+(start->info);
		start=start->next;
			}
	return num;
}
/*****Creating LL****/
struct node *CreatingLL(int sum){
	struct node *res=NULL;
	while(sum!=0){
		InsBeg(&res,sum%10);
		sum=sum/10;
	}
	return res;
}
/*Main Method*/
int main(void){
		struct node *start1,*start2,*res;
		int num1,num2,r;
		start1=NULL;
		start2=NULL;
		InsEnd(&start1,1);
		InsEnd(&start1,2);
		InsEnd(&start1,7);
		InsEnd(&start2,1);
		InsEnd(&start2,2);
		InsEnd(&start2,4);

		Traverse(start1);
		printf("\n");
		Traverse(start2);
		num1=CreatingNumber(start1);
		num2=CreatingNumber(start2);
		r=num1+num2;
		//r=abs(num1-num2);
		res=CreatingLL(r);
		printf("\n");
		Traverse(res);
	}
