/*Program for Decimal to Octal Conversion*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct stack{
	int top;
	int arr[SIZE];
};
struct stack s;
void initialize(){
	s.top=-1;
}
isEmpty(){
	return (s.top==-1);
}
isFull(){
	return (s.top==SIZE-1);
}
int push(int x){
	if(isFull()){
	printf("Overflow Condition can't push '%d'",x);
	exit(1);
    }
	s.top++;
	s.arr[s.top]=x;
	return x;
}
int pop(){
	int x;
	if(isEmpty()){
		printf("Underflow Condition");
		exit(1);
	}
	x=s.arr[s.top];
	s.top--;
	return x;
}
void BinaryToOctal(int x){
	while(x!=0){
		push(x%8);
		x=x/8;
	}
	while(!isEmpty()){
		x=pop();
		printf("%d",x);
	}
}
void main(void){
	initialize();
	int x;
	scanf("%d",&x);
	BinaryToOctal(x);
}
