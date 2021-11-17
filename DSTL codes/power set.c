/**DSTL LAB power set*****/
#include <stdio.h>
#include <math.h>
#define SIZE 100 
int np;//number of pairs
/********Printing subsets*************/
void PrintSubset(int *set,int si){
	np--;
	printf("{");
	for(int i=0;i<si;){
		printf("%d",set[i]);
		i++;
		if(i<si)
			printf(",");
		else
			break;
  }
  printf("}");
  if(np>0){
	  printf(",");
} 
}
/**********Powerset*************/
void powerset(int arr[],int len,int i,int subset[],int si){
	if(i==len){
		PrintSubset(subset,si);
	return;
	}
	powerset(arr,len,i+1,subset,si);
	subset[si]=arr[i];
	powerset(arr,len,i+1,subset,si+1);
}
/*********Main**************/
int main(void){
	int set1[SIZE];
	int subset[SIZE];
	int size1;
  	printf("Enter Size of set\n"); 
	scanf("%d",&size1);
	np=pow(2,size1);
	printf("Enter the elements of set\n");
	for(int i=0;i<size1;i++)
		scanf("%d",&set1[i]);
	printf("{");
    powerset(set1,size1,0,subset,0);
    printf("}");
}
