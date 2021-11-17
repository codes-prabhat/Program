#include <stdio.h>
void LinearSearch(int arr[],int l,int key){
	int flag=-1;
	for(int i=0;i<l;i++){
		if(arr[i]==key){
			flag=i;
			break;
		}
		else{
			continue;
		}
	}
	if(flag==-1)
		printf("\tLinear Search Unsuccessful!\nElement Not Found");
	else
		printf("\tLinear Search Successful\nElement Found at '%d' position",flag+1);
}
int main(void){
	int key,arr[]={1,3,6,0,2,9,4,6,8};
	int l=sizeof(arr)/sizeof(arr[0]);
	printf("Enter Element To be searched : ");
	scanf("%d",&key);
	LinearSearch(arr,l,key);
}
	
