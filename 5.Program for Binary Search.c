#include<stdio.h>
int binarysearch(int a[],int n,int e){
	int l,h,mid;
	l=0;
	h=n;
	while(l<=h){
		mid=(l+h)/2;
		if(a[mid]==e){
			return mid;
			break;
		}
		else if(e<a[mid])
		h=mid-1;
		else
		l=mid+1;
	}
	return -1;
}					
int 	main(){
	int a[100],i,n,e,r;
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter elements of array : ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter Element to be searched : ");
	scanf("%d",&e);
	r=binarysearch(a,n,e);
	if(r==-1)
	printf("Element not found");
	else
	printf("Element found at index %d",r);
}
