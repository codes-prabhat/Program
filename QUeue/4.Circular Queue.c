#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10
struct CQueue{
	int Buffer[SIZE];
	int Rear;
	int Front;
};
struct CQueue CQ;
void Initialize(){
	CQ.Rear=SIZE-1;
	CQ.Front=SIZE-1;
}
int Empty(){
	if(CQ.Rear==CQ.Front)
		return TRUE;
	else 
	    return FALSE;
}
void EnQueue(int x){
	if((CQ.Rear+1)%SIZE==CQ.Front){
		printf("Queue Overflow");
		exit(1);
	}
	CQ.Rear=(CQ.Rear+1)%SIZE;
    CQ.Buffer[CQ.Rear]=x;
}
int DeQueue(){
	int x;
	if(Empty()){
		printf("Queue Underflow");
		exit(1);
	}
	x=CQ.Buffer[CQ.Front];
	CQ.Front=(CQ.Front+1)%SIZE;
	return x;
}
void Display(){
	for(int i=(CQ.Front+1)%SIZE;;){
		if((CQ.Rear+1)%SIZE==i)
			break;
		printf("%d ",CQ.Buffer[i]);
		i=(i+1)%SIZE;
	}
}
int main(void){
	/*One space will always be wasted in circular queue so for size 10 only 9 elements can be inserted*/
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
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
	EnQueue(1);
	EnQueue(2);
	EnQueue(1);
	EnQueue(2);
	Display();
	return 0;
}
