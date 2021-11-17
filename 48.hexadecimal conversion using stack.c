/*Program for Decimal to Hexadecimal Conversion*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
struct stack{
	int top;
	int arr[SIZE];
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
void BinaryToHexadecimal(int x){
	while(x!=0){
		push(x%16);
		x=x/16;
	}
	while(!isEmpty()){
		x=pop();
		if(x<10)
		printf("%d",x);
		else{
	    printf("%c",55+x);
	}
}
}
int main(void){
	initialize();
	int x;
	scanf("%d",&x);
	BinaryToHexadecimal(x);
	return 0;
}

