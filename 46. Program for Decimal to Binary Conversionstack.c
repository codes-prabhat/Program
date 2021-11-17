/*Program for Decimal to Binary Conversion*/
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
void BinaryToDecimal(int x){
	while(x!=0){
		push(x%2);
		x=x/2;
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
	BinaryToDecimal(x);
}
