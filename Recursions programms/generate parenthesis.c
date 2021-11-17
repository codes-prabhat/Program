#include<stdio.h>
/*****Generate function**************/
void GenerateParenthesis(int o,int c,char str[],int i){
	if(o==0&&c==0){
		 printf("ok");
		 return;
	 }
	 str[i]='(';
	 GenerateParenthesis(o-1,c,str,i++);
	 if(o==0){
		 str[i]=')';
		 GenerateParenthesis(o,c-1,str,i++);
	 }
	 else if(o<c){
		 str[i]='(';
		 GenerateParenthesis(o-1,c,str,i++);
		 str[i]=')';
		 GenerateParenthesis(o,c-1,str,i++);
	 }
	 else{
		 str[i]='(';
		 GenerateParenthesis(o-1,c,str,i++);
	 }
 }
		 
		 
/*********Main Method****************/
int main(void){
	int n;char str[100];int i=0;
	printf("Enter the number");
	scanf("%d",&n);
	GenerateParenthesis(n,n,str,i);
	return 0;
}
