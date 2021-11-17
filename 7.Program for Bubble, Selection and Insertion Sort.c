#include<stdio.h>
int i,j;
void swap(int *x, int *y) 
{ 
    int t = *x; 
    *x= *y; 
    *y = t; 
}
void insertionsort(int a[],int n){
	int temp;
	for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void selectionsort(int a[],int n){
	int min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
		if(a[j]<a[min])
		min=j;
		swap(&a[min],&a[i]);
	}
}
void printarray(int a[],int n){
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
void bubblesort(int a[],int n){
	 for(i=0;i<n-1;i++){
		 for(j=0;j<n-1-i;j++)
		 if(a[j]>a[j+1])
		 swap(&a[j],&a[j+1]);
	 }
 }
int main(){
int a[100],n,ch;
printf("Enter size of array : ");
scanf("%d",&n);
printf("Enter elements of array : ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter \n1 for bubble sort\n2 for selection sort\n3 for insertion sort\nyour choice : ");
scanf("%d",&ch);
switch(ch){
	case 1:
	bubblesort(a,n);
	printarray(a,n);
	break;
	case 2:
	selectionsort(a,n);
	printarray(a,n);
	break;
	case 3:
	insertionsort(a,n);
	printarray(a,n);
	break;
	default:
	printf("Wrong input");
}
}
