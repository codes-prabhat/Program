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
/*******Prints all elements in LL in Recursively*********/
void Traverse(struct node *start){
if(start!=NULL){
	printf("%d\t",start->info);
	Traverse(start->next);
}
}
/**********************SWAP NODE Function******************************/
void SwapNode(struct node  **start,int x,int y){
	struct node *PointerX,*PreviousX,*PointerY,*PreviousY,*temp;
 /*searching for x*/	
	PointerX=*start;
	PreviousX=NULL;
	while(PointerX!=NULL && PointerX->info!=x){
		PreviousX=PointerX;
		PointerX=PointerX->next;
	}
  /*searching for y*/	
	PointerY=*start;
	PreviousY=NULL;
	while(PointerY!=NULL && PointerY->info!=y){
		PreviousY=PointerY;
		PointerY=PointerY->next;
	}
 //If x or Y doesn't exist's
	if(PointerX==NULL||PointerY==NULL){
		printf("\n");
		if(PointerX==NULL)
			printf("X doesn't exist\n");
		if(PointerY==NULL)
			printf("Y doesn't exist\n");
		printf("Void Swapping");
		return;
	}
	 /****If X and Y both are same*************************/
	if(x==y){
		return;
	}
	/*******If x is not Head and Y is not Head*************/
	if(PreviousX!=NULL&&PreviousY!=NULL){
		PreviousX->next=PointerY;
		PreviousY->next=PointerX;
    }
    /***********If X is head******************************/
     else if(PreviousX==NULL){
     *start=PointerY;
     PreviousY->next=PointerX;
     }
     /************If Y is Head***************************/
     else{
		 *start=PointerX;
		  PreviousX->next=PointerY;
	  }
  	temp=PointerY->next;
	PointerY->next=PointerX->next;
	PointerX->next=temp;
  }
/*************************Main Method(Driver code)*********************/
int main(void){
		struct node *start1;
		start1=NULL;
		InsEnd(&start1,10);
		InsEnd(&start1,20);
		InsEnd(&start1,30);
		InsEnd(&start1,40);
		InsEnd(&start1,70);
		InsOrd(&start1,25);
		InsOrd(&start1,1);
		InsOrd(&start1,35);
		InsOrd(&start1,19);
		InsOrd(&start1,5);
		Traverse(start1);
		SwapNode(&start1,11,1);
		printf("\n");
		Traverse(start1);
	    
}



