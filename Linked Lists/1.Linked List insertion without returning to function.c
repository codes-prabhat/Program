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
void InsBeg(char x){
	struct node *p;
	p=GetNode();
	p->info=x;
	p->next=start;
	start=p;
}
void InsEnd(char x){
	struct node *p,*temp;
	p=GetNode();
	temp=start;
	if(temp==NULL){
		InsBeg(x);
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
void InsAft(char c,char x){
	struct node *temp,*p;
	temp=start;
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
void Traverse(){
	struct node *p;
	p=start;
	while(p!=NULL){
		printf("%c\t",p->info);
		p=p->next;
	}
}
int main(void){
	InsBeg('P');
	InsEnd('V');
	InsEnd('I');
	InsEnd('R');
	InsAft('I','S');
	Traverse();
	return 0;
}
	

