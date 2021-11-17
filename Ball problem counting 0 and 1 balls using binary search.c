#include <stdio.h>
int main(void) {
	//m is for 0 and n is for 1 
	int l=0,u,size,mid,m=0,n=0,arr[]={0,1,1,1,1,1};
	size=sizeof(arr)/sizeof(int);
	u=size-1;
	/***Case1: When all '1'****/
	if(arr[0]==1){
		n=size;
	}
	/***Case2: When all '0'***/
	else if(arr[size-1]==0){
	m=size;	
	}
	/*****case3:when both  '1' and '0'*****/
	else{
		while(l<=u){
		mid=(l+u)/2;
		/***when mid is 0***/
		if(arr[mid]==0){
			if(arr[mid+1]==1){
				m=mid+1;
				n=size-m;
				break;
			}
			else{
				l=mid+1;
			}
	    /***when mid is 1***/
		}
		else if(arr[mid]==1){
			if(arr[mid-1]==0){
				m=mid;
				n=size-m;
				break;
			}
			else{
				u=mid-1;
			}
		}
		}
	}
	printf("M is = %d \nN is = %d",m,n);
	return 0;
}
