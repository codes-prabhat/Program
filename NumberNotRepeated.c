#include <stdio.h>
#include <stdlib.h>
void RepeatedOrNot(int arr1[],int arr2[],int n1,int n2){
	int c[20];
	/*******Intializzation of count array**********/
	for(int i=0;i<=19;i++){
		c[i]=0;
	}
	/***Increasing for arr1 and decreasing count for arr2****/
	for(int i=0;i<n1;i++){
		c[arr1[i]]=c[arr1[i]]+1;
	}
	for(int i=0;i<n2;i++){
		c[arr2[i]]=c[arr2[i]]-1;
	}
	/*****Checking count array*********/
	for(int i=0;i<=19;i++){
		if(c[i]!=0){
		printf("%d",i);
		exit(1);
	    }
	}
	printf("Every Element is repeated");
}
int main(void){
	int arr1[]={1,2,3,5,6,7};
	int arr2[]={1,2,3,5,6,7,19};
	int n1,n2;
	n1=sizeof(arr1)/sizeof(arr1[0]);
	n2=sizeof(arr2)/sizeof(arr2[0]);
	RepeatedOrNot(arr1,arr2,n1,n2);
	return 0;
}
  

