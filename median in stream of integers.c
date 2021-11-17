#include <stdio.h>
#include <stdio.h>
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
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
void StreamMedian(int arr[],int l){
	int arrcp[l];
	float x=0.0;
	/********Copying array in new array**********************/
	for(int k=0;k<l;k++){
		arrcp[k]=arr[k];
	}	

	for(int i=0;i<l;i++){
	    /***Printing the numbers who's median is to be found***/
	    printf("Median of ");
		for(int k=0;k<i+1;k++){
			printf("%d",arr[k]);
			if(k!=i)
				printf(",");
		}
			printf(":=>");
	/******************************************************/
		SelectionSort(arrcp,i+1);
		x=(i+1)%2!=0?arrcp[i/2]:(arrcp[i/2]+arrcp[(i+1)/2])/2.0;
		printf("%0.1f\n",x);
	}
}			
int main(void){
	int arr[]={5,1,2,3,14,10,1};
	int l=sizeof(arr)/sizeof(arr[0]);
	StreamMedian(arr,l);
}
