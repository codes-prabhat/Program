/**DSTL LAB set union,intersection,difference,symmetric difference,Cartesian Product*****/
#include <stdio.h>
#define SIZE 100
/***********************************Union of set***********************/
int *UnionOfSet(int set1[],int set2[],int size1,int size2){
	static int UnionSet[2*SIZE];
	int i=0,j=0,k=0;
	//finding union set
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
	//adding Left out elements of set1
	while(i<size1){
        UnionSet[k++]=set1[i++];
	}
	//adding Left out elements of set2
	while(j<size2){
        UnionSet[k++]=set2[j++];
	}
        return UnionSet;
}
/***************Intersection of set***********************************/
int *IntersectionOfSet(int set1[],int set2[],int s1,int s2){
    static int InterSet[2*SIZE];
    int i=0,j=0,k=0;
    //finding intersection set
    while(i<s1&&j<s2){
        if(set1[i]==set2[j]){
            InterSet[k++]=set1[i++];
            j++;
        }
        else{
            if(set1[i]<set2[j])
                i++;
            else
                j++;
        }
    }
  return InterSet;
}
/***********Difference of two set**************************************/
int *DifferenceOfSet(int set1[],int set2[],int s1,int s2){
	static int DiffSet[2*SIZE];
    int i=0,j=0,k=0;
    //finding intersection set
    while(i<s1&&j<s2){
        if(set1[i]<set2[j]){
            DiffSet[k++]=set1[i++];
        }
        else{
            if(set1[i]>set2[j]){
                j++;
			}
            else{
                i++;
                j++;
			}
        }
	}
        while(i<s1){
			DiffSet[k++]=set1[i++];
		}
	return DiffSet; 
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
/*****************Size of set******************************************/
int SizeSet(int *set){
	int i=0;
	while(set[i]!='\0'){
		i++;
	}
	return i;
}		
/*****************Symmetric Difference*********************************/
int *SymmetricDifference(int set1[],int set2[],int s1,int s2){
	int *un,*in,*diff;
	un=UnionOfSet(set1,set2,s1,s2);//finding union
	in=IntersectionOfSet(set1,set2,s1,s2);//finding intersection
	s1=SizeSet(un);
	s2=SizeSet(in);
	diff=DifferenceOfSet(un,in,s1,s2);//finding difference of un and in
	return diff;
}
/***********************Cartesian Product******************************/
void CartesianProduct(int set1[],int set2[],int s1,int s2){
	int i,j,f=s1*s2;
	printf("{");
	for(i=0;i<s1;i++){
		for(j=0;j<s2;j++){
			f--;
			printf("(%d,%d)",set1[i],set2[j]);
			if(f!=0)
				printf(",");
		}
	}
	printf("}");
}	
/************************Main function*********************************/
int main(void){
	int set1[SIZE];
	int set2[SIZE];
	int size1,size2;
    //Set 1
	printf("Enter Size of set 1\n");
	scanf("%d",&size1);
	printf("Enter the elements of set 1\n");
	for(int i=0;i<size1;i++)
		scanf("%d",&set1[i]);
    //set 2
	printf("Enter Size of set 2\n");
	scanf("%d",&size2);
	printf("Enter the elements of set 2\n");
	for(int i=0;i<size2;i++)
		scanf("%d",&set2[i]);
    printf("********Results************\n");
    //calling union function
    printf("UNION : ");
	PrintSets(UnionOfSet(set1,set2,size1,size2));
	//calling intersection function
	printf("\nINTERSECTION : ");
	PrintSets(IntersectionOfSet(set1,set2,size1,size2));
	//calling difference function
	printf("\nDIFFERENCE : ");
	PrintSets(DifferenceOfSet(set1,set2,size1,size2));
	//Symmetric Difference
	printf("\nSYMMETRIC DIFFERENCE : ");
	PrintSets(SymmetricDifference(set1,set2,size1,size2));
	//Cartesian Product
	printf("\nCARTESIAN PRODUCT : ");
	CartesianProduct(set1,set2,size1,size2);
	return 0;
}
/***************************End of code********************************/
