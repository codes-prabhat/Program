#include <stdio.h>
void Merge(int arr1[],int l1,int arr2[]){
	   int k=0,i=0;
		while(i<l1){
			if(arr1[i]==-1)
				arr1[i]=arr2[k++];
			i++;
		}
	}
int main(void){
	int arr1[]={-1,2,-1,4,-1,5,-1};
	int arr2[]={0,3,4,6};
	int l1=sizeof(arr1)/sizeof(arr1[0]);
	Merge(arr1,l1,arr2);
	for(int i=0;i<l1;i++)
		printf("%d ",arr1[i]);
    return 0;
}
