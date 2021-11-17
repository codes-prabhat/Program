#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0
struct Queue
{
	char item[MAXQUEUE];
	int REAR;
	int FRONT;
};
struct Queue CQ;
void Initialize(){
	CQ.REAR=MAXQUEUE-1;
	CQ.FRONT=MAXQUEUE-1;
}
void EnQueue(char x)
{
	if((CQ.REAR+1)%MAXQUEUE==CQ.FRONT){
	printf("Queue Overflow");
	exit(1);
	}
	else{
	CQ.REAR=(CQ.REAR+1)%MAXQUEUE;
	CQ.item[CQ.REAR]=x;
    }
}
int Empty(){
	if(CQ.FRONT==CQ.REAR)
	 return TRUE;
	else
	 return FALSE;
}
char DeQueue(){
	char x;
	if(Empty())
	{
		printf("Queue Underflow");
	    exit(1);
	}
    else{
		CQ.FRONT=(CQ.FRONT+1)%MAXQUEUE;
		x=CQ.item[CQ.FRONT];
		return x;
	}
}
void DisQueue(){
	if(!Empty()){
	for(int i=CQ.FRONT+1;i<=CQ.REAR;i++){
		printf("%c\n",CQ.item[i]);
	}
  }
}
int main(void)
{   /*char x;
	Initialize();
	EnQueue('A');
	EnQueue('B');
	EnQueue('C');
	EnQueue('D');
	x=DeQueue();
	printf("'%C' is removed from Queue\n",x);
	x=DeQueue();
	printf("'%C' is removed from Queue\n",x);
	x=DeQueue();
	printf("'%C' is removed from Queue\n",x);
	x=DeQueue();
	printf("'%C' is removed from Queue\n",x);
	x=DeQueue();
	printf("'%C' is removed from Queue\n",x);*/
	/****Menu Driven*****************/
	int choice;
	char item;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display all elements of the queue\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
 
                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf(" %c",&item);
                        EnQueue(item);
                        break;
                case 2:
                        item=DeQueue();
                        printf("\nDeleted element is  %c\n",item);
                        break;
                case 3:
                        DisQueue();
                        break;
                case 4:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }
 
	return 0;
}
