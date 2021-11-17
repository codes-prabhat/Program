/*Print N-bit binary numbers having more 1’s than 0’s for any prefix*/
#include <stdio.h>
#include <stdlib.h>
/*****Generating BInary NUmber*********/
void GenerateBinary(int n,int one,int zero, char *arr,int i){
	if(n==0){
		printf("%s\t",arr);
		return;
}
		arr[i]='1';
		GenerateBinary(n-1,one+1,zero,arr,i+1);
	if(one>zero){
		arr[i]='0';
		GenerateBinary(n-1,one,zero+1,arr,i+1);
	}
}
int main(void){
	int n,i=0;
	char *arr;
	printf("Enter Size of Binary Number : ");
	scanf("%d",&n);
	arr=(char*)malloc(n*sizeof(char));
	GenerateBinary(n,0,0,arr,i);
	free(arr);
	return 0;
}
