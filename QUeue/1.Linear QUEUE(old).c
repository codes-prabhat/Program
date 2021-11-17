#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct queue
{
	int item[10];
	int front;
	int rear;
};
struct queue Q;
void Initialize(){
	Q.rear=-1;
	Q.front=0;
}
int Empty(){
	if(Q.rear-Q.front+1==0)
		return TRUE;
	else 
	    return FALSE;
	}
void EnQueue(int x){
	Q.rear++;
	Q.item[Q.rear]=x;
}
int DeQueue(){
	if(Empty()){
		printf("\nEmpty Queue");
		exit(1);
	}
	int x;
	x=Q.item[Q.front];
	Q.front++;
	return x;
}
int main() {
 int x;
 Initialize();
 EnQueue(100);
 EnQueue(200);
 EnQueue(300);
 EnQueue(400);
 EnQueue(500);
 x=DeQueue();
 printf("%d ",x);
 
 x=DeQueue();
 printf("%d ",x);
 
 x=DeQueue();
 printf("%d ",x);
 
  x=DeQueue();
 printf("%d ",x);
 
 x=DeQueue();
 printf("%d ",x);
 
 x=DeQueue();
 printf("%d ",x);
 
 
 return 0;
}

