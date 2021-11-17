#include <stdio.h>
/**Just normal insertion sort********************/
void SortinK(int arr[],int len){
	int i,j,key,count;
	for(i=1;i<len;i++){
		key=arr[i];
		j=i-1;
		count=0;//maximum inner loop will run 3 times just a check not needed though
		while(j>=0&&arr[j]>key&&count<=3){
			count++;
			arr[j+1]=arr[j];
			j--;
			}
		arr[j+1]=key;
	}
}
int main(void){
	int arr[]={6, 5, 3, 2, 8, 10, 9};
	int len=sizeof(arr)/sizeof(arr[0]);
	SortinK(arr,len);//insertion sort
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);
	return 0;
}
