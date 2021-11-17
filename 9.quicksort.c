#include <stdio.h>
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
int swap(int *a,int *b);
int main()
{
	int i,n;
	int a[] = {11, 9, 8, 0, 1, 5};  
    n = sizeof(a) / sizeof(a[0]); 
		
	quick_sort(a,0,n-1);
	printf("\nArray after sorting:");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	puts("");
	
	return 0;		
}
 
void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}
 
int partition(int a[],int l,int u)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	
	do
	{
		do
			i++;
			
		while(a[i]<v&&i<=u);
		
		do
			j--;
		while(v<a[j]);
		
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}while(i<j);
	swap(&a[l],&a[j]);
	
	return(j);
}
int swap(int *a,int *b){
	int t= *a;
	*a=*b;
	*b=t;
}

