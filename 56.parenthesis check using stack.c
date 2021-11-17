/*Program to check the validity of Parenthesized Arithmetic Expression using Stack
 *Program to check the validity of Bracketed Arithmetic Expression using Stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
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
		printf("Invalid parenthesis");
		exit(1);
	}
	x=s.arr[s.top];
	return x;
}
int main(void){
	char c[SIZE];
	initialize();
	fgets(c,SIZE,stdin);
	    for(int i=0;i<strlen(c);i++){
		if(c[i]=='('||c[i]=='{'||c[i]=='[')
		push(c[i]);
		else if((c[i]==')'||c[i]==']'||c[i]=='}')){
			if((c[i]==')'&&stacktop()=='(')||(c[i]==']'&&stacktop()=='[')||(c[i]=='}'&&stacktop()=='{'))
				pop();
		else{
		printf("Invalid Close the '%c' before '%c'",stacktop(),c[i]);
		exit(1);
		}
	}
}
	if(s.top==-1)
	printf("BALANCED PARENTHESIS");
	else
	printf("UNBALANCED PARETHESIS");
	return 0;
}
		
		
		
