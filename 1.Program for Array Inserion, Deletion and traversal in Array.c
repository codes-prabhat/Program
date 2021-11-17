#include<stdio.h>
int a[20],m,i,c[21];
int insertion(int a[],int m){
	//element to be inserted
	//position at which to be inserted(starting position 1 not 0)
	int e,p;
	printf("Enter element and position to be inserted : ");
	scanf("%d%d",&e,&p);	
	//shifting forward
	for(i=m+1;i>=p;i--){
		a[i]=a[i-1];
	}
	a[p-1]=e;
	for(i=0;i<m+1;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
int deletion(int a[],int m){
	int p;
	//element position to be deleted(starting position 1 not 0)
	printf("Enter element position too be deleted : ");
	scanf("%d",&p);
	for(i=p-1;i<m-1;i++)
	{
		a[i]=a[i+1];
	}
	for(i=0;i<m-1;i++){
		printf("%d ",a[i]);
	}
}	
int traversal(int a[],int m){
	printf("Array : ");
	for(i=0;i<m;i++){
		printf("%d ",a[i]);
	}
}
	
main(){
  	int ch;
	//size of array max 20
	printf("Enter size of array : ");
	scanf("%d",&m);
	printf("Enter elements of array : ");
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	//press i for array element insertion
	//press d for array element deletion
	//press t for array traversal
	printf("Enter \n \"1\" for array element insertion\n \"2\" for array element deletion\n \"3\" for array traversal\nYour Choice : ");
	scanf("%d",&ch);
	switch(ch){
	case 1:
	insertion(a,m);
	break;
	case 2:
	deletion(a,m);
	break;
	case 3:
	traversal(a,m);
	break;
	default:
	printf("\nwrong input");
    }
    
}

	
	
