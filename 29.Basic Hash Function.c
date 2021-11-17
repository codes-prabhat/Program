#include <math.h>
#include <stdio.h>
/*********Prime number nearest to the given digit*********/
int NearestPrime(int n)
{
	int i,j,c;
	for(i=n;i>=1;i--)
	{
		c=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				c++;
			}
		}
		if(c==0)
		{
			return i;
			break;
		}
	}
	return 0;
}
/*****************Finding of Length******************/
int LengthOfKey(long long n)
{   long long t;
	int c=0;
	t=n;
	while(t!=0)
	{
		t=t/10;
		c++;
	}
	return c;
}
/********************Division Hash******************/
int DivisionHash(int key,int TS)
{
	int p,h;
	p=NearestPrime(TS);
	h=key%p;
	return h;
}
/****************************FoldingHash***********/
int FoldingHash(int key,int TS)
{
	int n,h,sum=0,r;
	n=key;
	while(n!=0)
	{
		r=n%TS;
		sum=sum+r;
		n=n/TS;
	}
	h=sum%TS;
	return h;
}
/*************************Midquare*****************/
int MidSquareHash(long int key,int TS)
{   long int n;
	int l,h,x;
	n=key*key;
	l=LengthOfKey(n);
    	x=ceil((l-(LengthOfKey(TS)-1))/2);
    	n=n/pow(10,x);
    	h=n%TS;	
	return h;
}
/******************Main***************************/
int main(void)
{   
	int n;
	n=74767880;
	printf("*************%d****************\n",n);
	printf("Division Method : %d\n",DivisionHash(n,1000));
	printf("Folding Method  : %d\n",FoldingHash(n,1000));
	printf("Midsquare Method: %d\n\n",MidSquareHash(n,1000));
	
	n=9648792;
	printf("*************%d****************\n",n);
    	printf("Division Method : %d\n",DivisionHash(n,1000));
	printf("Folding Method  : %d\n",FoldingHash(n,1000));
	printf("Midsquare Method: %d\n\n",MidSquareHash(n,1000));
	
	n=18007690;
	printf("*************%d****************\n",n);
	printf("Division Method : %d\n",DivisionHash(n,1000));
	printf("Folding Method  : %d\n",FoldingHash(n,1000));
	printf("Midsquare Method: %d\n\n",MidSquareHash(n,1000));
	
	
	
}
	

