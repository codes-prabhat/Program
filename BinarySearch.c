#include <stdio.h>
void BinarySearch(int arr[],int len,int key){
	int flag=-1;
	int l=0,u=len-1,mid;
	while(l<=u){
		mid=(l+u)/2;
		if(arr[mid]==key){
			flag=mid;
			break;
		}
		else if(arr[mid]<key)
			l=mid+1;
		else
			u=mid-1;
	}
	if(flag==-1)
		printf("\tBinary Search Unsuccessful!\nElement Not Found");
	else
		printf("\tBinary Search Successful\nElement Found at '%d' position",flag+1);
}
int main(void){
	int key,arr[]={1,3,8,9,10,11,17,19,23,45,55,100,101};
	int l=sizeof(arr)/sizeof(arr[0]);
	printf("Enter Element To be searched : ");
	scanf("%d",&key);
	BinarySearch(arr,l,key);
}
	

