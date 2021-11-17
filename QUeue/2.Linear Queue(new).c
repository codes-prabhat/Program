#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXQUEUE 10
struct Queue{
	int Buffer[MAXQUEUE];
	int Rear;
	int Front;
};
struct Queue Q;
void Initialize(){
	Q.Rear=-1;
	Q.Front=0;
}
int Empty(){
	if(Q.Rear-Q.Front+1==0)
		return TRUE;
	else 
	    return FALSE;
}
void EnQueue(int x){
	if(Q.Rear==MAXQUEUE-1){
		printf("Queue Overflow");
		exit(1);
	}
	Q.Rear=Q.Rear+1;
    Q.Buffer[Q.Rear]=x;
}
int DeQueue(){
	int x;
	if((Q.Rear-Q.Front+1)==0){
		printf("Queue Underflow");
		exit(1);
	}
	x=Q.Buffer[Q.Front];
	Q.Front=Q.Front+1;
	return x;
}
void Display(){
	for(int i=Q.Front;i<=Q.Rear;i++){
		printf("%d ",Q.Buffer[i]);
	}
}
int main(void){
	Initialize();
	EnQueue(1);
	EnQueue(2);
	EnQueue(1);
	EnQueue(2);
	EnQueue(1);
	EnQueue(2);
	EnQueue(1);
	EnQueue(2);
	EnQueue(1);
	EnQueue(2);
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	Display(Q);
	return 0;
}
