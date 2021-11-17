#include <stdio.h>
struct Time{
	int hr;
	int min;
	int sec;
};
int main(void){
	struct Time t1,t2,sum;
    printf("Enter two times in format Hr,min and sec\n");
    scanf("%d%d%d%d%d%d",&t1.hr,&t1.min,&t1.sec,&t2.hr,&t2.min,&t2.sec);
	sum.sec=t1.sec+t2.sec;
	sum.min=t1.min+t2.min+(sum.sec/60);
	sum.hr=t1.hr+t2.hr+(sum.min/60);
    sum.min=sum.min%60;
    sum.sec=sum.sec%60;
  printf("%d:%d:%d",sum.hr,sum.min,sum.sec);
  return 0;
}
