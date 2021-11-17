#include<stdio.h>
int i,a[20];
int insertionSorted(int a[],int m){
	int e;
	printf("Enter element to be inserted : ");
	scanf("%d",&e);
	i=m-1;
	while(a[i]>e){
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=e;
	m++;
	for(i=0;i<m;i++)
	{
		printf("%d ",a[i]);
	}
	
}
main(){
	int m;
	printf("Enter size of array : ");
	scanf("%d",&m);
	printf("Enter array : ");
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
insertionSorted(a,m);
}
