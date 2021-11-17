#include <stdio.h>
/*swap function*/
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
/******************************************************************/
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
/*********************************************************************/
/*SortPrint function*/
void SortPrint(int arr[],int len){
	QuickSort(arr,0,len-1);
	int i=0;
	int j=len-1;
	while(i<j)
		printf("%d %d ",arr[j--],arr[i++]);
	if(len%2!=0)//when odd
		printf("%d",arr[i]);
}	
/*driver code*/			
int main(void){
	int arr[]={7,1,2,3,4,45,1,0,4,8,5,3};
	int len=sizeof(arr)/sizeof(arr[0]);
    SortPrint(arr,len);

}
