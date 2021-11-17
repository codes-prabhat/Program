#include <stdio.h>
/*void SortinN(int arr[],int l,int n){//just normal count sort
	int count[n+1],copy[l];
	for(int i=0;i<=n;i++)
		count[i]=0;
	for(int i=0;i<l;i++)
		++count[arr[i]];
	for(int i=0;i<=n-1;i++)
		count[i+1]=count[i+1]+count[i];
	for(int i=l-1;i>=0;i--)
		copy[--count[arr[i]]]=arr[i];
	for(int i=0;i<l;i++)
		arr[i]=copy[i];
	}*/
void SortinN(int arr[],int n){
	for(int i=0;i<=n-1;i++)
		arr[i]=i+1;
	}
int main(void){
	int arr[]={10, 7, 9, 2, 8, 3, 5, 4, 6, 1};
	int n=10;
	//int l=sizeof(arr)/sizeof(arr[0]);
	SortinN(arr,n);
	for(int i=0;i<=n-1;i++)
		printf("%d ",arr[i]);
	return 0;
}
