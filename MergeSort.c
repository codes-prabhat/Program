#include <stdio.h>
/*Merge Function*/
void Merge(int arr[],int lb,int mid,int ub){
	int temp[ub+1];
	int i=lb;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=ub){
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=ub)
		temp[k++]=arr[j++];
	k=0;
	for(int i=lb;i<=ub;i++)
		arr[i]=temp[k++];
}
/*Merge Sort Function*/
void MergeSort(int arr[],int lb,int up){
	if(lb<up){
		int mid=(lb+up)/2;
		MergeSort(arr,lb,mid);
		MergeSort(arr,mid+1,up);
		Merge(arr,lb,mid,up);
	}
}	
/*Driver Code*/
int main(void){
    int arr[]={15,12,113,4,25,10,9,14,18,0};
    int Len=sizeof(arr)/sizeof(int);
    int ub=Len-1;
    MergeSort(arr,0,ub);
    for(int i=0;i<Len;i++)
		printf("%d ",arr[i]);
	return 0;
}
