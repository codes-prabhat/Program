#include <stdio.h>
/*swap function*/
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
/*selection sort*/
void SelectionSort(int arr[],int len){
	int min; 
	for(int i=0;i<len-1;i++){
		min=i;
		for(int j=i+1;j<len;j++){
			if(arr[j]<arr[min]){
				min=j;
				}
			}
		swap(&arr[i],&arr[min]);
		}
}
/*driver code*/
int main(void){
	int arr[]={0,2,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	SelectionSort(arr,len);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}

