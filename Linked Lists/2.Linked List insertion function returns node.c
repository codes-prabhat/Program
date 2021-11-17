#include <stdio.h>
#include <stdlib.h>
struct node
{
	char info;
	struct node *next;
};
struct node *start;
struct node *GetNode(){
	struct node *P;
	P=(struct node *) malloc(sizeof(struct node));
	return P;
}
struct node *InsBeg(char x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=start;
	start=p;
	return p;
}
struct node *InsEnd(char x){
	struct node *p,*temp;
	p=GetNode();
	temp=start;
	if(temp==NULL){
		p=InsBeg(x);
	}
	else{
	while(temp->next!=NULL){
		temp=temp->next;
	}
	p->info=x;
	p->next=NULL;
	temp->next=p;
}
	return p;

}
struct node *InsAft(struct node *p,char x){
	struct node *q;
	if(p!=NULL){
		q=GetNode();
		q->info=x;
		q->next=p->next;
		p->next=q;
	}
	else{
		printf("Void Insertion");
	}
	return q;
}
void Traverse(){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%c\t",p->info);
		p=p->next;
	}
}
int main(void){
	struct node *q;
	q=InsEnd('I');
	InsAft(q,'P');
	InsBeg('V');
	Traverse();
	return 0;
}
	

