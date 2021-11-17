#include <stdio.h>
/*swap function*/
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
/*Insertion sort function*/
void InsertionSort(int arr[],int len){
	int key,j; 
	for(int i=1;i<len;i++){
		key=arr[i];
		j=i-1;
		while(arr[j]>key&&j>=0){
		    arr[j+1]=arr[j];
			j--;
		}
        arr[j+1]=key;
		}
}
/*driver code*/
int main(void){
	int arr[]={18,0,2,2,3,4,5,6,7,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	InsertionSort(arr,len);
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}


