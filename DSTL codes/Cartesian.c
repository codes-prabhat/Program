
#include <stdio.h>
#define SIZE 100
/***********************Cartesian Product******************************/
void CartesianProduct(int set1[],int set2[],int s1,int s2){
	int i,j,f=s1*s2;
	printf("{");
	for(i=0;i<s1;i++){
		for(j=0;j<s2;j++){
			f--;
			printf("(%d,%d)",set1[i],set2[j]);
			if(f!=0)
				printf(",");
		}
	}
	printf("}");
}
/************************Main function*********************************/
int main(void){
	int set1[SIZE];
	int set2[SIZE];
	int size1,size2;
	printf("Enter Size of set 1\n");
	scanf("%d",&size1);
	printf("Enter the elements of set 1\n");
	for(int i=0;i<size1;i++)
		scanf("%d",&set1[i]);
	printf("Enter Size of set 2\n");
	scanf("%d",&size2);
	printf("Enter the elements of set 2\n");
	for(int i=0;i<size2;i++)
		scanf("%d",&set2[i]);
	printf("\nCARTESIAN PRODUCT : ");
	CartesianProduct(set1,set2,size1,size2);
}
	

