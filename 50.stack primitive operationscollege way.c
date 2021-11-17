//Program for Stack Primitive Operations
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 5
struct stack{
	int top;
	char arr[SIZE];
};
struct stack s;
void initialize(){
	s.top=-1;
}
int isEmpty(){
	return (s.top==-1);
}
int isFull(){
	return (s.top==SIZE-1);
}
char push(char x){
	if(isFull()){
	printf("Overflow Condition can't push '%c'",x);
	exit(1);
    }
	s.top++;
	s.arr[s.top]=x;
	return x;
}
char pop(){
	int x;
	if(isEmpty()){
		printf("Underflow Condition");
		exit(1);
	}
	x=s.arr[s.top];
	s.top--;
	return x;
}
char stacktop(){
	int x;
	if(isEmpty()){
		printf("Stack is Empty");
		exit(1);
	}
	x=s.arr[s.top];
	return x;
}
void display(){
	if(isEmpty()){
		printf("Stack is Empty");
		exit(1);
	}
	for(int i=s.top;i>=0;i--){
		printf("%c\n",s.arr[i]);
	}
}
int main(void){
	initialize();
	
    push('1');
	push('2');
	push('A');
	push('B');
    push('C');
	
	printf("'%c' is popped\n",pop());
	printf("'%c' is popped\n",pop());
    printf("'%c' is popped\n",pop());
    printf("'%c' is popped\n",pop());
    printf("Elements Left in stack\n");
    display();
    
    return 0;
}

































/*int main(void){
	initialize();
	int ch;
	char  c;
	do{
		
		printf("Enter  Choice 1.Push , 2.Pop ,3.StackTop , 4.display\n");
		scanf("%d",&ch);
		system("clear");
		switch(ch){
			case 1:
			printf("Enter character to be pushed : ");
			scanf("%s",&c);
			push(c);
			printf("%c pushed to stack",c);break;
			case 2:c=pop();
			printf("%c popped from stack",c);break;
			case 3:c=stacktop();
			printf("%c is at top of stack",c);break;
			case 4:display();break;
			default:
			if(ch==0)
			printf("Exited");
			else
			printf("Invalid Input\n");
		}
		sleep(1);
		if(ch!=0)
		printf("\t\t\tAgain\n");
		}while(ch!=0);//enter 0 to exit
	}*/
	
		
	
		
	
