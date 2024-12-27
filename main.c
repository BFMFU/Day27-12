#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

int main(int argc, char *argv[]){
	int choice;
	int n=0;
	Book books[50];
	do{
	printMenu();
	scanf("%d",&choice);
	switch(choice){
		case 1:
			inputBooks(books, &n) ;
			break;
		case 2:
			printBook(books, n);
			break;
		case 12:
			printf("\n======Thoat chuong trinh======\n");
			printf("=========Hen gap lai==========");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.");
	}
	} while(choice!=12);
	return 0;
}
