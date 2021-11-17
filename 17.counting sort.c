#include <stdio.h>
void CountingSort(int a[],int n,int k){
	int b[n];
	int c[k+1];
	int i;
	/**********initializing the counting array********/
	for(i=0;i<=k;i++){
		c[i]=0;
	}
	/****counting the elements in array********/
	for(i=0;i<n;i++){
		c[a[i]]=c[a[i]]+1;
	}
	/*********adding the previous count in next******/
	for(i=1;i<=k;i++){
		c[i]=c[i-1]+c[i];
	}
	/***start of sorting***/
	for(i=n-1;i>=0;i--){
		c[a[i]]=c[a[i]]-1;
		b[c[a[i]]]=a[i];
	}
	/***copying the array to previous array***/
	for(i=0;i<n;i++){
		a[i]=b[i];
	}
}
int main(void){
	int arr[]={3,1,5,0,3,5,8,4,6,0,2,0,7,3,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	CountingSort(arr,n,9);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

