#include <stdio.h>
/*swap function*/
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
/*partition function*/
int Partition(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start<end){
		while(arr[start]<=pivot)
			start++;
		while(arr[end]>pivot)
			end--;
		if(start<end)
			swap(&arr[start],&arr[end]);
	}
	swap(&arr[lb],&arr[end]);
	return end;
}
/*quick sort function*/
void QuickSort(int arr[],int lb,int ub){
	int pi;//location of pivot
	if(lb<ub){
		pi=Partition(arr,lb,ub);
		QuickSort(arr,lb,pi-1);
		QuickSort(arr,pi+1,ub);
	}
}
/*driver code*/
/*int main(void){
	int arr[]={18,13,12,15,19,10,4,0,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,len-1);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}*/
