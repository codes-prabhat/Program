#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void SortedOrNot(int A[],int l,int B[]){//Bubble sort
	for(int i=1;i<l;i++){
		for(int j=0;j<l-i;j++){
			if(A[j]>A[j+1]){
				if(B[j]==0){
					printf("Sorting Not Possible");
					return;
					}
					swap(&A[j],&A[j+1]);
				}
			}
		}
		printf("Sorting Possible");
	}
int main(void){
	int A[]={2, 3, 1, 4, 5, 6};
	int B[]={0, 1, 1, 1, 1};
	int l=sizeof(A)/sizeof(A[0]);
	SortedOrNot(A,l,B);
	return 0;
}
