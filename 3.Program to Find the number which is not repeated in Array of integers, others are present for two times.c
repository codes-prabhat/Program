#include<stdio.h>
int count(int a[],int n){
	int i,j,f=0;
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n;j++){
			if(a[i]==a[j]){
				f=f+1;
			}
		}
		if(f==1)
		printf("%d ",a[i]);
	}
 printf("\nTime Complexity of finding above answer is O(N^2)");
}
main(){
	int a[20],i,n;
	printf("Enter size of array :");
	scanf("%d",&n);
	printf("Enter Elements of array :");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	count(a,n);
	
}
/*int count(int a[],int n){
	int r=0,i;
	for(i=0;i<n;i++){
		r=r^a[i];
	}
	printf("%d",r);
	printf("\nTime Complexity of finding above answer is O(N)");
}*/
