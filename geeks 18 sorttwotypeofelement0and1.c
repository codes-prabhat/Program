#include <stdio.h>
#define swap(a,b) {(a)=(a)+(b); (b)=(a)-(b); (a)=(a)-(b);}//for swapping
/********Sort Fuction*********************/
void sort(int a[],int l){
	int start=0,end=l-1;
	while(start<end){
		if(a[start]==1){
			swap(a[start],a[end]);//swap envoked
			end--;
		}
		else
			start++;
	}
}
/*******Main Method**********************/
int main(void){
	int arr[]={1,0,0,0,1,1,1,0,0,0,0,0,0};
	int l=sizeof(arr)/sizeof(arr[0]);
	sort(arr,l);//calling sort function
	for(int i=0;i<l;i++)
		printf("%d ",arr[i]);
	return 0;
}
/*******End of code****************/
