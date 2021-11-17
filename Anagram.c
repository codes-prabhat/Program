#include <stdio.h>
#include <stdlib.h>
void AnagramTest(char arr1[],char arr2[],int n){
	int b1,b2,c[26];
	/*******Intializzation of count array**********/
	for(int i=0;i<26;i++){
		c[i]=0;
	}
	/***Increasing for arr1 and decreasing count for arr2****/
	for(int i=0;i<n;i++){
		b1=arr1[i]-'A';
		c[b1]=c[b1]+1;
		b2=arr2[i]-'A';
		c[b2]=c[b2]-1;
	}
	/*****Checking count array*********/
	for(int i=0;i<26;i++){
		if(c[i]!=0){
		printf("Not Anagram");
		exit(1);
	    }
	}
	printf("It is Anagram");
}
int main(void){
	char arr1[]="ABCD";
	char arr2[]="CBDA";
	int n1,n2;
	n1=sizeof(arr1)/sizeof(arr1[0]);
	n2=sizeof(arr2)/sizeof(arr2[0]);
	if(n1!=n2){
		printf("Not Anagram");
		exit(1);
	}
	AnagramTest(arr1,arr2,n1);
	return 0;
}
  
