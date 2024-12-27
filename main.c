#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check;
int length=0;

int main(int argc, char *argv[]) {
	Book book[100];
	
	if (length == 0) {
        book[0] = (Book){1,"Dac Nhan Tam","Dale Carnegie",105000,"Tu giup ban than"};
        book[1] = (Book){2, "Mat Biec","Nguyen Nhat Anh",110000,"Tieu thuyet"};
        book[2] = (Book){3, "Nhat Ky Trong Tu","Ho Chi Minh",250000,"Tap tho chu Han"};
        book[3] = (Book){4, "Nhung Ngay Tho Au","Nguyen Hong",120000,"Tieu thuyet"};
        book[4] = (Book){5, "Bo Gia","Mario Puzo",200000, "Tieu thuyet"};
        length = 5;
    }
do{
		displayMenu();
		printf("Nhap lua chon cua ban :");
		scanf("%d",&check);
		switch(check){
			case 1:{
				printBook(book,length);
				break;
			}
			case 2:{
				addBook(book,&length);
				saveBooksToFile(book, length);
				break;
			}
			case 3:{
				updateBook(book,length);
				saveBooksToFile(book, length);
				break;
			}
			case 4:{
				deleteBook(book, &length);
				saveBooksToFile(book, length);
				break;
			}
			case 5:{
				searchBookByName(book,length);
				break;
			}
			case 6:{
                int sortOrder;
                printf("Chon kieu sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Nhap lua chon: ");
                scanf("%d", &sortOrder);

                sortBooksByPrice(book, length, sortOrder == 1);
                printf("Danh sach sau khi sap xep:\n");
                printBook(book, length);
                saveBooksToFile(book, length);
				break;
	     	}
			case 7:{
				printf("Thoat chuong trinh...!");
				break;
			}
			default:
				printf("Lua chon cua ban khong hop le.Yeu cau ban nhap lai !!!\n");
		}
}while(check!=7);
	return 0;
}
