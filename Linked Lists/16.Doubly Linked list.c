/**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *left;
	struct node *right;
};
struct node *GetNode(){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node*));
    return p;
}
/*************Insert Begginning****************/
struct node* InsBeg(struct node **dstart,int x){
	struct node *p;
	p=GetNode();
	p->info=x;
	if(*dstart!=NULL){
		(*dstart)->left=p;
	}
	p->right=*dstart;
	p->left=NULL;
	*dstart=p;
	return *dstart;
}
/**************Insert End*******************************/
struct node *InsEnd(struct node **dstart,int x){
	struct node *p,*q;
	p=GetNode();
	p->info=x;
	q=*dstart;
	while(q->right!=NULL){
		q=q->right;
	}
	q->right=p;
	p->left=q;
	p->right=NULL;

	return p;
}
/*********Ins Left*********************************/
struct node *InsLeft(struct node **dstart,struct node *p,int x){
	if(p==*dstart){
		return InsBeg(dstart,x);
	}
	struct node *q,*r;
	q=GetNode();
	q->info=x;
	r=p->left;
	r->right=q;
	p->left=q;
	q->left=r;
	q->right=p;
	return q;
}
/*********Insert Right*****************************/
struct node *InsRight(struct node **dstart,struct node *p,int x){
	struct node *q,*r;
	q=GetNode();
	q->info=x;
	if(p==NULL){
		return InsBeg(dstart,x);
	}
	if(p->right==NULL){
		return InsEnd(dstart,x);
	}
	if(p==*dstart){
	r=(*dstart)->right;	
    (*dstart)->right=q;
    r->left=q;
    q->left=*dstart;
    q->right=r;	
    return q;
	}
	r=p->right;
	r->left=q;
	p->right=q;
	q->right=r;
	q->left=p;
	return q;
}
/*******Delete beginning******************/
int DelBeg(struct node **dstart){
	if(*dstart==NULL){
		return 0;
	}
	struct node *p;
	int x;
	p=GetNode();
	p=*dstart;
	*dstart=(*dstart)->right;
	if(*dstart!=NULL)
		(*dstart)->left=NULL;
	x=p->info;
	free(p);
	return x;
}

/*******Delete End********************************/
int DelEnd(struct node **dstart){
	if(*dstart==NULL)
		return 0;
	if((*dstart)->right==NULL)
		return DelBeg(dstart);
	struct node *p,*q;
	int x;
	p=GetNode();
	p=*dstart;
	while(p->right!=NULL){

		p=p->right;
	}
	q=p->left;
	q->right=NULL;
	x=p->info;
	free(p);
	return x;
}
/********Delete Specific***************************/
int DelSpecific(struct node **dstart,struct node *p){
	if(p==NULL)
		return 0;	
	if(p->left==NULL)
		return DelBeg(&(*dstart));
	if(p->right==NULL)
		return DelEnd(&(*dstart));
	struct node *l,*r;
	int x;
	l=p->left;
	r=p->right;
	l->right=r;
	r->left=l;
	x=p->info;
	free(p);
	return x;
}
/**********Delete Right***************************/
int DelRight(struct node **dstart,struct node *p){
	if(p==NULL||p->right==NULL)
		return 0;
	struct node *r;
	r=p->right;
	return DelSpecific(&(*dstart),r);
}
/**********Delete Right***************************/
int DelLeft(struct node **dstart,struct node *p){
	if(p==NULL||p->left==NULL)
		return 0;
	struct node *r;
	r=p->left;
	return DelSpecific(&(*dstart),r);
}
/************Traversal ***************************/
void Traversal(struct node *dstart){
	while(dstart!=NULL){
		printf("%d ",dstart->info);
		dstart=dstart->right;
	}
}
/**********Driver function************************/
int main(void){
	struct node *dstart1=NULL;
	struct node *p=NULL;
	InsRight(&dstart1,p,8);
	InsBeg(&dstart1,12);
	p=InsBeg(&dstart1,11);
	p=InsBeg(&dstart1,10);
	InsLeft(&dstart1,p,9);
	p=InsRight(&dstart1,p,99);
	Traversal(dstart1);
	printf("\n");
	//DelBeg(&dstart1);
	//DelEnd(&dstart1);
	//DelSpecific(&dstart1,p);
	DelLeft(&dstart1,p);
	Traversal(dstart1);
    return 0;
}
/**********************************************************************/
