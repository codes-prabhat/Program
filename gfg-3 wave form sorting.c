#include <stdio.h>
/*swap*/
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
/********Gives similar result but n2 complexity extra for sorting******/
/*void InsertionSort(int arr[],int len){
	int i,j,key;
	for(i=1;i<len;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void WaveSort(int arr[],int len){
	InsertionSort(arr,len);
	int i;
	for(i=0;i<len-1;i+=2){
		printf("%d ",arr[i+1]);
		printf("%d ",arr[i]);
	}
	if(len%2!=0)
		printf("%d",arr[i]);
}*/
/**********************************************************************/
void WaveSort(int arr[],int len){
	for(int i=0;i<len;i+=2){
		if(i>0&&arr[i-1]>arr[i])
			swap(&arr[i-1],&arr[i]);
		if(i<len-1&&arr[i]<arr[i+1])
			swap(&arr[i],&arr[i+1]);
		}
	}
int main(void){
	int arr[]={10, 5, 6, 3, 2, 20, 100,80};
	int len=sizeof(arr)/sizeof(arr[0]);
	WaveSort(arr,len);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}
