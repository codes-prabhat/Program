#include<stdio.h>
int main(){
	int n,i,r=0,m=0;
	char a[10000],b[10000];
	scanf("%d%s%s",&n,a,b);
	for(i=0;i<n;i++){
		if(b[i]=='r')
		r++;
		else
		m++;
	}
	for(i=0;i<n;i++){
		if(a[i]=='r' && r!=0)
		r--;
		else if(a[i]=='m' && m!=0)
		m--;
		else
		break;
	}
	printf("%d",m+r);
	return 0;
}

