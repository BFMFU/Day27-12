#include <stdio.h>
#include<string.h>
#include "functions.h"
//logic ham
void printMenu(){
	printf("\n***************Quan Ly Thu Vien***************\n");
	printf("\n=====================MENU=====================\t\n");
	printf("1. Nhap so luong va thong tin sach.\n");
	printf("2. In ra thong tin sach.\n");
	printf("3. Them sach vao vi tri chi dinh.\n");
	printf("4. Xoa sach theo ma sach.\n");
	printf("5. Cap nhat thong tin theo ma sach.\n");
	printf("6. Sap xep sach theo gia tien.\n");
	printf("7. Tim kiem theo id sach.\n");
	printf("8. Quan ly thong tin muon sach.\n");
	printf("9. Them thong tin nguoi muon sach.\n");
	printf("10. Chinh thong tin nguoi muon.\n");
	printf("11. Xoa thong tin nguoi muon sach.\n");
	printf("12. Thoat chuong trinh.\n");
	printf("===============================================\n");
	printf("Nhap lua chon cua ban: ");
}
void inputBooks(Book book[], int *n ){
	printf("Nhap so luong sach muon them: ");
	scanf("%d", n);
	getchar();
	for(int i=0; i<*n;i++){
		book[i].id=i+1;
		printf("Moi ban nhap vao ten sach: ");
		fgets(book[i].title, 20, stdin);
		book[i].title[strcspn(book[i].title, "\n")] = '\0';
		printf("Moi ban nhap vao ten tac gia: ");
		fgets(book[i].author, 20, stdin);
		book[i].author[strcspn(book[i].author, "\n")] = '\0';
		printf("Moi ban nhap vao gia tien: ");
		scanf("%d", &book[i].price);
		getchar();
		printf("Moi ban nhap vao the loai: ");
		fgets(book[i].category, 20, stdin);
		book[i].category[strcspn(book[i].category, "\n")] = '\0';
	}
	printf("Them sach thanh cong.");
	saveListToFile(book, n);
}
void printBook(Book book[], int n){
	if(n<1){
		printf("Khong co sach trong thu vien hien tai.");
		return;
	}
	int i;
    printf("\nDanh sach sach trong thu vien:\n");
    printf("%-10s %-30s %-20s %-10s %-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
    printf("-------------------------------------------------------------------------------\n");
    for (i=0;i<n;i++) {
        printf("%-10d %-30s %-20s %-10lld %-20s\n", 
               book[i].id, 
               book[i].title, 
               book[i].author, 
               book[i].price, 
               book[i].category);
    }
 
}
void saveListToFile(Book book[],int n){
	FILE *ptr=fopen("libraryData.dat","ab");
	if(ptr==NULL){
		printf("Khong mo duoc file");
		return ;
	}
	fwrite(book,sizeof(Book),n,ptr);
	printf("Luu file thanh cong.");
	fclose(ptr);
}
	

