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
/****************Ordered Insertion*************************************/
void InsOrd(struct node **start,int key){
	struct node *temp,*pre;
	pre=NULL;
	temp=*start;
	while(temp!=NULL && temp->info<=key){
		pre=temp;
		temp=temp->next;
	}
	if(pre!=NULL){
		InsAft(start,pre->info,key);
	}
	else{
		InsBeg(start,key);
	}
}
/**********Prints all elements in Linked List**************************/
void Traverse(struct node *start){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%d",p->info);
		if(p->next!=NULL)
			printf("->");
		p=p->next;
	}
}
/*********************Count nodes****************************/
int CountNodeLL(struct node *start){
	struct node *p;
	int count=0;
	p=GetNode();
	p=start;
	while(p!=NULL){
		count=count+1;
		p=p->next;
	}
	return count;
 }
 /*********sort ll*******************************************/
 void Sort(struct node ** start){
	 int c=CountNodeLL(*start);
	 struct node *p;
	 int temp;
	 for(int i=1;i<=c;i++){
		 p=*start;
		for(int j=1;j<=c-i;j++){
			if(p->info>p->next->info){
				temp=p->info;
				p->info=p->next->info;
				p->next->info=temp;
			}
			p=p->next;
		}
	} 
 }
 /*************Remove Duplicate*******************/
 void RemoveDuplicate(struct node **start){
	 struct node *p=*start;
	 while(p->next!=NULL){
		 if(p->info==p->next->info){
			 DelAft(&(*start),p->info);
			 continue;
		 }
		 p=p->next;
	 }
 }
 /**********Delete occurances of x********************/
 void DeleteX(struct node **start,int x){
	 struct node *p=*start;
	 while(p->next!=NULL){
		 if(p->info==x)
		 DelSpecific(&(*start),x);
		 continue;
		 p=p->next;
	 }
 }
		 
/*********Main Method*************/
int main(void){
		struct node *start1;
		start1=NULL;
		InsEnd(&start1,10);
		InsEnd(&start1,10);
		InsEnd(&start1,30);
		InsEnd(&start1,40);
		InsEnd(&start1,10);
		InsBeg(&start1,25);
		InsBeg(&start1,25);
		InsEnd(&start1,35);
		InsOrd(&start1,19);
		Traverse(start1);
		printf("\n%d\n",CountNodeLL(start1));
		Sort(&start1);
		Traverse(start1);
		RemoveDuplicate(&start1);
		printf("\n");
		Traverse(start1);
	    printf("\n");
	    DelSpecific(&start1,10);
		Traverse(start1);
}

