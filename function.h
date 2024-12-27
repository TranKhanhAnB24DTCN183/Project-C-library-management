#include"datatype.h"
//Nguyen mau ham
void displayMenu();
void printBook(Book book[],int length);
void addBook(Book books[], int *length);
void updateBook(Book book[], int length);
void deleteBook(Book book[], int *length);
void searchBookByName(Book book[], int length);
void toLowerCase(char str[]);
void sortBooksByPrice(Book books[], int length, int ascending);
void saveBooksToFile(Book book[], int length);
void loadBooksFromFile(Book books[], int *length);
