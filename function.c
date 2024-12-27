#include<stdio.h>
#include <ctype.h>
#include"function.h"
//logic ham
void displayMenu() {
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|                ========== QUAN LY SACH ==========                 |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|                1.Hien thi ra danh sach cua sach                   |\n");
    printf("|                2.Them sach vao danh sach                          |\n");
    printf("|                3.Sua sach trong danh sach                         |\n");
    printf("|                4.Xoa sach trong danh sach                         |\n");
    printf("|                5.Tim kiem sach trong danh sach                    |\n");
    printf("|                6.Sap xep sach theo gia tien                       |\n");
    printf("|                7.Thoat...!                                        |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
}
void printBook(Book book[], int length) {
	int i;
    printf("\n============================ DANH SACH SACH ============================\n");
    printf("%-5s %-18s %-15s %-10s %-15s\n", "ID", "Ten sach", "Tac gia", "Gia tien", "The loai");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < length; i++) {
        printf("%-5d %-18s %-15s %-10.2f %-15s\n",
               book[i].id,
               book[i].name,
               book[i].author,
               book[i].price,
               book[i].genre);
    }
    printf("========================================================================\n");
}
void addBook(Book book[], int *length) {
    printf("\nNhap thong tin sach moi:\n");
    book[*length].id = *length + 1;  
    printf("Ten sach: ");
    fflush(stdin); 
    fgets(book[*length].name, 50, stdin);
    book[*length].name[strcspn(book[*length].name, "\n")] = '\0'; 

    printf("Ten tac gia: ");
    fflush(stdin);
    fgets(book[*length].author, 50, stdin);
    book[*length].author[strcspn(book[*length].author, "\n")] = '\0';

    printf("Gia tien: ");
    scanf("%f", &book[*length].price);

    printf("The loai: ");
    fflush(stdin);
    fgets(book[*length].genre, 30, stdin);
    book[*length].genre[strcspn(book[*length].genre, "\n")] = '\0';

    (*length)++;
    printf("\nDa them thanh cong!\n");
}
void updateBook(Book book[], int length) {
    int id, found = 0;
    int i;
    printf("Nhap ID sach can sua: ");
    scanf("%d", &id);

    for (i = 0; i < length; i++) {
        if (book[i].id == id) {
            found = 1;
            printf("Thong tin sach hien tai:\n");
            printf("ID: %d, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
                   book[i].id, book[i].name, book[i].author, book[i].price, book[i].genre);

            printf("\nNhap ten sach moi: ");
            getchar(); 
            fgets(book[i].name, sizeof(book[i].name), stdin);
            book[i].name[strcspn(book[i].name, "\n")] = '\0'; 
            
            printf("Nhap ten tac gia moi: ");
            fgets(book[i].author, sizeof(book[i].author), stdin);
            book[i].author[strcspn(book[i].author, "\n")] = '\0';

            printf("Nhap gia tien moi: ");
            scanf("%f", &book[i].price);

            printf("Nhap the loai moi: ");
            getchar(); 
            fgets(book[i].genre, sizeof(book[i].genre), stdin);
            book[i].genre[strcspn(book[i].genre, "\n")] = '\0'; 

            printf("ау cap nhat thong tin sach co ID %d\n", id);
            break;
        }
    }
    if (found==0) {
        printf("Khong tim thay sach co ID %d\n", id);
    }
}

void deleteBook(Book book[], int *length) {
    int id, found = 0;
    int i,j;
    char confirm;
    printf("Nhap ID sach muon xoa: ");
    scanf("%d", &id);

    for (i = 0; i < *length; i++) {
        if (book[i].id == id) {
            found = 1;
            printf("Ban co muon xoa sach nay khong?\n");
            printf("Nhap 'a' hoac 'A' de xoa , muon huy thi ban bam phim bat ki : ");
            getchar(); 
            scanf("%c", &confirm);
            if (confirm == 'a' || confirm == 'A'){
	            for (j = i; j < *length - 1; j++) {
	                book[j] = book[j + 1];
	            }
	            (*length)--; 
                printf("Da xoa sach co ID %d\n", id);
            }else{
            	printf("Huy xoa sach\n");
			}
            break;
        }
    }
	    if (found==0) {
	        printf("Khong tim thay sach co ID %d\n", id);
	    }
}

void searchBookByName(Book book[], int length) {
    char name[100];
    int found = 0;
    int i;

    printf("Nhap ten sach can tim: ");
    getchar(); 
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 
    toLowerCase(name);

    for ( i = 0; i < length; i++) {
        char bookName[100];
        strcpy(bookName, book[i].name);
        toLowerCase(bookName);

        if (strstr(bookName, name) != NULL) {
            found = 1;
            printf("\n============================ DANH SACH SACH ============================\n");
            printf("%-5s %-18s %-15s %-10s %-15s\n", "ID", "Ten sach", "Tac gia", "Gia tien", "The loai");
            printf("%-5d %-18s %-15s %-10.2f %-15s\n",
               book[i].id,
               book[i].name,
               book[i].author,
               book[i].price,
               book[i].genre);
        }
    }

    if (found==0) {
        printf("Khong tim thay sach '%s'\n", name);
    }
}
void toLowerCase(char str[]) {
	int i;
    for ( i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
void sortBooksByPrice(Book books[], int length, int ascending) {
	int i,j;
    for ( i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if ((ascending && books[j].price > books[j + 1].price) || 
                (!ascending && books[j].price < books[j + 1].price)) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
void saveBooksToFile(Book book[], int length) {
	FILE *ptr=fopen("books.dat","wb");
	
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(book,sizeof(Book),length,ptr);
	printf("Luu thong tin thanh cong\n");
	
	fclose(ptr);
}
void loadBooksFromFile(Book book[], int *length) {
	int i;
	FILE *ptr = fopen("books.dat", "rb");

	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	*length=fread(book,sizeof(Book),50,ptr);
	for( i=0;i<*length;i++){
	 printf("%-5d %-18s %-15s %-10.2f %-15s\n",
               book[i].id,
               book[i].name,
               book[i].author,
               book[i].price,
               book[i].genre);
    }	
	printf("Lay Du Lieu Thanh Cong\n");
	fclose(ptr);
}






