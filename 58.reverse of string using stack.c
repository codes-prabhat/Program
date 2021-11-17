/*Program to Reverse the given String using Stack
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct stack{
	int top;
	char arr[SIZE];
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
void reverse(char str[]){
	for(int i=0;i<strlen(str);i++)
	push(str[i]);
	for(int i=0;i<strlen(str);i++)
	printf("%c",pop());
}
main(){
	char arr[SIZE];
	scanf("%[^\n]%*c",arr);
	reverse(arr);
}
