#include <stdio.h>
#define TRUE 1
#define FALSE 0
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
void BubbleSort(int arr[],int len){
	int swapcall;//see geeks for geeks bubble sort article
	//int count=0; 
	for(int i=1;i<len;i++){
		swapcall=FALSE;
		for(int j=0;j<len-i;j++){
			if(arr[j]>arr[j+1]){
				//count++;
				swapcall=TRUE;
				swap(&arr[j],&arr[j+1]);
				}
			}
			//code optimisation if inner loop didn't swap
			if(swapcall==FALSE){
				//printf("\n\t(%d)\n",count);
				break;
			
			}
		}
}
int main(void){
	int arr[]={1,2,4,5,2,18,10,19,11,15};
	int len=sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr,len);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}
