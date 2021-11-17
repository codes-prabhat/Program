#include <stdio.h>
void CountingSort(int a[],int n,int k,int pass){
	int b[n];
	int c[k];
	int i;
	/**********initializing the counting array********/
	for(i=0;i<=k;i++){
		c[i]=0;
	}
	/****counting the elements in array********/
	for(i=0;i<n;i++){
		c[(a[i]/pass)%10]++;
	}
	/*********adding the previous count in next******/
	for(i=1;i<=k;i++){
		c[i]=c[i-1]+c[i];
	}
	/***start of sorting***/
	for(i=n-1;i>=0;i--){
		b[--c[(a[i]/pass)%10]]=a[i];
	}
	/***copying the array to previous array***/
	for(i=0;i<n;i++){
		a[i]=b[i];
	}	
}
void RadixSort(int a[],int n,int d){
	int k=9,pass=1;
	for(int i=0;i<d;i++){
		CountingSort(a,n,k,pass);
		pass=10*pass;
	}
}
int main(void){
	int arr[]={3719,1531,5503,1256,9447,8790,3456};
	int n=sizeof(arr)/sizeof(arr[0]);
	RadixSort(arr,n,4);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
