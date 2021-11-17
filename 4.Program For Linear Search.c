#include<stdio.h>
int linearsearch(int a[],int n){
	int i,e;
	printf("Enter element to be searched : ");
	scanf("%d",&e);
	for(i=0;i<n;i++){
		if(a[i]==e)
		return i;
	}
	return -1;
}
int main(){
	int a[100],n,i;
	printf("Enter Size of array : ");
	scanf("%d",&n);
	printf("Enter Elements of arrray : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(linearsearch(a,n)!=-1)
	printf("   Found at index %d",linearsearch(a,n));
	else
	printf("   Not Found ");
}

