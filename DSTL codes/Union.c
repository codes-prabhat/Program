#include <stdio.h>
#define SIZE 100
/***********************************Union of set***********************/
int *UnionOfSet(int set1[],int set2[],int size1,int size2){
	static int UnionSet[2*SIZE];
	int i=0,j=0,k=0;
	while(i<size1&&j<size2){
		if(set1[i]<set2[j]){
			UnionSet[k++]=set1[i++];

		}
		else if(set2[j]<set1[i]){
				UnionSet[k++]=set2[j++];
		}
        else{
            UnionSet[k++]=set2[j++];
            i++;
        }
	}
	while(i<size1){
        UnionSet[k++]=set1[i++];
	}
	while(j<size2){
        UnionSet[k++]=set2[j++];
	}
        return UnionSet;
}
/*********Printing Sets************************************************/
void PrintSets(int *set){
	printf("{");
	for(int i=0;set[i]!='\0';){
		printf("%d",set[i]);
		i++;
		if(set[i]!='\0')
			printf(",");
		else
			break;
  }
  printf("}");
}
/************************Main function*********************************/
int main(void){
	int set1[SIZE];
	int set2[SIZE];
	int size1,size2;
	printf("Enter Size of set 1\n");
	scanf("%d",&size1);
	printf("Enter the elements of set 1\n");
	for(int i=0;i<size1;i++)
		scanf("%d",&set1[i]);
	printf("Enter Size of set 2\n");
	scanf("%d",&size2);
	printf("Enter the elements of set 2\n");
	for(int i=0;i<size2;i++)
		scanf("%d",&set2[i]);
    printf("UNION : ");
	PrintSets(UnionOfSet(set1,set2,size1,size2));
}
