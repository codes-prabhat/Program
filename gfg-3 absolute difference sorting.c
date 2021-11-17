#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void AbsoluteBubbleSort(int arr[],int len,int n){
	for(int i=0;i<len;i++){
		for(int j=0;j<len-i;j++){
			if(abs(n-arr[j])>abs(n-arr[j+1]))
				swap(&arr[j+1],&arr[j]);
			}
		}
	}
int main(void){
	int n=7;
	int arr[]={10, 5, 3, 9, 2};
	int len=sizeof(arr)/sizeof(arr[0]);
	AbsoluteBubbleSort(arr,len,n);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}
