#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
struct library{
	int  a;
	char name[20];
	char title[20];
	int  flag;
};
int n=0;
struct library lib[size];
/**************Displaying library books*****************/
void display(){
printf("Books details:\n");
for(int j=0;j<n;j++){
printf("(%d). %d |%s |%s ",(j+1),lib[j].a,lib[j].name,lib[j].title);
if(lib[j].flag==1)
	printf("|Available\n");
else
	printf("|Unavailable\n");
}
}
/**************Adding library books******************/
void BookAdd(){
	printf("Accession number: ");
    scanf("%d",&lib[n].a);
	printf("Name of author: ");
	scanf(" %[^\n]%*c",lib[n].name);
	printf("Title of book: ");
	scanf(" %[^\n]%*c",lib[n].title);
	lib[n].flag=1;
	n=n+1;
}
/**************Searching books of author*************/
void AutSearch(char a[]){
	for(int i=0;i<n;i++){
		if(strcmp(a,lib[i].name)==0){
			printf("%s\n",lib[i].title);
		}
	}
}
/*****************searching how many books by a same title******************/
int BookSearch(char a[]){
	int c=0;
	for(int i=0;i<n;i++){
		if(strcmp(a,lib[i].title)==0){
			c=c+lib[i].flag;
		}
	}
	return c;
}
/******************issuing books***************/
void issue(){
	int k;
	printf("Enter accession no:");
	scanf("%d",&k);
	for(int i=0;i<n;i++){
		if(k==lib[i].a){
			lib[i].flag=0;
		}
	}
}
/*************Total books*****************/
int totalBooks(){
	int c=0;
	for(int i=0;i<n;i++){
		c=c+lib[i].flag;
	}
	return c;
} 
/***************Main function**************/
int main(void)
{
	int ch;
	char c[20];
	while(1){
	printf("Enter your choice \n1 - Display book information\n2 - Add a new book\n3 - Display all the books in the library of a particular author\n4 - Display the number of books of a particular title\n5 - Display the total number of books in the library\n6 - Issue a book\n0 - Exit\n:-");
    scanf("%d",&ch);
    switch(ch){
		case 0:
		exit(1);
		case 1:
		display();
		break;
		case 2:
		BookAdd();
		break;
		case 3:
		printf("Enter Name of author: ");
		scanf(" %[^\n]%*c",c);
		AutSearch(c);
		break;
		case  4:
		printf("Enter Name of Book: ");
		scanf(" %[^\n]%*c",c);
		printf("%d\n",BookSearch(c));
		break;
		case 5:
		printf("%d\n",totalBooks());
		break;
		case 6:
		issue();
		break;
		default:
		printf("Invalid choice");
		break;
	}
}
return 0;
}
/*********************End of code*******************/		
		
