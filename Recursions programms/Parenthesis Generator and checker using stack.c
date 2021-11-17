#include<stdio.h>
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
void ParethesisCheck(char *c,int l)
{       initialize();
	    for(int i=0;i<l;i++){
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
}		
/*****Generate function**************/
void GenerateParenthesis(int o,int c,char *str,int i){
	if(o==0&&c==0){
		 printf("%s",str);
		 /*ParethesisCheck(str,i);*/
		 printf("\n");
		 return;
	 }
	 if(o!=0){
		 str[i]='(';
		 GenerateParenthesis(o-1,c,str,i+1);
	 }
	 if(c>o){
		 str[i]=')';
		 GenerateParenthesis(o,c-1,str,i+1);
	 }
 }		 
/*********Main Method****************/
int main(void){
	int n;char str[100];
	printf("********Generate parenthesis**********\nEnter : "); 
	scanf("%d",&n);
	GenerateParenthesis(n,n,str,0);
	return 0;
}
/**********	End of code*****************/

